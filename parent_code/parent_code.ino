#include <Wire.h> // Library for I2C communication
#include "RTClib.h"
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h> // include i/o class header
#include <SPI.h>
#include <SD.h>
#include "Constants.h"
#include "UV.h"
#include "Utils.h"
#include "ModbusSlave.h"
#include <Arduino.h>

#define SLAVE_ID 15
#define SERIAL_BAUDRATE 38400
#define SERIAL_PORT Serial2
#define RS485_CTRL_PIN 3

File myFile;
Constants constants;
Utils utils;
RTC_DS3231 rtc;

hd44780_I2Cexp lcd; // declare lcd object: auto locate & config display for hd44780 chip
bool buzzerStat = false;

const long defaultTimer = 60000; // Every 1 mins upload to SD card
long lastRun = millis();

int lastPressed = 0;
int displayCounter = 0;

const int lifeHours = 9000;
const int resetTimer = 5000;

const String FILE_NAME = "uv.txt";
const String FILE_NAME1 = "backup.txt";

const String FILE_NAME_1 = "uv1.txt";
const String FILE_NAME1_1 = "backup1.txt";

const int DEFAULT_CS = 53;

UV uvlightStat;
int defaultMsgStat = 0;
long buzzerMillis = millis();
long displayMillis = millis();

int au16data[60] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

uint8_t input_pins_size = 60;
Modbus slave(SERIAL_PORT, SLAVE_ID, RS485_CTRL_PIN);

int pass = 0;
int plengthForDisplay = 0;

void setup()
{
  Serial.begin(115200);
  Serial3.begin(500000);
  slave.cbVector[CB_READ_INPUT_REGISTERS] = readAnalogIn;
  SERIAL_PORT.begin(SERIAL_BAUDRATE);
  slave.begin(SERIAL_BAUDRATE);

  Wire.begin(5);
  Serial.println("Trying to setupup clock");
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  } else {
    Serial.println("RTC launched");
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  if (rtc.lostPower()) {
    Serial.println("RTC lost power");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.begin (20, 4); // 20 x 4 LCD module
  startingMsg();

  pinMode(constants.BUZZER_PIN, OUTPUT);

  pinMode(constants.UV_Light1_Input_PIN, INPUT);
  pinMode(constants.UV_Light1_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light2_Input_PIN, INPUT);
  pinMode(constants.UV_Light2_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light3_Input_PIN, INPUT);
  pinMode(constants.UV_Light3_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light4_Input_PIN, INPUT);
  pinMode(constants.UV_Light4_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light5_Input_PIN, INPUT);
  pinMode(constants.UV_Light5_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light6_Input_PIN, INPUT);
  pinMode(constants.UV_Light6_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light7_Input_PIN, INPUT);
  pinMode(constants.UV_Light7_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light8_Input_PIN, INPUT);
  pinMode(constants.UV_Light8_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light9_Input_PIN, INPUT);
  pinMode(constants.UV_Light9_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light10_Input_PIN, INPUT);
  pinMode(constants.UV_Light10_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light11_Input_PIN, INPUT);
  pinMode(constants.UV_Light11_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light12_Input_PIN, INPUT);
  pinMode(constants.UV_Light12_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light13_Input_PIN, INPUT);
  pinMode(constants.UV_Light13_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light14_Input_PIN, INPUT);
  pinMode(constants.UV_Light14_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light15_Input_PIN, INPUT);
  pinMode(constants.UV_Light15_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light16_Input_PIN, INPUT);
  pinMode(constants.UV_Light16_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light17_Input_PIN, INPUT);
  pinMode(constants.UV_Light17_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light18_Input_PIN, INPUT);
  pinMode(constants.UV_Light18_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light19_Input_PIN, INPUT);
  pinMode(constants.UV_Light19_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light20_Input_PIN, INPUT);
  pinMode(constants.UV_Light20_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light21_Input_PIN, INPUT);
  pinMode(constants.UV_Light21_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light22_Input_PIN, INPUT);
  pinMode(constants.UV_Light22_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light23_Input_PIN, INPUT);
  pinMode(constants.UV_Light23_Input_BUTTON, INPUT);

  pinMode(constants.UV_Light24_Input_PIN, INPUT);
  pinMode(constants.UV_Light24_Input_BUTTON, INPUT);

  Serial.print("Initializing SD card...");

  if (!SD.begin(DEFAULT_CS)) {
    Serial.println("Initialization failed!");
    sdCardFailure();
  }
  Serial.println("Initialization done.");

  if (SD.exists(FILE_NAME) || SD.exists(FILE_NAME_1)) {
    Serial.println(FILE_NAME + " exists.");
    Serial.println(FILE_NAME_1 + " exists.");
    readSDMsg();
  } else {
    if (SD.exists(FILE_NAME1) || SD.exists(FILE_NAME1_1)) {
      Serial.println(FILE_NAME1 + " exists.");
      Serial.println(FILE_NAME1_1 + " exists.");
      readSDMsg1();
    } else {
      Serial.println(FILE_NAME + " does not exist. Creating first time.");
      writeSDMsg();
    }
  }
 
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print('-');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
}

void startingMsg() {
  for (int j = 0; j <= 4; j++) {
    for (int i = 0; i <= 20; i++) {
      lcd.setCursor(i, j);
      lcd.print(" ");
    }
  }

  lcd.setCursor(6, 0);
  lcd.print("CLAIRCO");

  lcd.setCursor(5, 2);
  lcd.print("Clean Air");
  lcd.setCursor(3, 3);
  lcd.print("Guaranteed!!");
}

void defaultMsg(long timeRec) {
  if (millis() - displayMillis > 2000) {
    displayMillis = millis();
    if (! checker(timeRec)) {
      if (defaultMsgStat == 1) {
        return;
      }

      for (int j = 0; j <= 4; j++) {
        for (int i = 0; i <= 20; i++) {
          lcd.setCursor(i, j);
          lcd.print(" ");
        }
      }

      lcd.setCursor(6, 0);
      lcd.print("CLAIRCO");

      lcd.setCursor(5, 2);
      lcd.print("Clean Air");
      lcd.setCursor(3, 3);
      lcd.print("Guaranteed!!");
    }

    defaultMsgStat = 1;
  }
}

bool checker(long timeRec) {
  String outputForDisplay = uvlightStat.errorStatusToDisplay(timeRec);
  //Serial.print(F("outputForDisplay: "));
  //Serial.println(F(outputForDisplay));

  int lengthForDisplay = outputForDisplay.length();
  char buf[lengthForDisplay] = {};
  outputForDisplay.toCharArray(buf, lengthForDisplay);

  if (plengthForDisplay != lengthForDisplay) {
    pass = 0;
    plengthForDisplay = lengthForDisplay;
  }

  String value1 = "";
  String value2 = "";
  String value3 = "";
  String value4 = "";

  if (lengthForDisplay <= 20) {
    for (int i = 0; i < outputForDisplay.length(); i++) {
      if (buf[i] == '\0') {
        continue;
      }
      value1 = value1 + buf[i];
    }
  } else if (lengthForDisplay > 20 && lengthForDisplay <= 40) {
    for (int i = 0; i < 20; i++) {
      if (buf[i] == '\0') {
        break;
      }
      value1 = value1 + buf[i];
    }

    for (int i = 20; i < outputForDisplay.length(); i++) {
      if (buf[i] == '\0') {
        continue;
      }
      value2 = value2 + buf[i];
    }

  } else if (lengthForDisplay > 40 && lengthForDisplay <= 60) {
    for (int i = 0; i < 20; i++) {
      if (buf[i] == '\0') {
        break;
      }
      value1 = value1 + buf[i];
    }

    for (int i = 20; i < 40; i++) {
      if (buf[i] == '\0') {
        break;
      }
      value2 = value2 + buf[i];
    }

    for (int i = 40; i < outputForDisplay.length(); i++) {
      if (buf[i] == '\0') {
        continue;
      }
      value3 = value3 + buf[i];
    }

  } else if (lengthForDisplay > 60 && lengthForDisplay <= 80) {
    for (int i = 0; i < 20; i++) {
      if (buf[i] == '\0') {
        break;
      }
      value1 = value1 + buf[i];
    }

    for (int i = 20; i < 40; i++) {
      if (buf[i] == '\0') {
        break;
      }
      value2 = value2 + buf[i];
    }

    for (int i = 40; i < 60; i++) {
      if (buf[i] == '\0') {
        break;
      }
      value3 = value3 + buf[i];
    }

    for (int i = 60; i < outputForDisplay.length(); i++) {
      if (buf[i] == '\0') {
        break;
      }
      value4 = value4 + buf[i];
    }
  } else if (lengthForDisplay > 80 && lengthForDisplay <= 160) {

    if (pass == 0) {
      for (int i = 0; i < 20; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value1 = value1 + buf[i];
      }

      for (int i = 20; i < 40; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value2 = value2 + buf[i];
      }

      for (int i = 40; i < 60; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value3 = value3 + buf[i];
      }

      for (int i = 60; i < 80; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value4 = value4 + buf[i];
      }
      pass = 1;
    } else if (pass == 1) {
      for (int i = 80; i < 100; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value1 = value1 + buf[i];
      }

      for (int i = 100; i < 120; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value2 = value2 + buf[i];
      }

      for (int i = 120; i < 140; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value3 = value3 + buf[i];
      }

      for (int i = 140; i < 160; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value4 = value4 + buf[i];
      }
      pass = 0;
    }
  } else if (lengthForDisplay > 160) {

    if (pass == 0) {
      for (int i = 0; i < 20; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value1 = value1 + buf[i];
      }

      for (int i = 20; i < 40; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value2 = value2 + buf[i];
      }

      for (int i = 40; i < 60; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value3 = value3 + buf[i];
      }

      for (int i = 60; i < 80; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value4 = value4 + buf[i];
      }
      pass = 1;
    } else if (pass == 1) {
      for (int i = 80; i < 100; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value1 = value1 + buf[i];
      }

      for (int i = 100; i < 120; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value2 = value2 + buf[i];
      }

      for (int i = 120; i < 140; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value3 = value3 + buf[i];
      }

      for (int i = 140; i < 160; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value4 = value4 + buf[i];
      }
      pass = 2;
    } else if (pass == 2) {
      for (int i = 160; i < 174; i++) {
        if (buf[i] == '\0') {
          break;
        }
        value1 = value1 + buf[i];
      }
      pass = 0;
    }
  }

  //Serial.print("outputForDisplay");
  //Serial.println(outputForDisplay.length());
  if (outputForDisplay.length() > 5) {
    buzzerStat = true;
    //    Serial.print("value1 ");
    //    Serial.println(value1);
    //    Serial.print("|| value2 ");
    //    Serial.println(value2);
    //    Serial.print(" ||value3 ");
    //    Serial.println(value3);
    //    Serial.print(" || value4 ");
    //    Serial.println(value4);
    chkDisplay(value1, value2, value3, value4);
    return true;
  } else {
    buzzerStat = false;
  }
  return false;
}

// 1. Duration ran, 2 Duration left, 3 Current status
void updateLCD(long data, byte output) {
  defaultMsgStat = 2;
  lcd.clear();
  lcd.setCursor(0, 0);
  String line1 = "UV " + String(lastPressed) + " light status";
  lcd.print(line1);

  lcd.setCursor(0, 1); // 1 mins = 1 point / 60 points
  long hoursRan = data / long(60);
  long minutesRan = (data % 60) * ((defaultTimer / 1000) / 60);
  String line2 = "Ran: " + String(hoursRan) + "h :" + String(minutesRan) + "m";
  lcd.print(line2);

  lcd.setCursor(0, 2);
  String life = "Left: " + String(uvlightStat.defaultLightHours - hoursRan) + "hrs";
  lcd.print(life);

  lcd.setCursor(0, 3);
  String currentStatus = "Status is: ";
  if (output == '1') {
    currentStatus = currentStatus + "LIVE";
  } else if (output == '0') {
    currentStatus = currentStatus + "NOT LIVE";
  }
  lcd.print(currentStatus);
}

void resetPresed() {

  defaultMsgStat = 3;
  lcd.clear();
  lcd.setCursor(0, 0);
  String line1 = "Reset Pressed";
  lcd.print(line1);

  lcd.setCursor(0, 1);
  String life = "Unlocked";
  lcd.print(life);

  lcd.setCursor(0, 2);
  String life1 = "Select reset pin";
  lcd.print(life1);
}

void resetAndPinPressed(int pin) {

  defaultMsgStat = 4;
  lcd.clear();
  delay(500);
  lcd.setCursor(0, 0);
  String line1 = "Reset Pressed";
  lcd.print(line1);

  lcd.setCursor(0, 1);
  String line5 = "Pin Selected: " + String(pin);
  //Serial.println(line5);
  lcd.print(line5);

  lcd.setCursor(0, 2);
  String line2 = "Reset Successful!!";
  lcd.print(line2);
}

void chkDisplay(String value1, String value2, String value3, String value4) {

  defaultMsgStat = 4;
  lcd.clear();
  delay(500);

  lcd.setCursor(0, 0);
  lcd.print(value1);

  lcd.setCursor(0, 1);
  lcd.print(value2);

  lcd.setCursor(0, 2);
  lcd.print(value3);

  lcd.setCursor(0, 3);
  lcd.print(value4);
}

void writeSDMsg1() {

  if (SD.exists(FILE_NAME1)) {
    SD.remove(FILE_NAME1);
  }
  delay(500);

  myFile = SD.open(FILE_NAME1, FILE_WRITE);

  if (myFile) {
    myFile.seek(0);
    String output = uvlightStat.putStatusToSDCard();

    Serial.println("Writing default...");
    Serial.println(output);
    myFile.println(output);
    myFile.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening " + FILE_NAME1);
  }

  if (SD.exists(FILE_NAME1_1)) {
    SD.remove(FILE_NAME1_1);
  }
  delay(500);

  myFile = SD.open(FILE_NAME1_1, FILE_WRITE);

  if (myFile) {
    myFile.seek(0);
    String output = uvlightStat.putStatusToSDCard1();

    Serial.println("Writing default...");
    Serial.println(output);
    myFile.println(output);
    myFile.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening " + FILE_NAME1_1);
  }
}

void writeSDMsg() {

  if (SD.exists(FILE_NAME)) {
    SD.remove(FILE_NAME);
  }
  delay(500);

  myFile = SD.open(FILE_NAME, FILE_WRITE);

  if (myFile) {
    myFile.seek(0);
    String output = uvlightStat.putStatusToSDCard();

    Serial.print("Writing default...");
    myFile.println(output);
    myFile.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening " + FILE_NAME);
  }

  if (SD.exists(FILE_NAME_1)) {
    SD.remove(FILE_NAME_1);
  }
  delay(500);

  myFile = SD.open(FILE_NAME_1, FILE_WRITE);

  if (myFile) {
    myFile.seek(0);
    String output = uvlightStat.putStatusToSDCard1();

    Serial.print("Writing default...");
    myFile.println(output);
    myFile.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening " + FILE_NAME_1);
  }
}

void readSDMsg1() {
  if (SD.exists(FILE_NAME1)) {
    myFile = SD.open(FILE_NAME1);
    while (myFile.available())
    {
      String strBuffer = myFile.readStringUntil('\n');
      int ind = utils.getValue(strBuffer, '=', 0).toInt();
      long value = utils.getValue(strBuffer, '=', 1).toInt();
      Serial.print(ind);
      Serial.print("-");
      Serial.println(value);

      if (ind == 1) {
        uvlightStat.ledHoursRun1 = value;
      }
      else if (ind == 2) {
        uvlightStat.ledHoursRun2 = value;
      } else if (ind == 3) {
        uvlightStat.ledHoursRun3 = value;
      } else if (ind == 4) {
        uvlightStat.ledHoursRun4 = value;
      } else if (ind == 5) {
        uvlightStat.ledHoursRun5 = value;
      } else if (ind == 6) {
        uvlightStat.ledHoursRun6 = value;
      } else if (ind == 7) {
        uvlightStat.ledHoursRun7 = value;
      } else if (ind == 8) {
        uvlightStat.ledHoursRun8 = value;
      } else if (ind == 9) {
        uvlightStat.ledHoursRun9 = value;
      } else if (ind == 10) {
        uvlightStat.ledHoursRun10 = value;
      } else if (ind == 11) {
        uvlightStat.ledHoursRun11 = value;
      } else if (ind == 12) {
        uvlightStat.ledHoursRun12 = value;
      } else if (ind == 13) {
        uvlightStat.ledHoursRun13 = value;
      } else if (ind == 14) {
        uvlightStat.ledHoursRun14 = value;
      } else if (ind == 15) {
        uvlightStat.ledHoursRun15 = value;
      } else if (ind == 16) {
        uvlightStat.ledHoursRun16 = value;
      } else if (ind == 17) {
        uvlightStat.ledHoursRun17 = value;
      }
      else if (ind == 18) {
        uvlightStat.ledHoursRun18 = value;
      }
      else if (ind == 19) {
        uvlightStat.ledHoursRun19 = value;
      } else if (ind == 20) {
        uvlightStat.ledHoursRun20 = value;
      } else if (ind == 21) {
        uvlightStat.ledHoursRun21 = value;
      } else if (ind == 22) {
        uvlightStat.ledHoursRun22 = value;
      } else if (ind == 23) {
        uvlightStat.ledHoursRun23 = value;
      } else if (ind == 24) {
        uvlightStat.ledHoursRun24 = value;
      }

      else if (ind == 25) {
        uvlightStat.ledlastBuzzed1 = value;
      } else if (ind == 26) {
        uvlightStat.ledlastBuzzed2 = value;
      } else if (ind == 27) {
        uvlightStat.ledlastBuzzed3 = value;
      } else if (ind == 28) {
        uvlightStat.ledlastBuzzed4 = value;
      } else if (ind == 29) {
        uvlightStat.ledlastBuzzed5 = value;
      } else if (ind == 30) {
        uvlightStat.ledlastBuzzed6 = value;
      } else if (ind == 31) {
        uvlightStat.ledlastBuzzed7 = value;
      } else if (ind == 32) {
        uvlightStat.ledlastBuzzed8 = value;
      } else if (ind == 33) {
        uvlightStat.ledlastBuzzed9 = value;
      } else if (ind == 34) {
        uvlightStat.ledlastBuzzed10 = value;
      } else if (ind == 35) {
        uvlightStat.ledlastBuzzed11 = value;
      } else if (ind == 36) {
        uvlightStat.ledlastBuzzed12 = value;
      } else if (ind == 37) {
        uvlightStat.ledlastBuzzed13 = value;
      } else if (ind == 38) {
        uvlightStat.ledlastBuzzed14 = value;
      } else if (ind == 39) {
        uvlightStat.ledlastBuzzed15 = value;
      } else if (ind == 40) {
        uvlightStat.ledlastBuzzed16 = value;
      } else if (ind == 41) {
        uvlightStat.ledlastBuzzed17 = value;
      }
      else if (ind == 42) {
        uvlightStat.ledlastBuzzed18 = value;
      }
      else if (ind == 43) {
        uvlightStat.ledlastBuzzed19 = value;
      } else if (ind == 44) {
        uvlightStat.ledlastBuzzed20 = value;
      } else if (ind == 45) {
        uvlightStat.ledlastBuzzed21 = value;
      } else if (ind == 46) {
        uvlightStat.ledlastBuzzed22 = value;
      } else if (ind == 47) {
        uvlightStat.ledlastBuzzed23 = value;
      } else if (ind == 48) {
        uvlightStat.ledlastBuzzed24 = value;
      }
      else if (ind == 49) {
        uvlightStat.defaultLightHours = value;
      } else if (ind == 50) {
        uvlightStat.defaultBuzzerHours = value;
      }
    }
  }

  if (SD.exists(FILE_NAME1_1)) {
    myFile = SD.open(FILE_NAME1_1);
    while (myFile.available())
    {
      String strBuffer = myFile.readStringUntil('\n');
      int ind = utils.getValue(strBuffer, '=', 0).toInt();
      long value = utils.getValue(strBuffer, '=', 1).toInt();
      Serial.print(ind);
      Serial.print("-");
      Serial.println(value);

      if (ind == 51) {
        uvlightStat.ledHoursRun25 = value;
      } else if (ind == 52) {
        uvlightStat.ledHoursRun26 = value;
      } else if (ind == 53) {
        uvlightStat.ledHoursRun27 = value;
      } else if (ind == 54) {
        uvlightStat.ledHoursRun28 = value;
      } else if (ind == 55) {
        uvlightStat.ledHoursRun29 = value;
      } else if (ind == 56) {
        uvlightStat.ledHoursRun30 = value;
      } else if (ind == 57) {
        uvlightStat.ledHoursRun31 = value;
      } else if (ind == 58) {
        uvlightStat.ledHoursRun32 = value;
      } else if (ind == 59) {
        uvlightStat.ledHoursRun33 = value;
      } else if (ind == 60) {
        uvlightStat.ledHoursRun34 = value;
      } else if (ind == 61) {
        uvlightStat.ledHoursRun35 = value;
      } else if (ind == 62) {
        uvlightStat.ledHoursRun36 = value;
      } else if (ind == 63) {
        uvlightStat.ledHoursRun37 = value;
      } else if (ind == 64) {
        uvlightStat.ledHoursRun38 = value;
      } else if (ind == 65) {
        uvlightStat.ledHoursRun39 = value;
      } else if (ind == 66) {
        uvlightStat.ledHoursRun40 = value;
      } else if (ind == 67) {
        uvlightStat.ledHoursRun41 = value;
      } else if (ind == 68) {
        uvlightStat.ledHoursRun42 = value;
      } else if (ind == 69) {
        uvlightStat.ledHoursRun43 = value;
      } else if (ind == 70) {
        uvlightStat.ledHoursRun44 = value;
      } else if (ind == 71) {
        uvlightStat.ledHoursRun45 = value;
      } else if (ind == 72) {
        uvlightStat.ledHoursRun46 = value;
      } else if (ind == 73) {
        uvlightStat.ledHoursRun47 = value;
      } else if (ind == 74) {
        uvlightStat.ledHoursRun48 = value;
      } else if (ind == 75) {
        uvlightStat.ledHoursRun49 = value;
      } else if (ind == 76) {
        uvlightStat.ledHoursRun50 = value;
      } else if (ind == 77) {
        uvlightStat.ledHoursRun51 = value;
      } else if (ind == 78) {
        uvlightStat.ledHoursRun52 = value;
      } else if (ind == 79) {
        uvlightStat.ledHoursRun53 = value;
      } else if (ind == 80) {
        uvlightStat.ledHoursRun54 = value;
      } else if (ind == 81) {
        uvlightStat.ledHoursRun55 = value;
      } else if (ind == 82) {
        uvlightStat.ledHoursRun56 = value;
      } else if (ind == 83) {
        uvlightStat.ledHoursRun57 = value;
      } else if (ind == 84) {
        uvlightStat.ledHoursRun58 = value;
      } else if (ind == 85) {
        uvlightStat.ledHoursRun59 = value;
      } else if (ind == 86) {
        uvlightStat.ledHoursRun60 = value;
      } else if (ind == 87) {
        uvlightStat.ledlastBuzzed25 = value;
      } else if (ind == 88) {
        uvlightStat.ledlastBuzzed26 = value;
      } else if (ind == 89) {
        uvlightStat.ledlastBuzzed27 = value;
      } else if (ind == 90) {
        uvlightStat.ledlastBuzzed28 = value;
      } else if (ind == 91) {
        uvlightStat.ledlastBuzzed29 = value;
      } else if (ind == 92) {
        uvlightStat.ledlastBuzzed30 = value;
      } else if (ind == 93) {
        uvlightStat.ledlastBuzzed31 = value;
      } else if (ind == 94) {
        uvlightStat.ledlastBuzzed32 = value;
      } else if (ind == 95) {
        uvlightStat.ledlastBuzzed33 = value;
      } else if (ind == 96) {
        uvlightStat.ledlastBuzzed34 = value;
      } else if (ind == 97) {
        uvlightStat.ledlastBuzzed35 = value;
      } else if (ind == 98) {
        uvlightStat.ledlastBuzzed36 = value;
      } else if (ind == 99) {
        uvlightStat.ledlastBuzzed37 = value;
      }
      else if (ind == 100) {
        uvlightStat.ledlastBuzzed38 = value;
      } else if (ind == 101) {
        uvlightStat.ledlastBuzzed39 = value;
      } else if (ind == 102) {
        uvlightStat.ledlastBuzzed40 = value;
      } else if (ind == 103) {
        uvlightStat.ledlastBuzzed41 = value;
      } else if (ind == 104) {
        uvlightStat.ledlastBuzzed42 = value;
      } else if (ind == 105) {
        uvlightStat.ledlastBuzzed43 = value;
      } else if (ind == 106) {
        uvlightStat.ledlastBuzzed44 = value;
      } else if (ind == 107) {
        uvlightStat.ledlastBuzzed45 = value;
      } else if (ind == 108) {
        uvlightStat.ledlastBuzzed46 = value;
      } else if (ind == 109) {
        uvlightStat.ledlastBuzzed47 = value;
      } else if (ind == 110) {
        uvlightStat.ledlastBuzzed48 = value;
      } else if (ind == 111) {
        uvlightStat.ledlastBuzzed49 = value;
      } else if (ind == 112) {
        uvlightStat.ledlastBuzzed50 = value;
      } else if (ind == 113) {
        uvlightStat.ledlastBuzzed51 = value;
      } else if (ind == 114) {
        uvlightStat.ledlastBuzzed52 = value;
      } else if (ind == 115) {
        uvlightStat.ledlastBuzzed53 = value;
      } else if (ind == 116) {
        uvlightStat.ledlastBuzzed54 = value;
      } else if (ind == 117) {
        uvlightStat.ledlastBuzzed55 = value;
      } else if (ind == 118) {
        uvlightStat.ledlastBuzzed56 = value;
      } else if (ind == 119) {
        uvlightStat.ledlastBuzzed57 = value;
      } else if (ind == 120) {
        uvlightStat.ledlastBuzzed58 = value;
      } else if (ind == 121) {
        uvlightStat.ledlastBuzzed59 = value;
      } else if (ind == 122) {
        uvlightStat.ledlastBuzzed60 = value;
      }
    }
  }
}

void readSDMsg() {
  if (SD.exists(FILE_NAME)) {
    myFile = SD.open(FILE_NAME);
    while (myFile.available())
    {
      String strBuffer = myFile.readStringUntil('\n');
      int ind = utils.getValue(strBuffer, '=', 0).toInt();
      long value = utils.getValue(strBuffer, '=', 1).toInt();
      Serial.print(ind);
      Serial.print("-");
      Serial.println(value);

      if (ind == 1) {
        uvlightStat.ledHoursRun1 = value;
      }
      else if (ind == 2) {
        uvlightStat.ledHoursRun2 = value;
      } else if (ind == 3) {
        uvlightStat.ledHoursRun3 = value;
      } else if (ind == 4) {
        uvlightStat.ledHoursRun4 = value;
      } else if (ind == 5) {
        uvlightStat.ledHoursRun5 = value;
      } else if (ind == 6) {
        uvlightStat.ledHoursRun6 = value;
      } else if (ind == 7) {
        uvlightStat.ledHoursRun7 = value;
      } else if (ind == 8) {
        uvlightStat.ledHoursRun8 = value;
      } else if (ind == 9) {
        uvlightStat.ledHoursRun9 = value;
      } else if (ind == 10) {
        uvlightStat.ledHoursRun10 = value;
      } else if (ind == 11) {
        uvlightStat.ledHoursRun11 = value;
      } else if (ind == 12) {
        uvlightStat.ledHoursRun12 = value;
      } else if (ind == 13) {
        uvlightStat.ledHoursRun13 = value;
      } else if (ind == 14) {
        uvlightStat.ledHoursRun14 = value;
      } else if (ind == 15) {
        uvlightStat.ledHoursRun15 = value;
      } else if (ind == 16) {
        uvlightStat.ledHoursRun16 = value;
      } else if (ind == 17) {
        uvlightStat.ledHoursRun17 = value;
      }
      else if (ind == 18) {
        uvlightStat.ledHoursRun18 = value;
      }
      else if (ind == 19) {
        uvlightStat.ledHoursRun19 = value;
      } else if (ind == 20) {
        uvlightStat.ledHoursRun20 = value;
      } else if (ind == 21) {
        uvlightStat.ledHoursRun21 = value;
      } else if (ind == 22) {
        uvlightStat.ledHoursRun22 = value;
      } else if (ind == 23) {
        uvlightStat.ledHoursRun23 = value;
      } else if (ind == 24) {
        uvlightStat.ledHoursRun24 = value;
      }

      else if (ind == 25) {
        uvlightStat.ledlastBuzzed1 = value;
      } else if (ind == 26) {
        uvlightStat.ledlastBuzzed2 = value;
      } else if (ind == 27) {
        uvlightStat.ledlastBuzzed3 = value;
      } else if (ind == 28) {
        uvlightStat.ledlastBuzzed4 = value;
      } else if (ind == 29) {
        uvlightStat.ledlastBuzzed5 = value;
      } else if (ind == 30) {
        uvlightStat.ledlastBuzzed6 = value;
      } else if (ind == 31) {
        uvlightStat.ledlastBuzzed7 = value;
      } else if (ind == 32) {
        uvlightStat.ledlastBuzzed8 = value;
      } else if (ind == 33) {
        uvlightStat.ledlastBuzzed9 = value;
      } else if (ind == 34) {
        uvlightStat.ledlastBuzzed10 = value;
      } else if (ind == 35) {
        uvlightStat.ledlastBuzzed11 = value;
      } else if (ind == 36) {
        uvlightStat.ledlastBuzzed12 = value;
      } else if (ind == 37) {
        uvlightStat.ledlastBuzzed13 = value;
      } else if (ind == 38) {
        uvlightStat.ledlastBuzzed14 = value;
      } else if (ind == 39) {
        uvlightStat.ledlastBuzzed15 = value;
      } else if (ind == 40) {
        uvlightStat.ledlastBuzzed16 = value;
      } else if (ind == 41) {
        uvlightStat.ledlastBuzzed17 = value;
      }
      else if (ind == 42) {
        uvlightStat.ledlastBuzzed18 = value;
      }
      else if (ind == 43) {
        uvlightStat.ledlastBuzzed19 = value;
      } else if (ind == 44) {
        uvlightStat.ledlastBuzzed20 = value;
      } else if (ind == 45) {
        uvlightStat.ledlastBuzzed21 = value;
      } else if (ind == 46) {
        uvlightStat.ledlastBuzzed22 = value;
      } else if (ind == 47) {
        uvlightStat.ledlastBuzzed23 = value;
      } else if (ind == 48) {
        uvlightStat.ledlastBuzzed24 = value;
      }
      else if (ind == 49) {
        uvlightStat.defaultLightHours = value;
      } else if (ind == 50) {
        uvlightStat.defaultBuzzerHours = value;
      }
    }
  }

  if (SD.exists(FILE_NAME_1)) {
    myFile = SD.open(FILE_NAME_1);
    while (myFile.available())
    {
      String strBuffer = myFile.readStringUntil('\n');
      int ind = utils.getValue(strBuffer, '=', 0).toInt();
      long value = utils.getValue(strBuffer, '=', 1).toInt();
      Serial.print(ind);
      Serial.print("-");
      Serial.println(value);

      if (ind == 51) {
        uvlightStat.ledHoursRun25 = value;
      } else if (ind == 52) {
        uvlightStat.ledHoursRun26 = value;
      } else if (ind == 53) {
        uvlightStat.ledHoursRun27 = value;
      } else if (ind == 54) {
        uvlightStat.ledHoursRun28 = value;
      } else if (ind == 55) {
        uvlightStat.ledHoursRun29 = value;
      } else if (ind == 56) {
        uvlightStat.ledHoursRun30 = value;
      } else if (ind == 57) {
        uvlightStat.ledHoursRun31 = value;
      } else if (ind == 58) {
        uvlightStat.ledHoursRun32 = value;
      } else if (ind == 59) {
        uvlightStat.ledHoursRun33 = value;
      } else if (ind == 60) {
        uvlightStat.ledHoursRun34 = value;
      } else if (ind == 61) {
        uvlightStat.ledHoursRun35 = value;
      } else if (ind == 62) {
        uvlightStat.ledHoursRun36 = value;
      } else if (ind == 63) {
        uvlightStat.ledHoursRun37 = value;
      } else if (ind == 64) {
        uvlightStat.ledHoursRun38 = value;
      } else if (ind == 65) {
        uvlightStat.ledHoursRun39 = value;
      } else if (ind == 66) {
        uvlightStat.ledHoursRun40 = value;
      } else if (ind == 67) {
        uvlightStat.ledHoursRun41 = value;
      } else if (ind == 68) {
        uvlightStat.ledHoursRun42 = value;
      } else if (ind == 69) {
        uvlightStat.ledHoursRun43 = value;
      } else if (ind == 70) {
        uvlightStat.ledHoursRun44 = value;
      } else if (ind == 71) {
        uvlightStat.ledHoursRun45 = value;
      } else if (ind == 72) {
        uvlightStat.ledHoursRun46 = value;
      } else if (ind == 73) {
        uvlightStat.ledHoursRun47 = value;
      } else if (ind == 74) {
        uvlightStat.ledHoursRun48 = value;
      } else if (ind == 75) {
        uvlightStat.ledHoursRun49 = value;
      } else if (ind == 76) {
        uvlightStat.ledHoursRun50 = value;
      } else if (ind == 77) {
        uvlightStat.ledHoursRun51 = value;
      } else if (ind == 78) {
        uvlightStat.ledHoursRun52 = value;
      } else if (ind == 79) {
        uvlightStat.ledHoursRun53 = value;
      } else if (ind == 80) {
        uvlightStat.ledHoursRun54 = value;
      } else if (ind == 81) {
        uvlightStat.ledHoursRun55 = value;
      } else if (ind == 82) {
        uvlightStat.ledHoursRun56 = value;
      } else if (ind == 83) {
        uvlightStat.ledHoursRun57 = value;
      } else if (ind == 84) {
        uvlightStat.ledHoursRun58 = value;
      } else if (ind == 85) {
        uvlightStat.ledHoursRun59 = value;
      } else if (ind == 86) {
        uvlightStat.ledHoursRun60 = value;
      } else if (ind == 87) {
        uvlightStat.ledlastBuzzed25 = value;
      } else if (ind == 88) {
        uvlightStat.ledlastBuzzed26 = value;
      } else if (ind == 89) {
        uvlightStat.ledlastBuzzed27 = value;
      } else if (ind == 90) {
        uvlightStat.ledlastBuzzed28 = value;
      } else if (ind == 91) {
        uvlightStat.ledlastBuzzed29 = value;
      } else if (ind == 92) {
        uvlightStat.ledlastBuzzed30 = value;
      } else if (ind == 93) {
        uvlightStat.ledlastBuzzed31 = value;
      } else if (ind == 94) {
        uvlightStat.ledlastBuzzed32 = value;
      } else if (ind == 95) {
        uvlightStat.ledlastBuzzed33 = value;
      } else if (ind == 96) {
        uvlightStat.ledlastBuzzed34 = value;
      } else if (ind == 97) {
        uvlightStat.ledlastBuzzed35 = value;
      } else if (ind == 98) {
        uvlightStat.ledlastBuzzed36 = value;
      } else if (ind == 99) {
        uvlightStat.ledlastBuzzed37 = value;
      }
      else if (ind == 100) {
        uvlightStat.ledlastBuzzed38 = value;
      } else if (ind == 101) {
        uvlightStat.ledlastBuzzed39 = value;
      } else if (ind == 102) {
        uvlightStat.ledlastBuzzed40 = value;
      } else if (ind == 103) {
        uvlightStat.ledlastBuzzed41 = value;
      } else if (ind == 104) {
        uvlightStat.ledlastBuzzed42 = value;
      } else if (ind == 105) {
        uvlightStat.ledlastBuzzed43 = value;
      } else if (ind == 106) {
        uvlightStat.ledlastBuzzed44 = value;
      } else if (ind == 107) {
        uvlightStat.ledlastBuzzed45 = value;
      } else if (ind == 108) {
        uvlightStat.ledlastBuzzed46 = value;
      } else if (ind == 109) {
        uvlightStat.ledlastBuzzed47 = value;
      } else if (ind == 110) {
        uvlightStat.ledlastBuzzed48 = value;
      } else if (ind == 111) {
        uvlightStat.ledlastBuzzed49 = value;
      } else if (ind == 112) {
        uvlightStat.ledlastBuzzed50 = value;
      } else if (ind == 113) {
        uvlightStat.ledlastBuzzed51 = value;
      } else if (ind == 114) {
        uvlightStat.ledlastBuzzed52 = value;
      } else if (ind == 115) {
        uvlightStat.ledlastBuzzed53 = value;
      } else if (ind == 116) {
        uvlightStat.ledlastBuzzed54 = value;
      } else if (ind == 117) {
        uvlightStat.ledlastBuzzed55 = value;
      } else if (ind == 118) {
        uvlightStat.ledlastBuzzed56 = value;
      } else if (ind == 119) {
        uvlightStat.ledlastBuzzed57 = value;
      } else if (ind == 120) {
        uvlightStat.ledlastBuzzed58 = value;
      } else if (ind == 121) {
        uvlightStat.ledlastBuzzed59 = value;
      } else if (ind == 122) {
        uvlightStat.ledlastBuzzed60 = value;
      }
    }
  }
}

void sdCardFailure() {
  defaultMsgStat = 4;
  lcd.clear();
  delay(500);

  String line1 = "SD card Failure";
  lcd.print(line1);

  delay(500);
}

void muteErrors(int light) {
  defaultMsgStat = 4;
  lcd.clear();
  delay(500);
  digitalWrite(constants.BUZZER_PIN, LOW);
  String line1 = "Light " + String(light) + " muted.";
  lcd.print(line1);

  delay(5000);
}

void resetPassCodeProtection(int option, String msg) {

  defaultMsgStat = 4;
  lcd.clear();
  delay(500);
  lcd.setCursor(0, 0);
  String line1 = "Reset Pressed";
  if (option == 1) {
    line1 = "Menu Pressed";
  }
  lcd.print(line1);

  lcd.setCursor(0, 1);
  lcd.print(msg);
}

void checkBuzzerAndStat(int positionOfErrorLight, int currentPosition, long currentEpooch, long hoursRanSoFar, byte statOfLED) {
  if (uvlightStat.erroredLight[positionOfErrorLight] == 1) {
    muteErrors(currentPosition); // deactivate error in display
    buzzerStat = false;
    setLastBuzzed(currentPosition, currentEpooch);
    uvlightStat.erroredLight[positionOfErrorLight] = 0;
  } else {
    buzzerStat = false;
    lastPressed = currentPosition;
    displayCounter = 10;
    updateLCD(hoursRanSoFar, statOfLED);
  }
}

void setLastBuzzed(int order, long epoochValue) {
  switch (order) {
    case 1:
      uvlightStat.ledlastBuzzed1 = epoochValue;
      break;
    case 2:
      uvlightStat.ledlastBuzzed2 = epoochValue;
      break;
    case 3:
      uvlightStat.ledlastBuzzed3 = epoochValue;
      break;
    case 4:
      uvlightStat.ledlastBuzzed4 = epoochValue;
      break;
    case 5:
      uvlightStat.ledlastBuzzed5 = epoochValue;
      break;
    case 6:
      uvlightStat.ledlastBuzzed6 = epoochValue;
      break;
    case 7:
      uvlightStat.ledlastBuzzed7 = epoochValue;
      break;
    case 8:
      uvlightStat.ledlastBuzzed8 = epoochValue;
      break;
    case 9:
      uvlightStat.ledlastBuzzed9 = epoochValue;
      break;
    case 10:
      uvlightStat.ledlastBuzzed10 = epoochValue;
      break;
    case 11:
      uvlightStat.ledlastBuzzed11 = epoochValue;
      break;
    case 12:
      uvlightStat.ledlastBuzzed12 = epoochValue;
      break;
    case 13:
      uvlightStat.ledlastBuzzed13 = epoochValue;
      break;
    case 14:
      uvlightStat.ledlastBuzzed14 = epoochValue;
      break;
    case 15:
      uvlightStat.ledlastBuzzed15 = epoochValue;
      break;
    case 16:
      uvlightStat.ledlastBuzzed16 = epoochValue;
      break;
    case 17:
      uvlightStat.ledlastBuzzed17 = epoochValue;
      break;
    case 18:
      uvlightStat.ledlastBuzzed18 = epoochValue;
      break;
    case 19:
      uvlightStat.ledlastBuzzed19 = epoochValue;
      break;
    case 20:
      uvlightStat.ledlastBuzzed20 = epoochValue;
      break;
    case 21:
      uvlightStat.ledlastBuzzed21 = epoochValue;
      break;
    case 22:
      uvlightStat.ledlastBuzzed22 = epoochValue;
      break;
    case 23:
      uvlightStat.ledlastBuzzed23 = epoochValue;
      break;
    case 24:
      uvlightStat.ledlastBuzzed24 = epoochValue;
      break;
    case 25:
      uvlightStat.ledlastBuzzed25 = epoochValue;
      break;
    case 26:
      uvlightStat.ledlastBuzzed26 = epoochValue;
      break;

    case 27:
      uvlightStat.ledlastBuzzed27 = epoochValue;
      break;

    case 28:
      uvlightStat.ledlastBuzzed28 = epoochValue;
      break;

    case 29:
      uvlightStat.ledlastBuzzed29 = epoochValue;
      break;

    case 30:
      uvlightStat.ledlastBuzzed30 = epoochValue;
      break;

    case 31:
      uvlightStat.ledlastBuzzed31 = epoochValue;
      break;

    case 32:
      uvlightStat.ledlastBuzzed32 = epoochValue;
      break;

    case 33:
      uvlightStat.ledlastBuzzed33 = epoochValue;
      break;

    case 34:
      uvlightStat.ledlastBuzzed34 = epoochValue;
      break;

    case 35:
      uvlightStat.ledlastBuzzed35 = epoochValue;
      break;

    case 36:
      uvlightStat.ledlastBuzzed36 = epoochValue;
      break;

    case 37:
      uvlightStat.ledlastBuzzed37 = epoochValue;
      break;

    case 38:
      uvlightStat.ledlastBuzzed38 = epoochValue;
      break;

    case 39:
      uvlightStat.ledlastBuzzed39 = epoochValue;
      break;

    case 40:
      uvlightStat.ledlastBuzzed40 = epoochValue;
      break;

    case 41:
      uvlightStat.ledlastBuzzed41 = epoochValue;
      break;

    case 42:
      uvlightStat.ledlastBuzzed42 = epoochValue;
      break;

    case 43:
      uvlightStat.ledlastBuzzed43 = epoochValue;
      break;

    case 44:
      uvlightStat.ledlastBuzzed44 = epoochValue;
      break;
    case 45:
      uvlightStat.ledlastBuzzed45 = epoochValue;
      break;
    case 46:
      uvlightStat.ledlastBuzzed46 = epoochValue;
      break;
    case 47:
      uvlightStat.ledlastBuzzed47 = epoochValue;
      break;
    case 48:
      uvlightStat.ledlastBuzzed48 = epoochValue;
      break;
    case 49:
      uvlightStat.ledlastBuzzed49 = epoochValue;
      break;
    case 50:
      uvlightStat.ledlastBuzzed50 = epoochValue;
      break;
    case 51:
      uvlightStat.ledlastBuzzed51 = epoochValue;
      break;
    case 52:
      uvlightStat.ledlastBuzzed52 = epoochValue;
      break;
    case 53:
      uvlightStat.ledlastBuzzed53 = epoochValue;
      break;
    case 54:
      uvlightStat.ledlastBuzzed54 = epoochValue;
      break;
    case 55:
      uvlightStat.ledlastBuzzed55 = epoochValue;
      break;
    case 56:
      uvlightStat.ledlastBuzzed56 = epoochValue;
      break;
    case 57:
      uvlightStat.ledlastBuzzed57 = epoochValue;
      break;
    case 58:
      uvlightStat.ledlastBuzzed58 = epoochValue;
      break;
    case 59:
      uvlightStat.ledlastBuzzed59 = epoochValue;
      break;
    case 60:
      uvlightStat.ledlastBuzzed60 = epoochValue;
      break;
  }
}


bool passwordProtection(int code) {

  while (true) {
    resetPassCodeProtection(code, "Select code 1...");
    bool selectedOption1 = uvlightStat.chooseButtonPressed(10);
    if (! selectedOption1) {
      resetPassCodeProtection(code, "Incorrect pattern");
      return false;
    }

    resetPassCodeProtection(code, "Select code 2...");
    bool selectedOption2 = uvlightStat.chooseButtonPressed(12);
    if (! selectedOption2) {
      resetPassCodeProtection(code, "Incorrect pattern");
      return false;
    }

    resetPassCodeProtection(code, "Select code 3...");
    bool selectedOption3 = uvlightStat.chooseButtonPressed(13);
    if (! selectedOption3) {
      resetPassCodeProtection(code, "Incorrect pattern");
      return false;
    }

    resetPassCodeProtection(code, "Select code 4...");
    bool selectedOption4 = uvlightStat.chooseButtonPressed(14);
    if (! selectedOption4) {
      resetPassCodeProtection(code, "Incorrect pattern");
      return false;
    } else {
      return true;
    }
  }
}

void updateModbusData() {

  if (uvlightStat.led1Status == '1') {
    au16data[0] = 1;
  } else {
    au16data[0] = 0;
  };
  if (uvlightStat.led2Status == '1') {
    au16data[1] = 1;
  } else {
    au16data[1] = 0;
  };
  if (uvlightStat.led3Status == '1') {
    au16data[2] = 1;
  } else {
    au16data[2] = 0;
  };
  if (uvlightStat.led4Status == '1') {
    au16data[3] = 1;
  } else {
    au16data[3] = 0;
  };

  if (uvlightStat.led5Status == '1') {
    au16data[4] = 1;
  } else {
    au16data[4] = 0;
  };
  ;
  if (uvlightStat.led6Status == '1') {
    au16data[5] = 1;
  } else {
    au16data[5] = 0;
  };

  if (uvlightStat.led7Status == '1') {
    au16data[6] = 1;
  } else {
    au16data[6] = 0;
  };

  if (uvlightStat.led8Status == '1') {
    au16data[7] = 1;
  } else {
    au16data[7] = 0;
  };

  if (uvlightStat.led9Status == '1') {
    au16data[8] = 1;
  } else {
    au16data[8] = 0;
  };

  if (uvlightStat.led10Status == '1') {
    au16data[9] = 1;
  } else {
    au16data[9] = 0;
  };

  if (uvlightStat.led11Status == '1') {
    au16data[10] = 1;
  } else {
    au16data[10] = 0;
  };

  if (uvlightStat.led12Status == '1') {
    au16data[11] = 1;
  } else {
    au16data[11] = 0;
  };


  if (uvlightStat.led13Status == '1') {
    au16data[12] = 1;
  } else {
    au16data[12] = 0;
  };

  if (uvlightStat.led14Status == '1') {
    au16data[13] = 1;
  } else {
    au16data[13] = 0;
  };

  if (uvlightStat.led15Status == '1') {
    au16data[14] = 1;
  } else {
    au16data[14] = 0;
  };

  if (uvlightStat.led16Status == '1') {
    au16data[15] = 1;
  } else {
    au16data[15] = 0;
  };

  if (uvlightStat.led17Status == '1') {
    au16data[16] = 1;
  } else {
    au16data[16] = 0;
  };

  if (uvlightStat.led18Status == '1') {
    au16data[17] = 1;
  } else {
    au16data[17] = 0;
  };

  if (uvlightStat.led19Status == '1') {
    au16data[18] = 1;
  } else {
    au16data[18] = 0;
  };

  if (uvlightStat.led20Status == '1') {
    au16data[19] = 1;
  } else {
    au16data[19] = 0;
  };

  if (uvlightStat.led21Status == '1') {
    au16data[20] = 1;
  } else {
    au16data[20] = 0;
  };

  if (uvlightStat.led22Status == '1') {
    au16data[21] = 1;
  } else {
    au16data[21] = 0;
  };

  if (uvlightStat.led23Status == '1') {
    au16data[22] = 1;
  } else {
    au16data[22] = 0;
  };

  if (uvlightStat.led24Status == '1') {
    au16data[23] = 1;
  } else {
    au16data[23] = 0;
  };
  if (uvlightStat.led25Status == '1') {
    au16data[24] = 1;
  } else {
    au16data[24] = 0;
  };
  if (uvlightStat.led26Status == '1') {
    au16data[25] = 1;
  } else {
    au16data[25] = 0;
  };
  if (uvlightStat.led27Status == '1') {
    au16data[26] = 1;
  } else {
    au16data[26] = 0;
  };
  if (uvlightStat.led28Status == '1') {
    au16data[27] = 1;
  } else {
    au16data[27] = 0;
  };

  if (uvlightStat.led29Status == '1') {
    au16data[28] = 1;
  } else {
    au16data[28] = 0;
  };
  ;
  if (uvlightStat.led30Status == '1') {
    au16data[29] = 1;
  } else {
    au16data[29] = 0;
  };

  if (uvlightStat.led31Status == '1') {
    au16data[30] = 1;
  } else {
    au16data[30] = 0;
  };

  if (uvlightStat.led32Status == '1') {
    au16data[31] = 1;
  } else {
    au16data[31] = 0;
  };

  if (uvlightStat.led33Status == '1') {
    au16data[32] = 1;
  } else {
    au16data[32] = 0;
  };

  if (uvlightStat.led34Status == '1') {
    au16data[33] = 1;
  } else {
    au16data[33] = 0;
  };

  if (uvlightStat.led35Status == '1') {
    au16data[34] = 1;
  } else {
    au16data[34] = 0;
  };

  if (uvlightStat.led36Status == '1') {
    au16data[35] = 1;
  } else {
    au16data[35] = 0;
  };


  if (uvlightStat.led37Status == '1') {
    au16data[36] = 1;
  } else {
    au16data[36] = 0;
  };

  if (uvlightStat.led38Status == '1') {
    au16data[37] = 1;
  } else {
    au16data[37] = 0;
  };

  if (uvlightStat.led39Status == '1') {
    au16data[38] = 1;
  } else {
    au16data[38] = 0;
  };

  if (uvlightStat.led40Status == '1') {
    au16data[39] = 1;
  } else {
    au16data[39] = 0;
  };

  if (uvlightStat.led41Status == '1') {
    au16data[40] = 1;
  } else {
    au16data[40] = 0;
  };

  if (uvlightStat.led42Status == '1') {
    au16data[41] = 1;
  } else {
    au16data[41] = 0;
  };

  if (uvlightStat.led43Status == '1') {
    au16data[42] = 1;
  } else {
    au16data[42] = 0;
  };

  if (uvlightStat.led44Status == '1') {
    au16data[43] = 1;
  } else {
    au16data[43] = 0;
  };

  if (uvlightStat.led45Status == '1') {
    au16data[44] = 1;
  } else {
    au16data[44] = 0;
  };

  if (uvlightStat.led46Status == '1') {
    au16data[45] = 1;
  } else {
    au16data[45] = 0;
  };

  if (uvlightStat.led47Status == '1') {
    au16data[46] = 1;
  } else {
    au16data[46] = 0;
  };

  if (uvlightStat.led48Status == '1') {
    au16data[47] = 1;
  } else {
    au16data[47] = 0;
  };
  if (uvlightStat.led49Status == '1') {
    au16data[48] = 1;
  } else {
    au16data[48] = 0;
  };

  if (uvlightStat.led50Status == '1') {
    au16data[49] = 1;
  } else {
    au16data[49] = 0;
  };

  if (uvlightStat.led51Status == '1') {
    au16data[50] = 1;
  } else {
    au16data[50] = 0;
  };

  if (uvlightStat.led52Status == '1') {
    au16data[51] = 1;
  } else {
    au16data[51] = 0;
  };

  if (uvlightStat.led53Status == '1') {
    au16data[52] = 1;
  } else {
    au16data[52] = 0;
  };

  if (uvlightStat.led54Status == '1') {
    au16data[53] = 1;
  } else {
    au16data[53] = 0;
  };

  if (uvlightStat.led55Status == '1') {
    au16data[54] = 1;
  } else {
    au16data[54] = 0;
  };

  if (uvlightStat.led56Status == '1') {
    au16data[55] = 1;
  } else {
    au16data[55] = 0;
  };

  if (uvlightStat.led57Status == '1') {
    au16data[56] = 1;
  } else {
    au16data[56] = 0;
  };
  if (uvlightStat.led58Status == '1') {
    au16data[57] = 1;
  } else {
    au16data[57] = 0;
  };

  if (uvlightStat.led59Status == '1') {
    au16data[58] = 1;
  } else {
    au16data[58] = 0;
  };

  if (uvlightStat.led60Status == '1') {
    au16data[59] = 1;
  } else {
    au16data[59] = 0;
  };

}

bool checkIfAnyBuzzerActive() {
  bool isAnyError = false;
  for (int i = 0; i <= 59; i++) {
    if (uvlightStat.erroredLight[i] == 1) {
      Serial.print(i + 1);
      Serial.print(" - ");
      Serial.println(uvlightStat.erroredLight[i]);
      isAnyError = true;
      break;
    }
  }
  return isAnyError;
}

void muteAllBuzzing(long epoochTime) {
  digitalWrite(constants.BUZZER_PIN, LOW); // TMP off buzzer - not necessary
  for (int i = 0; i <= 59; i++) {
    if (uvlightStat.erroredLight[i] == 1) {
      buzzerStat = false;
      setLastBuzzed(i + 1, epoochTime); // setLastBuzzed(int order, long epoochValue);
      uvlightStat.erroredLight[i] = 0;
    }
  }
  buzzerStat = false;
}

void loop()
{
  updateModbusData();
  slave.poll();

  uvlightStat.statusOfUV();
  if (buzzerStat) {
    if (millis() - buzzerMillis > 2000) {
      Serial.println(F("Turning on buzzer"));
      digitalWrite(constants.BUZZER_PIN, HIGH);
      buzzerMillis = millis();
    }
  }

  //  Serial.print("Menu: ");
  //  Serial.println(digitalRead(constants.MENU_PIN));
  if (digitalRead(constants.MENU_PIN) == LOW) {
    Serial.println("Menu pressed ");
    menuLogic();
  } else if (digitalRead(constants.RESET_PIN) == LOW) {
    if (checkIfAnyBuzzerActive()) {
      Serial.println("Reset pressed - activated");
      muteAllBuzzing(rtc.now().unixtime());
      startingMsg();
      return;
    } else {
      Serial.println("none active");
    }

    int counter = 0;
    bool resetSuccessPattern = false;
    resetSuccessPattern = passwordProtection(0);

    if (resetSuccessPattern) {
      resetPresed();
      delay(2000);
      while (true) {
        int output = uvlightStat.reset();
        Serial.print("Pin pressed: ");
        Serial.println(output);
        if (output > 0) {
          resetAndPinPressed(output);
          counter = 0;
        }

        if (counter > 10) {
          break;
        }

        counter++;
        delay(500);
      }
    }

  } else {
    if ((millis() - lastRun) > defaultTimer) {
      uvlightStat.updateUVStat();
      delay(500);
      writeSDMsg1();
      delay(1000);
      writeSDMsg();
      lastRun = millis();
    }
    uint32_t timeBuzzed = rtc.now().unixtime();

    float voltage1 = analogRead(constants.UV_Light1_Input_BUTTON) * (5.0 / 1023.0);
    if (voltage1 < 2.5) {
      Serial.println("Low in 1");
      checkBuzzerAndStat(0, 1, timeBuzzed, uvlightStat.ledHoursRun1, uvlightStat.led1Status);
    }

    float voltage2 = analogRead(constants.UV_Light2_Input_BUTTON) * (5.0 / 1023.0);
    if (voltage2 < 2.5) {
      Serial.println("Low in 2");
      checkBuzzerAndStat(1, 2, timeBuzzed, uvlightStat.ledHoursRun2, uvlightStat.led2Status);
    }

    float voltage3 = analogRead(constants.UV_Light3_Input_BUTTON) * (5.0 / 1023.0);
    if (voltage3 < 2.5) {
      Serial.println("Low in 3");
      checkBuzzerAndStat(2, 3, timeBuzzed, uvlightStat.ledHoursRun3, uvlightStat.led3Status);
    }

    float voltage4 = analogRead(constants.UV_Light4_Input_BUTTON) * (5.0 / 1023.0);
    if (voltage4 < 2.5) {
      Serial.println("Low in 4");
      checkBuzzerAndStat(3, 4, timeBuzzed, uvlightStat.ledHoursRun4, uvlightStat.led4Status);
    }

    float voltage5 = analogRead(constants.UV_Light5_Input_BUTTON) * (5.0 / 1023.0);
    if (voltage5 < 2.5) {
      Serial.println("Low in 5");
      checkBuzzerAndStat(4, 5, timeBuzzed, uvlightStat.ledHoursRun5, uvlightStat.led5Status);
    }

    float voltage6 = analogRead(constants.UV_Light6_Input_BUTTON) * (5.0 / 1023.0);
    if (voltage6 < 2.5) {
      Serial.println("Low in 6");
      checkBuzzerAndStat(5, 6, timeBuzzed, uvlightStat.ledHoursRun6, uvlightStat.led6Status);
    }

    float voltage7 = analogRead(constants.UV_Light7_Input_BUTTON) * (5.0 / 1023.0);
    if (voltage7 < 2.5) {
      Serial.println("Low in 7");
      checkBuzzerAndStat(6, 7, timeBuzzed, uvlightStat.ledHoursRun7, uvlightStat.led7Status);
    }

    float voltage8 = analogRead(constants.UV_Light8_Input_BUTTON) * (5.0 / 1023.0);
    if (voltage8 < 2.5) {
      Serial.println("Low in 8");
      checkBuzzerAndStat(7, 8, timeBuzzed, uvlightStat.ledHoursRun8, uvlightStat.led8Status);
    }

    if (digitalRead(constants.UV_Light9_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(8, 9, timeBuzzed, uvlightStat.ledHoursRun9, uvlightStat.led9Status);
    } else if (digitalRead(constants.UV_Light10_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(9, 10, timeBuzzed, uvlightStat.ledHoursRun10, uvlightStat.led10Status);
    } else if (digitalRead(constants.UV_Light11_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(10, 11, timeBuzzed, uvlightStat.ledHoursRun11, uvlightStat.led11Status);
    } else if (digitalRead(constants.UV_Light12_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(11, 12, timeBuzzed, uvlightStat.ledHoursRun12, uvlightStat.led12Status);
    } else if (digitalRead(constants.UV_Light13_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(12, 13, timeBuzzed, uvlightStat.ledHoursRun13, uvlightStat.led13Status);
    } else if (digitalRead(constants.UV_Light14_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(13, 14, timeBuzzed, uvlightStat.ledHoursRun14, uvlightStat.led14Status);
    } else if (digitalRead(constants.UV_Light15_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(14, 15, timeBuzzed, uvlightStat.ledHoursRun15, uvlightStat.led15Status);
    } else if (digitalRead(constants.UV_Light16_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(15, 16, timeBuzzed, uvlightStat.ledHoursRun16, uvlightStat.led16Status);
    } else if (digitalRead(constants.UV_Light17_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(16, 17, timeBuzzed, uvlightStat.ledHoursRun17, uvlightStat.led17Status);
    }
    else if (digitalRead(constants.UV_Light18_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(17, 18, timeBuzzed, uvlightStat.ledHoursRun18, uvlightStat.led18Status);
    }
    else if (digitalRead(constants.UV_Light19_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(18, 19, timeBuzzed, uvlightStat.ledHoursRun19, uvlightStat.led19Status);
    } else if (digitalRead(constants.UV_Light20_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(19, 20, timeBuzzed, uvlightStat.ledHoursRun20, uvlightStat.led20Status);
    } else if (digitalRead(constants.UV_Light21_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(20, 21, timeBuzzed, uvlightStat.ledHoursRun21, uvlightStat.led21Status);
    }
    else if (digitalRead(constants.UV_Light22_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(21, 22, timeBuzzed, uvlightStat.ledHoursRun22, uvlightStat.led22Status);
    } else if (digitalRead(constants.UV_Light23_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(22, 23, timeBuzzed, uvlightStat.ledHoursRun23, uvlightStat.led23Status);
    } else if (digitalRead(constants.UV_Light24_Input_BUTTON) == LOW) {
      checkBuzzerAndStat(23, 24, timeBuzzed, uvlightStat.ledHoursRun24, uvlightStat.led24Status);
    }
    String buttonFPressedData = uvlightStat.buttonPressedData;
    char char_array[buttonFPressedData.length() + 1];
    buttonFPressedData.toCharArray(char_array, buttonFPressedData.length() + 1);

    if (char_array[1] == '0') {
      checkBuzzerAndStat(24, 25, timeBuzzed, uvlightStat.ledHoursRun25, uvlightStat.led25Status);
    }
    if (char_array[2] == '0') {
      checkBuzzerAndStat(25, 26, timeBuzzed, uvlightStat.ledHoursRun26, uvlightStat.led26Status);
    }
    if (char_array[3] == '0') {
      checkBuzzerAndStat(26, 27, timeBuzzed, uvlightStat.ledHoursRun27, uvlightStat.led27Status);
    }
    if (char_array[4] == '0') {
      checkBuzzerAndStat(27, 28, timeBuzzed, uvlightStat.ledHoursRun28, uvlightStat.led28Status);
    }
    if (char_array[5] == '0') {
      checkBuzzerAndStat(28, 29, timeBuzzed, uvlightStat.ledHoursRun29, uvlightStat.led29Status);
    }
    if (char_array[6] == '0') {
      checkBuzzerAndStat(29, 30, timeBuzzed, uvlightStat.ledHoursRun30, uvlightStat.led30Status);
    }
    if (char_array[7] == '0') {
      checkBuzzerAndStat(30, 31, timeBuzzed, uvlightStat.ledHoursRun31, uvlightStat.led31Status);
    }
    if (char_array[8] == '0') {
      checkBuzzerAndStat(31, 32, timeBuzzed, uvlightStat.ledHoursRun32, uvlightStat.led32Status);
    }
    if (char_array[9] == '0') {
      checkBuzzerAndStat(32, 33, timeBuzzed, uvlightStat.ledHoursRun33, uvlightStat.led33Status);
    }
    if (char_array[10] == '0') {
      checkBuzzerAndStat(33, 34, timeBuzzed, uvlightStat.ledHoursRun34, uvlightStat.led34Status);
    }
    if (char_array[11] == '0') {
      checkBuzzerAndStat(34, 35, timeBuzzed, uvlightStat.ledHoursRun35, uvlightStat.led35Status);
    }
    if (char_array[12] == '0') {
      checkBuzzerAndStat(35, 36, timeBuzzed, uvlightStat.ledHoursRun36, uvlightStat.led36Status);
    }
    if (char_array[13] == '0') {
      checkBuzzerAndStat(36, 37, timeBuzzed, uvlightStat.ledHoursRun37, uvlightStat.led37Status);
    }
    if (char_array[14] == '0') {
      checkBuzzerAndStat(37, 38, timeBuzzed, uvlightStat.ledHoursRun38, uvlightStat.led38Status);
    }
    if (char_array[15] == '0') {
      checkBuzzerAndStat(38, 39, timeBuzzed, uvlightStat.ledHoursRun39, uvlightStat.led39Status);
    }
    if (char_array[16] == '0') {
      checkBuzzerAndStat(39, 40, timeBuzzed, uvlightStat.ledHoursRun40, uvlightStat.led40Status);
    }
    if (char_array[17] == '0') {
      checkBuzzerAndStat(40, 41, timeBuzzed, uvlightStat.ledHoursRun41, uvlightStat.led41Status);
    }
    if (char_array[18] == '0') {
      checkBuzzerAndStat(41, 42, timeBuzzed, uvlightStat.ledHoursRun42, uvlightStat.led42Status);
    }
    if (char_array[19] == '0') {
      checkBuzzerAndStat(42, 43, timeBuzzed, uvlightStat.ledHoursRun43, uvlightStat.led43Status);
    }
    if (char_array[20] == '0') {
      checkBuzzerAndStat(43, 44, timeBuzzed, uvlightStat.ledHoursRun44, uvlightStat.led44Status);
    }
    if (char_array[21] == '0') {
      checkBuzzerAndStat(44, 45, timeBuzzed, uvlightStat.ledHoursRun45, uvlightStat.led45Status);
    }
    if (char_array[22] == '0') {
      checkBuzzerAndStat(45, 46, timeBuzzed, uvlightStat.ledHoursRun46, uvlightStat.led46Status);
    }
    if (char_array[23] == '0') {
      checkBuzzerAndStat(46, 47, timeBuzzed, uvlightStat.ledHoursRun47, uvlightStat.led47Status);
    }
    if (char_array[24] == '0') {
      checkBuzzerAndStat(47, 48, timeBuzzed, uvlightStat.ledHoursRun48, uvlightStat.led48Status);
    }
    if (char_array[25] == '0') {
      checkBuzzerAndStat(48, 49, timeBuzzed, uvlightStat.ledHoursRun49, uvlightStat.led49Status);
    }
    if (char_array[26] == '0') {
      checkBuzzerAndStat(49, 50, timeBuzzed, uvlightStat.ledHoursRun50, uvlightStat.led50Status);
    }
    if (char_array[27] == '0') {
      checkBuzzerAndStat(50, 51, timeBuzzed, uvlightStat.ledHoursRun51, uvlightStat.led51Status);
    }
    if (char_array[28] == '0') {
      checkBuzzerAndStat(51, 52, timeBuzzed, uvlightStat.ledHoursRun52, uvlightStat.led52Status);
    }
    if (char_array[29] == '0') {
      checkBuzzerAndStat(52, 53, timeBuzzed, uvlightStat.ledHoursRun53, uvlightStat.led53Status);
    }
    if (char_array[30] == '0') {
      checkBuzzerAndStat(53, 54, timeBuzzed, uvlightStat.ledHoursRun54, uvlightStat.led54Status);
    }
    if (char_array[31] == '0') {
      checkBuzzerAndStat(54, 55, timeBuzzed, uvlightStat.ledHoursRun55, uvlightStat.led55Status);
    }
    if (char_array[32] == '0') {
      checkBuzzerAndStat(55, 56, timeBuzzed, uvlightStat.ledHoursRun56, uvlightStat.led56Status);
    }
    if (char_array[33] == '0') {
      checkBuzzerAndStat(56, 57, timeBuzzed, uvlightStat.ledHoursRun57, uvlightStat.led57Status);
    }
    if (char_array[34] == '0') {
      checkBuzzerAndStat(57, 58, timeBuzzed, uvlightStat.ledHoursRun58, uvlightStat.led58Status);
    }
    if (char_array[35] == '0') {
      checkBuzzerAndStat(58, 59, timeBuzzed, uvlightStat.ledHoursRun59, uvlightStat.led59Status);
    }
    if (char_array[36] == '0') {
      checkBuzzerAndStat(59, 60, timeBuzzed, uvlightStat.ledHoursRun60, uvlightStat.led60Status);
    }

    if (displayCounter > 0) {
      displayCounter = displayCounter - 1;
      lastPressed = 0;
    } else {
      defaultMsg(rtc.now().unixtime());
    }
  }

  digitalWrite(constants.BUZZER_PIN, LOW);

  if (Serial3.available() > 0) {
    char bfr[100];
    memset(bfr, 0, 100);
    Serial3.readBytesUntil('\n', bfr, 50);
    Serial3.flush();
    if (bfr[0] == 'a' && bfr[37] == 'e') {
      uvlightStat.buttonPressedData = String(bfr);
      //Serial.println(uvlightStat.buttonPressedData);
    } else if (bfr[0] == 'b' && bfr[37] == 'e') {
      uvlightStat.lightData = String(bfr);
      //Serial.println(uvlightStat.lightData);
    }
  }
  delay(500);
}

void menuLogic() {
  int counter = 0;
  digitalWrite(constants.BUZZER_PIN, LOW);
  while (true) {
    // 1. First check password
    bool firstProtection = passwordProtection(1);
    //bool firstProtection = true;
    if (firstProtection) {
      Serial.println("in here");
      // 2. Show the first menu

      lcd.clear();
      lcd.setCursor(0, 0);
      String line1 = "1.Reset Light Timer";
      lcd.print(line1);

      lcd.setCursor(0, 1);
      String line2 = "2.Reset Buzzer Timer";
      lcd.print(line2);

      lcd.setCursor(0, 2);
      String line3 = "Up - 1 | Down - 2";
      lcd.print(line3);

      lcd.setCursor(0, 3);
      String line4 = "Press Cancel to exit";
      lcd.print(line4);

      int buttonPressed = 0;

      while (true) {
        if (digitalRead(constants.UP_PIN) == LOW) {
          buttonPressed = 1;
          break;
        } else if (digitalRead(constants.DOWN_PIN) == LOW) {
          buttonPressed = 2;
          break;
        } else if (digitalRead(constants.RESET_PIN) == LOW) {
          buttonPressed = 3;
          break;
        }
      }

      if (buttonPressed == 1) {
        lcd.clear();
        lcd.setCursor(0, 0);
        String line1 = "Reset Buzzer Timer hrs";
        lcd.print(line1);
        lcd.setCursor(0, 1);
        String line2 = String(uvlightStat.defaultBuzzerHours);
        lcd.print(line2);
        lcd.setCursor(0, 2);
        String line3 = "Up - 1 | Down - 2";
        lcd.print(line3);
        lcd.setCursor(0, 3);
        String line4 = "Select - Save";
        lcd.print(line4);

        int value = uvlightStat.defaultBuzzerHours;
        long newMillisUp = millis();
        long newMillisDown = millis();
        long newMillisUpdate = millis();
        long currentMillisUp = millis();
        int internalCounter = 0;

        while (true) {

          Serial.println(value);

          if (millis() - newMillisUp > 200) {
            if (digitalRead(constants.DOWN_PIN) == LOW) {
              internalCounter = 0;
              if (value <= 47) {
                value = value + 1;
              }
            }
            newMillisUp = millis();
          }

          if (millis() - newMillisDown > 200) {
            if (digitalRead(constants.UP_PIN) == LOW) {
              internalCounter = 0;
              if (value >= 2) {
                if (value == 0) {
                  value = 1;
                } else {
                  value = value - 1;
                }
              }
            }
            newMillisDown = millis();
          }

          if (millis() - newMillisUpdate > 200) {
            for (int i = 0; i <= 19; i++) {
              lcd.setCursor(i, 1);
              lcd.print(" ");
              delay(2);
            }
            lcd.setCursor(0, 1);
            lcd.print(String(value));
            Serial.println(String(value));
            newMillisUpdate = millis();
          }



          if (digitalRead(constants.MENU_PIN) == LOW) {
            if (value == 0) {
              value = 1;
            }
            internalCounter = 0;
            lcd.clear();
            lcd.setCursor(0, 0);
            uvlightStat.defaultBuzzerHours = value;
            lcd.print("Settings saved.");
            lcd.setCursor(0, 1);
            String txt = "Buzzer hrs:" + String(value);
            lcd.print(txt);
            delay(3000);
            startingMsg();
            return;
          }

          //            internalCounter++;
          //            if(internalCounter>100){
          //              startingMsg();
          //              return;
          //            }
        }
      }

      if (buttonPressed == 2) {
        lcd.clear();
        lcd.setCursor(0, 0);
        String line1 = "Reset Light Timer hrs";
        lcd.print(line1);
        lcd.setCursor(0, 1);
        String line2 = String(uvlightStat.defaultLightHours);
        lcd.print(line2);
        lcd.setCursor(0, 2);
        String line3 = "Up - 1 | Down - 2";
        lcd.print(line3);
        lcd.setCursor(0, 3);
        String line4 = "Select - Save";
        lcd.print(line4);

        int value = uvlightStat.defaultLightHours;
        long newMillisUp = millis();
        long newMillisDown = millis();
        long newMillisUpdate = millis();
        long currentMillisUp = millis();
        int internalCounter = 0;
        while (true) {

          if (millis() - newMillisUp > 50) {
            if (digitalRead(constants.DOWN_PIN) == LOW) {
              internalCounter = 0;
              if (value <= 8900) {
                value = value + 100;
              }
            }
            newMillisUp = millis();
          }

          if (millis() - newMillisDown > 50) {
            if (digitalRead(constants.UP_PIN) == LOW) {
              internalCounter = 0;
              if (value >= 200) {
                if (value == 0) {
                  value = 100;
                } else {
                  value = value - 100;
                }
              }
            }
            newMillisDown = millis();
          }

          if (millis() - newMillisUpdate > 50) {
            for (int i = 0; i <= 19; i++) {
              lcd.setCursor(i, 1);
              lcd.print(" ");
              delay(2);
            }
            lcd.setCursor(0, 1);
            lcd.print(String(value));
            Serial.println(String(value));
            newMillisUpdate = millis();
          }

          if (digitalRead(constants.MENU_PIN) == LOW) {

            if (value == 0) {
              value = 100;
            }
            internalCounter = 0;
            lcd.clear();
            lcd.setCursor(0, 0);
            uvlightStat.defaultLightHours = value;
            lcd.print("Settings saved.");
            lcd.setCursor(0, 1);
            String txt = "Light hrs:" + String(value);
            lcd.print(txt);
            delay(3000);
            startingMsg();
            return;
          }

          //            internalCounter++;
          //            if(internalCounter>100){
          //              startingMsg();
          //              return;
          //            }
        }
      }
      if (buttonPressed == 3) {
        startingMsg();
        return;
      }

      //        counter++;
      //        if(counter>200){
      //          startingMsg();
      //          return;
      //        }

    } else {
      startingMsg();
      return;
    }
  }
}

uint8_t readAnalogIn(uint8_t fc, uint16_t address, uint16_t length)
{
  if (address > input_pins_size  || (address + length) > input_pins_size )
  {
    return STATUS_ILLEGAL_DATA_ADDRESS;
  }
  for (int i = 0; i < length; i++)
  {
    slave.writeRegisterToBuffer(i, au16data[i]);
  }

  return STATUS_OK;
}
