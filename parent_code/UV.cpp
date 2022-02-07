#include <Arduino.h>
#include "UV.h"

UV::UV() {
}

String UV::putStatusToSDCard()
{
  String output = "1=" + String(ledHoursRun1) + "\r\n";
  output = output + "2=" + String(ledHoursRun2) + "\r\n";
  output = output + "3=" + String(ledHoursRun3) + "\r\n";
  output = output + "4=" + String(ledHoursRun4) + "\r\n";
  output = output + "5=" + String(ledHoursRun5) + "\r\n";
  output = output + "6=" + String(ledHoursRun6) + "\r\n";
  output = output + "7=" + String(ledHoursRun7) + "\r\n";
  output = output + "8=" + String(ledHoursRun8) + "\r\n";
  output = output + "9=" + String(ledHoursRun9) + "\r\n";
  output = output + "10=" + String(ledHoursRun10) + "\r\n";
  output = output + "11=" + String(ledHoursRun11) + "\r\n";
  output = output + "12=" + String(ledHoursRun12) + "\r\n";
  output = output + "13=" + String(ledHoursRun13) + "\r\n";
  output = output + "14=" + String(ledHoursRun14) + "\r\n";
  output = output + "15=" + String(ledHoursRun15) + "\r\n";
  output = output + "16=" + String(ledHoursRun16) + "\r\n";
  output = output + "17=" + String(ledHoursRun17) + "\r\n";
  output = output + "18=" + String(ledHoursRun18) + "\r\n";
  output = output + "19=" + String(ledHoursRun19) + "\r\n";
  output = output + "20=" + String(ledHoursRun20) + "\r\n";
  output = output + "21=" + String(ledHoursRun21) + "\r\n";
  output = output + "22=" + String(ledHoursRun22) + "\r\n";
  output = output + "23=" + String(ledHoursRun23) + "\r\n";
  output = output + "24=" + String(ledHoursRun24) + "\r\n";

  output = output + "25=" + String(ledlastBuzzed1) + "\r\n";
  output = output + "26=" + String(ledlastBuzzed2) + "\r\n";
  output = output + "27=" + String(ledlastBuzzed3) + "\r\n";
  output = output + "28=" + String(ledlastBuzzed4) + "\r\n";
  output = output + "29=" + String(ledlastBuzzed5) + "\r\n";
  output = output + "30=" + String(ledlastBuzzed6) + "\r\n";
  output = output + "31=" + String(ledlastBuzzed7) + "\r\n";
  output = output + "32=" + String(ledlastBuzzed8) + "\r\n";
  output = output + "33=" + String(ledlastBuzzed9) + "\r\n";
  output = output + "34=" + String(ledlastBuzzed10) + "\r\n";
  output = output + "35=" + String(ledlastBuzzed11) + "\r\n";
  output = output + "36=" + String(ledlastBuzzed12) + "\r\n";
  output = output + "37=" + String(ledlastBuzzed13) + "\r\n";
  output = output + "38=" + String(ledlastBuzzed14) + "\r\n";
  output = output + "39=" + String(ledlastBuzzed15) + "\r\n";
  output = output + "40=" + String(ledlastBuzzed16) + "\r\n";
  output = output + "41=" + String(ledlastBuzzed17) + "\r\n";
  output = output + "42=" + String(ledlastBuzzed18) + "\r\n";
  output = output + "43=" + String(ledlastBuzzed19) + "\r\n";
  output = output + "44=" + String(ledlastBuzzed20) + "\r\n";
  output = output + "45=" + String(ledlastBuzzed21) + "\r\n";
  output = output + "46=" + String(ledlastBuzzed22) + "\r\n";
  output = output + "47=" + String(ledlastBuzzed23) + "\r\n";
  output = output + "48=" + String(ledlastBuzzed24) + "\r\n";

  output = output + "49=" + String(defaultLightHours) + "\r\n";
  output = output + "50=" + String(defaultBuzzerHours) + "\r\n";

  Serial.print("LED output is: ");
  Serial.println(output);

  return output;
}

String UV::putStatusToSDCard1()
{
  String output = "51=" + String(ledHoursRun25) + "\r\n";
  output = output + "52=" + String(ledHoursRun26) + "\r\n";
  output = output + "53=" + String(ledHoursRun27) + "\r\n";
  output = output + "54=" + String(ledHoursRun28) + "\r\n";
  output = output + "55=" + String(ledHoursRun29) + "\r\n";
  output = output + "56=" + String(ledHoursRun30) + "\r\n";
  output = output + "57=" + String(ledHoursRun31) + "\r\n";
  output = output + "58=" + String(ledHoursRun32) + "\r\n";
  output = output + "59=" + String(ledHoursRun33) + "\r\n";
  output = output + "60=" + String(ledHoursRun34) + "\r\n";
  output = output + "61=" + String(ledHoursRun35) + "\r\n";
  output = output + "62=" + String(ledHoursRun36) + "\r\n";
  output = output + "63=" + String(ledHoursRun37) + "\r\n";
  output = output + "64=" + String(ledHoursRun38) + "\r\n";
  output = output + "65=" + String(ledHoursRun39) + "\r\n";
  output = output + "66=" + String(ledHoursRun40) + "\r\n";
  output = output + "67=" + String(ledHoursRun41) + "\r\n";
  output = output + "68=" + String(ledHoursRun42) + "\r\n";
  output = output + "69=" + String(ledHoursRun43) + "\r\n";
  output = output + "70=" + String(ledHoursRun44) + "\r\n";
  output = output + "71=" + String(ledHoursRun45) + "\r\n";
  output = output + "72=" + String(ledHoursRun46) + "\r\n";
  output = output + "73=" + String(ledHoursRun47) + "\r\n";
  output = output + "74=" + String(ledHoursRun48) + "\r\n";
  output = output + "75=" + String(ledHoursRun49) + "\r\n";
  output = output + "76=" + String(ledHoursRun50) + "\r\n";
  output = output + "77=" + String(ledHoursRun51) + "\r\n";
  output = output + "78=" + String(ledHoursRun52) + "\r\n";
  output = output + "79=" + String(ledHoursRun53) + "\r\n";
  output = output + "80=" + String(ledHoursRun54) + "\r\n";
  output = output + "81=" + String(ledHoursRun55) + "\r\n";
  output = output + "82=" + String(ledHoursRun56) + "\r\n";
  output = output + "83=" + String(ledHoursRun57) + "\r\n";
  output = output + "84=" + String(ledHoursRun58) + "\r\n";
  output = output + "85=" + String(ledHoursRun59) + "\r\n";
  output = output + "86=" + String(ledHoursRun60) + "\r\n";
  
  output = output + "87=" + String(ledlastBuzzed25) + "\r\n";
  output = output + "88=" + String(ledlastBuzzed26) + "\r\n";
  output = output + "89=" + String(ledlastBuzzed27) + "\r\n";
  output = output + "90=" + String(ledlastBuzzed28) + "\r\n";
  output = output + "91=" + String(ledlastBuzzed29) + "\r\n";
  output = output + "92=" + String(ledlastBuzzed30) + "\r\n";
  output = output + "93=" + String(ledlastBuzzed31) + "\r\n";
  output = output + "94=" + String(ledlastBuzzed32) + "\r\n";
  output = output + "95=" + String(ledlastBuzzed33) + "\r\n";
  output = output + "96=" + String(ledlastBuzzed34) + "\r\n";
  output = output + "97=" + String(ledlastBuzzed35) + "\r\n";
  output = output + "98=" + String(ledlastBuzzed36) + "\r\n";
  output = output + "99=" + String(ledlastBuzzed37) + "\r\n";
  output = output + "100=" + String(ledlastBuzzed38) + "\r\n";
  output = output + "101=" + String(ledlastBuzzed39) + "\r\n";
  output = output + "102=" + String(ledlastBuzzed40) + "\r\n";
  output = output + "103=" + String(ledlastBuzzed41) + "\r\n";
  output = output + "104=" + String(ledlastBuzzed42) + "\r\n";
  output = output + "105=" + String(ledlastBuzzed43) + "\r\n";
  output = output + "106=" + String(ledlastBuzzed44) + "\r\n";
  output = output + "107=" + String(ledlastBuzzed45) + "\r\n";
  output = output + "108=" + String(ledlastBuzzed46) + "\r\n";
  output = output + "109=" + String(ledlastBuzzed47) + "\r\n";
  output = output + "110=" + String(ledlastBuzzed48) + "\r\n";
  output = output + "111=" + String(ledlastBuzzed49) + "\r\n";
  output = output + "112=" + String(ledlastBuzzed50) + "\r\n";
  output = output + "113=" + String(ledlastBuzzed51) + "\r\n";
  output = output + "114=" + String(ledlastBuzzed52) + "\r\n";
  output = output + "115=" + String(ledlastBuzzed53) + "\r\n";
  output = output + "116=" + String(ledlastBuzzed54) + "\r\n";
  output = output + "117=" + String(ledlastBuzzed55) + "\r\n";
  output = output + "118=" + String(ledlastBuzzed56) + "\r\n";
  output = output + "119=" + String(ledlastBuzzed57) + "\r\n";
  output = output + "120=" + String(ledlastBuzzed58) + "\r\n";
  output = output + "121=" + String(ledlastBuzzed59) + "\r\n";
  output = output + "122=" + String(ledlastBuzzed60) + "\r\n";
  
  Serial.print("LED output is: ");
  Serial.println(output);

  return output;
}

bool UV::muteStatus(long lightIdentifierValue, int lightNum, long currentEpooch) {
  if (lightIdentifierValue == 0) {
    erroredLight[lightNum] = 1;
            //Serial.print("erroredLight ");
            //Serial.print(lightNum);
            //Serial.print(" is: ");
            ////Serial.println(erroredLight[lightNum]);

    return true;
  } else {
    long currentDifference = currentEpooch - lightIdentifierValue;
            //Serial.print("UV : ");
            //Serial.print(lightNum);
            //Serial.print(" ||currentEpooch: ");
            //Serial.print(currentEpooch);
            //Serial.print(" ||currentDifference: ");
            //Serial.print(currentDifference);
            //Serial.print(" || ledlastBuzzed");
            //Serial.print(lightNum);
            //Serial.print(": ");
            //Serial.print(lightIdentifierValue);
            //Serial.print(" || defaultLightHours: ");
            //Serial.print(defaultLightHours*60*60);
            //Serial.print(" || defaultBuzzerHours: ");
            ////Serial.println(defaultBuzzerHours*60*60);

    if (currentDifference > (defaultBuzzerHours * 60 * 60)) {
      ////Serial.print();
      erroredLight[lightNum] = 1;
      return true;
    }
  }
  return false;
}

String UV::errorStatusToDisplay(long currentEpooch) {
  String output = "Chk:";
  //  String out = String(ledHoursRun1) + "," + String(ledHoursRun2) + "," + String(ledHoursRun3) +"," +String(ledHoursRun4) + "," + String(ledHoursRun5) +"," + String(ledHoursRun6) + "," + String(ledHoursRun7) +"," + String(ledHoursRun8) + "," + String(ledHoursRun9) +
  //  "," + String(ledHoursRun10) + "," + String(ledHoursRun11) + "," + String(ledHoursRun12) +"," + String(ledHoursRun12) + "," + String(ledHoursRun13) +"," + String(ledHoursRun14) + "," + String(ledHoursRun15) +"," + String(ledHoursRun16) + "," + String(ledHoursRun17) +
  //  "," + String(ledHoursRun18) + "," + String(ledHoursRun19) +"," + String(ledHoursRun20) + "," + String(ledHoursRun21) +"," + String(ledHoursRun22) + "," + String(ledHoursRun23) +"," + String(ledHoursRun24);
  //  ////Serial.println(out);

  float voltage1 = analogRead(constants.UV_Light1_Input_PIN) * (5.0 / 1023.0);
  float voltage2 = analogRead(constants.UV_Light2_Input_PIN) * (5.0 / 1023.0);
  float voltage3 = analogRead(constants.UV_Light3_Input_PIN) * (5.0 / 1023.0);
  float voltage4 = analogRead(constants.UV_Light4_Input_PIN) * (5.0 / 1023.0);
  float voltage5 = analogRead(constants.UV_Light5_Input_PIN) * (5.0 / 1023.0);
  float voltage6 = analogRead(constants.UV_Light6_Input_PIN) * (5.0 / 1023.0);
  float voltage7 = analogRead(constants.UV_Light7_Input_PIN) * (5.0 / 1023.0);
  float voltage8 = analogRead(constants.UV_Light8_Input_PIN) * (5.0 / 1023.0);


  if (ledHoursRun1 >= (defaultLightHours * 60) || voltage1 > 2.5) {
    bool resStat = muteStatus(ledlastBuzzed1, 0, currentEpooch);
    if (resStat) {
      output = output + String(1) + ",";
    } else {
      erroredLight[0] = 0;
    }
  } else {
    erroredLight[0] = 0;
    ledlastBuzzed1 = 0;
  }
  if (ledHoursRun2 >= (defaultLightHours * 60) || voltage2 > 2.5) {
    bool resStat = muteStatus(ledlastBuzzed2, 1, currentEpooch);
    if (resStat) {
      output = output + String(2) + ",";
    } else {
      erroredLight[1] = 0;
    }
  } else {
    erroredLight[1] = 0;
    ledlastBuzzed2 = 0;
  }
  if (ledHoursRun3 >= (defaultLightHours * 60) || voltage3 > 2.5) {
    bool resStat = muteStatus(ledlastBuzzed3, 2, currentEpooch);
    if (resStat) {
      output = output + String(3) + ",";
    } else {
      erroredLight[2] = 0;
    }
  } else {
    erroredLight[2] = 0;
    ledlastBuzzed3 = 0;
  }
  if (ledHoursRun4 >= (defaultLightHours * 60) || voltage4 > 2.5) {
    bool resStat = muteStatus(ledlastBuzzed4, 3, currentEpooch);
    if (resStat) {
      output = output + String(4) + ",";
    } else {
      erroredLight[3] = 0;
    }
  } else {
    erroredLight[3] = 0;
    ledlastBuzzed4 = 0;
  }
  if (ledHoursRun5 >= (defaultLightHours * 60) || voltage5 > 2.5) {
    bool resStat = muteStatus(ledlastBuzzed5, 4, currentEpooch);
    if (resStat) {
      output = output + String(5) + ",";
    } else {
      erroredLight[4] = 0;
    }
  } else {
    erroredLight[4] = 0;
    ledlastBuzzed5 = 0;
  }
  if (ledHoursRun6 >= (defaultLightHours * 60) || voltage6 > 2.5) {
    bool resStat = muteStatus(ledlastBuzzed6, 5, currentEpooch);
    if (resStat) {
      output = output + String(6) + ",";
    } else {
      erroredLight[5] = 0;
    }
  } else {
    erroredLight[5] = 0;
    ledlastBuzzed6 = 0;
  }
  if (ledHoursRun7 >= (defaultLightHours * 60) || voltage7 > 2.5) {
    bool resStat = muteStatus(ledlastBuzzed7, 6, currentEpooch);
    if (resStat) {
      output = output + String(7) + ",";
    } else {
      erroredLight[6] = 0;
    }
  } else {
    erroredLight[6] = 0;
    ledlastBuzzed7 = 0;
  }
  if (ledHoursRun8 >= (defaultLightHours * 60) || voltage8 > 2.5) {
    bool resStat = muteStatus(ledlastBuzzed8, 7, currentEpooch);
    if (resStat) {
      output = output + String(8) + ",";
    } else {
      erroredLight[7] = 0;
    }
  } else {
    erroredLight[7] = 0;
    ledlastBuzzed8 = 0;
  }
  if (ledHoursRun9 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light9_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed9, 8, currentEpooch);
    if (resStat) {
      output = output + String(9) + ",";
    } else {
      erroredLight[8] = 0;
    }
  } else {
    erroredLight[8] = 0;
    ledlastBuzzed9 = 0;
  }
  if (ledHoursRun10 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light10_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed10, 9, currentEpooch);
    if (resStat) {
      output = output + String(10) + ",";
    } else {
      erroredLight[9] = 0;
    }
  } else {
    erroredLight[9] = 0;
    ledlastBuzzed10 = 0;
  }
  if (ledHoursRun11 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light11_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed11, 10, currentEpooch);
    if (resStat) {
      output = output + String(11) + ",";
    } else {
      erroredLight[10] = 0;
    }
  } else {
    erroredLight[10] = 0;
    ledlastBuzzed11 = 0;
  }
  if (ledHoursRun12 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light12_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed12, 11, currentEpooch);
    if (resStat) {
      output = output + String(12) + ",";
    } else {
      erroredLight[11] = 0;
    }
  } else {
    erroredLight[11] = 0;
    ledlastBuzzed12 = 0;
  }
  if (ledHoursRun13 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light13_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed13, 12, currentEpooch);
    if (resStat) {
      output = output + String(13) + ",";
    } else {
      erroredLight[12] = 0;
    }
  } else {
    erroredLight[12] = 0;
    ledlastBuzzed13 = 0;
  }
  if (ledHoursRun14 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light14_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed14, 13, currentEpooch);
    if (resStat) {
      output = output + String(14) + ",";
    } else {
      erroredLight[13] = 0;
    }
  } else {
    erroredLight[13] = 0;
    ledlastBuzzed14 = 0;
  }
  if (ledHoursRun15 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light15_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed15, 14, currentEpooch);
    if (resStat) {
      output = output + String(15) + ",";
    } else {
      erroredLight[14] = 0;
    }
  } else {
    erroredLight[14] = 0;
    ledlastBuzzed15 = 0;
  }
  if (ledHoursRun16 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light16_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed16, 15, currentEpooch);
    if (resStat) {
      output = output + String(16) + ",";
    } else {
      erroredLight[15] = 0;
    }
  } else {
    erroredLight[15] = 0;
    ledlastBuzzed16 = 0;
  }
  if (ledHoursRun17 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light17_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed17, 16, currentEpooch);
    if (resStat) {
      output = output + String(17) + ",";
    } else {
      erroredLight[16] = 0;
    }
  } else {
    erroredLight[16] = 0;
    ledlastBuzzed17 = 0;
  }
  if (ledHoursRun18 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light18_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed18, 17, currentEpooch);
    if (resStat) {
      output = output + String(18) + ",";
    } else {
      erroredLight[17] = 0;
    }
  } else {
    erroredLight[17] = 0;
    ledlastBuzzed18 = 0;
  }
  if (ledHoursRun19 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light19_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed19, 18, currentEpooch);
    if (resStat) {
      output = output + String(19) + ",";
    } else {
      erroredLight[18] = 0;
    }
  } else {
    erroredLight[18] = 0;
    ledlastBuzzed19 = 0;
  }
  if (ledHoursRun20 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light20_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed20, 19, currentEpooch);
    if (resStat) {
      output = output + String(20) + ",";
    } else {
      erroredLight[19] = 0;
    }
  } else {
    erroredLight[19] = 0;
    ledlastBuzzed20 = 0;
  }
  if (ledHoursRun21 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light21_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed21, 20, currentEpooch);
    if (resStat) {
      output = output + String(21) + ",";
    } else {
      erroredLight[20] = 0;
    }
  } else {
    erroredLight[20] = 0;
    ledlastBuzzed21 = 0;
  }
  if (ledHoursRun22 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light22_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed22, 21, currentEpooch);
    if (resStat) {
      output = output + String(22) + ",";
    } else {
      erroredLight[21] = 0;
    }
  } else {
    erroredLight[21] = 0;
    ledlastBuzzed22 = 0;
  }
  if (ledHoursRun23 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light23_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed23, 22, currentEpooch);
    if (resStat) {
      output = output + String(23) + ",";
    } else {
      erroredLight[22] = 0;
    }
  } else {
    erroredLight[22] = 0;
    ledlastBuzzed23 = 0;
  }
  if (ledHoursRun24 >= (defaultLightHours * 60) || digitalRead(constants.UV_Light24_Input_PIN) == HIGH) {
    bool resStat = muteStatus(ledlastBuzzed24, 23, currentEpooch);
    if (resStat) {
      output = output + String(24) + ",";
    } else {
      erroredLight[23] = 0;
    }
  } else {
    erroredLight[23] = 0;
    ledlastBuzzed24 = 0;
  }

  char char_array[lightData.length() + 1];
  lightData.toCharArray(char_array, lightData.length() + 1);

  if (ledHoursRun25 >= (defaultLightHours * 60) || lightData[1] == '1') {
    bool resStat = muteStatus(ledlastBuzzed25, 24, currentEpooch);
    if (resStat) {
      output = output + String(25) + ",";
    } else {
      erroredLight[24] = 0;
    }
  } else {
    erroredLight[24] = 0;
    ledlastBuzzed25 = 0;
  }
  if (ledHoursRun26 >= (defaultLightHours * 60) || lightData[2] == '1') {
    bool resStat = muteStatus(ledlastBuzzed26, 25, currentEpooch);
    if (resStat) {
      output = output + String(26) + ",";
    } else {
      erroredLight[25] = 0;
    }
  } else {
    erroredLight[25] = 0;
    ledlastBuzzed26 = 0;
  }
  if (ledHoursRun27 >= (defaultLightHours * 60) || lightData[3] == '1') {
    bool resStat = muteStatus(ledlastBuzzed27, 26, currentEpooch);
    if (resStat) {
      output = output + String(27) + ",";
    } else {
      erroredLight[26] = 0;
    }
  } else {
    erroredLight[26] = 0;
    ledlastBuzzed27 = 0;
  }
  if (ledHoursRun28 >= (defaultLightHours * 60) || lightData[4] == '1') {
    bool resStat = muteStatus(ledlastBuzzed28, 27, currentEpooch);
    if (resStat) {
      output = output + String(28) + ",";
    } else {
      erroredLight[27] = 0;
    }
  } else {
    erroredLight[27] = 0;
    ledlastBuzzed28 = 0;
  }
  if (ledHoursRun29 >= (defaultLightHours * 60) || lightData[5] == '1') {
    bool resStat = muteStatus(ledlastBuzzed29, 28, currentEpooch);
    if (resStat) {
      output = output + String(29) + ",";
    } else {
      erroredLight[28] = 0;
    }
  } else {
    erroredLight[28] = 0;
    ledlastBuzzed29 = 0;
  }
  if (ledHoursRun30 >= (defaultLightHours * 60) || lightData[6] == '1') {
    bool resStat = muteStatus(ledlastBuzzed30, 29, currentEpooch);
    if (resStat) {
      output = output + String(30) + ",";
    } else {
      erroredLight[29] = 0;
    }
  } else {
    erroredLight[29] = 0;
    ledlastBuzzed30 = 0;
  }
  if (ledHoursRun31 >= (defaultLightHours * 60) || lightData[7] == '1') {
    bool resStat = muteStatus(ledlastBuzzed31, 30, currentEpooch);
    if (resStat) {
      output = output + String(31) + ",";
    } else {
      erroredLight[30] = 0;
    }
  } else {
    erroredLight[30] = 0;
    ledlastBuzzed31 = 0;
  }
  if (ledHoursRun32 >= (defaultLightHours * 60) || lightData[8] == '1') {
    bool resStat = muteStatus(ledlastBuzzed32, 31, currentEpooch);
    if (resStat) {
      output = output + String(32) + ",";
    } else {
      erroredLight[31] = 0;
    }
  } else {
    erroredLight[31] = 0;
    ledlastBuzzed32 = 0;
  }
  if (ledHoursRun33 >= (defaultLightHours * 60) || lightData[9] == '1') {
    bool resStat = muteStatus(ledlastBuzzed33, 32, currentEpooch);
    if (resStat) {
      output = output + String(33) + ",";
    } else {
      erroredLight[32] = 0;
    }
  } else {
    erroredLight[32] = 0;
    ledlastBuzzed33 = 0;
  }
  if (ledHoursRun34 >= (defaultLightHours * 60) || lightData[10] == '1') {
    bool resStat = muteStatus(ledlastBuzzed34, 33, currentEpooch);
    if (resStat) {
      output = output + String(34) + ",";
    } else {
      erroredLight[33] = 0;
    }
  } else {
    erroredLight[33] = 0;
    ledlastBuzzed34 = 0;
  }
  if (ledHoursRun35 >= (defaultLightHours * 60) || lightData[11] == '1') {
    bool resStat = muteStatus(ledlastBuzzed35, 34, currentEpooch);
    if (resStat) {
      output = output + String(35) + ",";
    } else {
      erroredLight[34] = 0;
    }
  } else {
    erroredLight[34] = 0;
    ledlastBuzzed35 = 0;
  }
  if (ledHoursRun36 >= (defaultLightHours * 60) || lightData[12] == '1') {
    bool resStat = muteStatus(ledlastBuzzed36, 35, currentEpooch);
    if (resStat) {
      output = output + String(36) + ",";
    } else {
      erroredLight[35] = 0;
    }
  } else {
    erroredLight[35] = 0;
    ledlastBuzzed36 = 0;
  }
  if (ledHoursRun37 >= (defaultLightHours * 60) || lightData[13] == '1') {
    bool resStat = muteStatus(ledlastBuzzed37, 36, currentEpooch);
    if (resStat) {
      output = output + String(37) + ",";
    } else {
      erroredLight[36] = 0;
    }
  } else {
    erroredLight[36] = 0;
    ledlastBuzzed37 = 0;
  }
  if (ledHoursRun38 >= (defaultLightHours * 60) || lightData[14] == '1') {
    bool resStat = muteStatus(ledlastBuzzed38, 37, currentEpooch);
    if (resStat) {
      output = output + String(38) + ",";
    } else {
      erroredLight[37] = 0;
    }
  } else {
    erroredLight[37] = 0;
    ledlastBuzzed38 = 0;
  }
  if (ledHoursRun39 >= (defaultLightHours * 60) || lightData[15] == '1') {
    bool resStat = muteStatus(ledlastBuzzed39, 38, currentEpooch);
    if (resStat) {
      output = output + String(39) + ",";
    } else {
      erroredLight[38] = 0;
    }
  } else {
    erroredLight[38] = 0;
    ledlastBuzzed39 = 0;
  }
  if (ledHoursRun40 >= (defaultLightHours * 60) || lightData[16] == '1') {
    bool resStat = muteStatus(ledlastBuzzed40, 39, currentEpooch);
    if (resStat) {
      output = output + String(40) + ",";
    } else {
      erroredLight[39] = 0;
    }
  } else {
    erroredLight[39] = 0;
    ledlastBuzzed40 = 0;
  }
  if (ledHoursRun41 >= (defaultLightHours * 60) || lightData[17] == '1') {
    bool resStat = muteStatus(ledlastBuzzed41, 40, currentEpooch);
    if (resStat) {
      output = output + String(41) + ",";
    } else {
      erroredLight[40] = 0;
    }
  } else {
    erroredLight[40] = 0;
    ledlastBuzzed41 = 0;
  }
  if (ledHoursRun42 >= (defaultLightHours * 60) || lightData[18] == '1') {
    bool resStat = muteStatus(ledlastBuzzed42, 41, currentEpooch);
    if (resStat) {
      output = output + String(42) + ",";
    } else {
      erroredLight[41] = 0;
    }
  } else {
    erroredLight[41] = 0;
    ledlastBuzzed42 = 0;
  }
  if (ledHoursRun43 >= (defaultLightHours * 60) || lightData[19] == '1') {
    bool resStat = muteStatus(ledlastBuzzed43, 42, currentEpooch);
    if (resStat) {
      output = output + String(43) + ",";
    } else {
      erroredLight[42] = 0;
    }
  } else {
    erroredLight[42] = 0;
    ledlastBuzzed43 = 0;
  }
  if (ledHoursRun44 >= (defaultLightHours * 60) || lightData[20] == '1') {
    bool resStat = muteStatus(ledlastBuzzed44, 43, currentEpooch);
    if (resStat) {
      output = output + String(44) + ",";
    } else {
      erroredLight[43] = 0;
    }
  } else {
    erroredLight[43] = 0;
    ledlastBuzzed44 = 0;
  }
  if (ledHoursRun45 >= (defaultLightHours * 60) || lightData[21] == '1') {
    bool resStat = muteStatus(ledlastBuzzed45, 44, currentEpooch);
    if (resStat) {
      output = output + String(45) + ",";
    } else {
      erroredLight[44] = 0;
    }
  } else {
    erroredLight[44] = 0;
    ledlastBuzzed45 = 0;
  }
  if (ledHoursRun46 >= (defaultLightHours * 60) || lightData[22] == '1') {
    bool resStat = muteStatus(ledlastBuzzed46, 45, currentEpooch);
    if (resStat) {
      output = output + String(46) + ",";
    } else {
      erroredLight[45] = 0;
    }
  } else {
    erroredLight[45] = 0;
    ledlastBuzzed46 = 0;
  }
  if (ledHoursRun47 >= (defaultLightHours * 60) || lightData[23] == '1') {
    bool resStat = muteStatus(ledlastBuzzed47, 46, currentEpooch);
    if (resStat) {
      output = output + String(47) + ",";
    } else {
      erroredLight[46] = 0;
    }
  } else {
    erroredLight[46] = 0;
    ledlastBuzzed47 = 0;
  }
  if (ledHoursRun48 >= (defaultLightHours * 60) || lightData[24] == '1') {
    bool resStat = muteStatus(ledlastBuzzed48, 47, currentEpooch);
    if (resStat) {
      output = output + String(48) + ",";
    } else {
      erroredLight[47] = 0;
    }
  } else {
    erroredLight[47] = 0;
    ledlastBuzzed48 = 0;
  }
  if (ledHoursRun49 >= (defaultLightHours * 60) || lightData[25] == '1') {
    bool resStat = muteStatus(ledlastBuzzed49, 48, currentEpooch);
    if (resStat) {
      output = output + String(49) + ",";
    } else {
      erroredLight[48] = 0;
    }
  } else {
    erroredLight[48] = 0;
    ledlastBuzzed49 = 0;
  }
  if (ledHoursRun50 >= (defaultLightHours * 60) || lightData[26] == '1') {
    bool resStat = muteStatus(ledlastBuzzed50, 49, currentEpooch);
    if (resStat) {
      output = output + String(50) + ",";
    } else {
      erroredLight[49] = 0;
    }
  } else {
    erroredLight[49] = 0;
    ledlastBuzzed50 = 0;
  }
  if (ledHoursRun51 >= (defaultLightHours * 60) || lightData[27] == '1') {
    bool resStat = muteStatus(ledlastBuzzed51, 50, currentEpooch);
    if (resStat) {
      output = output + String(51) + ",";
    } else {
      erroredLight[50] = 0;
    }
  } else {
    erroredLight[50] = 0;
    ledlastBuzzed51 = 0;
  }
  if (ledHoursRun52 >= (defaultLightHours * 60) || lightData[28] == '1') {
    bool resStat = muteStatus(ledlastBuzzed52, 51, currentEpooch);
    if (resStat) {
      output = output + String(52) + ",";
    } else {
      erroredLight[51] = 0;
    }
  } else {
    erroredLight[51] = 0;
    ledlastBuzzed52 = 0;
  }
  if (ledHoursRun53 >= (defaultLightHours * 60) || lightData[29] == '1') {
    bool resStat = muteStatus(ledlastBuzzed53, 52, currentEpooch);
    if (resStat) {
      output = output + String(53) + ",";
    } else {
      erroredLight[52] = 0;
    }
  } else {
    erroredLight[52] = 0;
    ledlastBuzzed53 = 0;
  }
  if (ledHoursRun54 >= (defaultLightHours * 60) || lightData[30] == '1') {
    bool resStat = muteStatus(ledlastBuzzed54, 53, currentEpooch);
    if (resStat) {
      output = output + String(54) + ",";
    } else {
      erroredLight[53] = 0;
    }
  } else {
    erroredLight[53] = 0;
    ledlastBuzzed54 = 0;
  }
  if (ledHoursRun55 >= (defaultLightHours * 60) || lightData[31] == '1') {
    bool resStat = muteStatus(ledlastBuzzed55, 54, currentEpooch);
    if (resStat) {
      output = output + String(55) + ",";
    } else {
      erroredLight[54] = 0;
    }
  } else {
    erroredLight[54] = 0;
    ledlastBuzzed55 = 0;
  }
  if (ledHoursRun56 >= (defaultLightHours * 60) || lightData[32] == '1') {
    bool resStat = muteStatus(ledlastBuzzed56, 55, currentEpooch);
    if (resStat) {
      output = output + String(56) + ",";
    } else {
      erroredLight[55] = 0;
    }
  } else {
    erroredLight[55] = 0;
    ledlastBuzzed56 = 0;
  }
  if (ledHoursRun57 >= (defaultLightHours * 60) || lightData[33] == '1') {
    bool resStat = muteStatus(ledlastBuzzed57, 56, currentEpooch);
    if (resStat) {
      output = output + String(57) + ",";
    } else {
      erroredLight[56] = 0;
    }
  } else {
    erroredLight[56] = 0;
    ledlastBuzzed57 = 0;
  }
  if (ledHoursRun58 >= (defaultLightHours * 60) || lightData[34] == '1') {
    bool resStat = muteStatus(ledlastBuzzed58, 57, currentEpooch);
    if (resStat) {
      output = output + String(58) + ",";
    } else {
      erroredLight[57] = 0;
    }
  } else {
    erroredLight[57] = 0;
    ledlastBuzzed58 = 0;
  }
  if (ledHoursRun59 >= (defaultLightHours * 60) || lightData[35] == '1') {
    bool resStat = muteStatus(ledlastBuzzed59, 58, currentEpooch);
    if (resStat) {
      output = output + String(59) + ",";
    } else {
      erroredLight[58] = 0;
    }
  } else {
    erroredLight[58] = 0;
    ledlastBuzzed59 = 0;
  }
  if (ledHoursRun60 >= (defaultLightHours * 60) || lightData[36] == '1') {
    bool resStat = muteStatus(ledlastBuzzed60, 59, currentEpooch);
    if (resStat) {
      output = output + String(60) + ",";
    } else {
      erroredLight[59] = 0;
    }
  } else {
    erroredLight[59] = 0;
    ledlastBuzzed60 = 0;
  }

  //////Serial.println(output);
  return output;
}

bool UV::chooseButtonPressed(int buttonToBePressed) {
  int pressedButton = 0;
  int counter = 0;
  while (true) {
    String buttonPressedData1 = "";
    
    if (Serial3.available() > 0) {
      char bfr[100];
      memset(bfr, 0, 100);
      Serial3.readBytesUntil('\n', bfr, 50);
      Serial3.flush();
      if (bfr[0] == 'a' && bfr[37] == 'e') {
        buttonPressedData1 = String(bfr);
      }
    }

    if (pressedButton > 0) {
      break;
    }

    if (counter > 50) {
      pressedButton = 0;
      break;
    }

    float voltage1 = analogRead(constants.UV_Light1_Input_BUTTON) * (5.0 / 1023.0);
    float voltage2 = analogRead(constants.UV_Light2_Input_BUTTON) * (5.0 / 1023.0);
    float voltage3 = analogRead(constants.UV_Light3_Input_BUTTON) * (5.0 / 1023.0);
    float voltage4 = analogRead(constants.UV_Light4_Input_BUTTON) * (5.0 / 1023.0);
    float voltage5 = analogRead(constants.UV_Light5_Input_BUTTON) * (5.0 / 1023.0);
    float voltage6 = analogRead(constants.UV_Light6_Input_BUTTON) * (5.0 / 1023.0);
    float voltage7 = analogRead(constants.UV_Light7_Input_BUTTON) * (5.0 / 1023.0);
    float voltage8 = analogRead(constants.UV_Light8_Input_BUTTON) * (5.0 / 1023.0);

    if (voltage1 < 2.5) {
      ////Serial.println(F("Selected 1 ");
      pressedButton = 1;
    }
    if (voltage2 < 2.5) {
      ////Serial.println(F("Selected 2 ");
      pressedButton = 2;
    }
    if (voltage3 < 2.5) {
      ////Serial.println(F("Selected 3 ");
      pressedButton = 3;
    }
    if (voltage4 < 2.5) {
      ////Serial.println(F("Selected 4 ");
      pressedButton = 4;
    }
    if (voltage5 < 2.5) {
      ////Serial.println(F("Selected 5 ");
      pressedButton = 5;
    }
    if (voltage6 < 2.5) {
      ////Serial.println(F("Selected 6 ");
      pressedButton = 6;
    }
    if (voltage7 < 2.5) {
      ////Serial.println(F("Selected 7 ");
      pressedButton = 7;
    }
    if (voltage8 < 2.5) {
      ////Serial.println(F("Selected 8 ");
      pressedButton = 8;
    }

    if (digitalRead(constants.UV_Light9_Input_BUTTON) == LOW) {
      pressedButton = 9;
      ////Serial.println(F("Selected 9 ");
    }
    if (digitalRead(constants.UV_Light10_Input_BUTTON) == LOW) {
      pressedButton = 10;
      ////Serial.println(F("Selected 10 ");
    }
    if (digitalRead(constants.UV_Light11_Input_BUTTON) == LOW) {
      pressedButton = 11;
      ////Serial.println(F("Selected 11 ");
    }
    if (digitalRead(constants.UV_Light12_Input_BUTTON) == LOW) {
      pressedButton = 12;
      ////Serial.println(F("Selected 12 ");
    }
    if (digitalRead(constants.UV_Light13_Input_BUTTON) == LOW) {
      pressedButton = 13;
      ////Serial.println(F("Selected 13 ");
    }
    if (digitalRead(constants.UV_Light14_Input_BUTTON) == LOW) {
      pressedButton = 14;
      ////Serial.println(F("Selected 14 ");
    }

    if (digitalRead(constants.UV_Light15_Input_BUTTON) == LOW) {
      pressedButton = 15;
      ////Serial.println(F("Selected 15 ");
    }
    if (digitalRead(constants.UV_Light16_Input_BUTTON) == LOW) {
      pressedButton = 16;
      ////Serial.println(F("Selected 16 ");
    }
    if (digitalRead(constants.UV_Light17_Input_BUTTON) == LOW) {
      pressedButton = 17;
      ////Serial.println(F("Selected 17 ");
    }
    if (digitalRead(constants.UV_Light18_Input_BUTTON) == LOW) {
      pressedButton = 18;
      ////Serial.println(F("Selected 18 ");
    }
    if (digitalRead(constants.UV_Light19_Input_BUTTON) == LOW) {
      pressedButton = 19;
      ////Serial.println(F("Selected 19 ");
    }
    if (digitalRead(constants.UV_Light20_Input_BUTTON) == LOW) {
      pressedButton = 20;
      ////Serial.println(F("Selected 20 ");
    }
    if (digitalRead(constants.UV_Light21_Input_BUTTON) == LOW) {
      pressedButton = 21;
      ////Serial.println(F("Selected 21 ");
    }
    if (digitalRead(constants.UV_Light22_Input_BUTTON) == LOW) {
      pressedButton = 22;
      ////Serial.println(F("Selected 22 ");
    }
    if (digitalRead(constants.UV_Light23_Input_BUTTON) == LOW) {
      pressedButton = 23;
      ////Serial.println(F("Selected 23 ");
    }
    if (digitalRead(constants.UV_Light24_Input_BUTTON) == LOW) {
      pressedButton = 24;
      ////Serial.println(F("Selected 24 ");
    }

    if (digitalRead(constants.UP_PIN) == LOW) {
      pressedButton = 25;
      ////Serial.println(F("Selected UP ");
    }
    if (digitalRead(constants.DOWN_PIN) == LOW) {
      pressedButton = 26;
      ////Serial.println(F("Selected DOWN ");
    }
    Serial.println(String(buttonPressedData1));
    char char_array[buttonPressedData1.length() + 1];
    buttonPressedData1.toCharArray(char_array, buttonPressedData1.length() + 1);

    if (char_array[1] == '0') {
      pressedButton = 27;
      ////Serial.println(F("Selected 25 ");
    }
    if (char_array[2] == '0') {
      pressedButton = 28;
      ////Serial.println(F("Selected 26 ");
    }
    if (char_array[3] == '0') {
      pressedButton = 29;
      ////Serial.println(F("Selected 27 ");
    }
    if (char_array[4] == '0') {
      pressedButton = 30;
      ////Serial.println(F("Selected 28 ");
    }
    if (char_array[5] == '0') {
      pressedButton = 31;
      ////Serial.println(F("Selected 29 ");
    }
    if (char_array[6] == '0') {
      pressedButton = 32;
      ////Serial.println(F("Selected 30 ");
    }
    if (char_array[7] == '0') {
      pressedButton = 33;
      ////Serial.println(F("Selected 31 ");
    }
    if (char_array[8] == '0') {
      pressedButton = 34;
      ////Serial.println(F("Selected 32 ");
    }
    if (char_array[9] == '0') {
      pressedButton = 35;
      ////Serial.println(F("Selected 33 ");
    }
    if (char_array[10] == '0') {
      pressedButton = 36;
      ////Serial.println(F("Selected 34 ");
    }
    if (char_array[11] == '0') {
      pressedButton = 37;
      ////Serial.println(F("Selected 35 ");
    }
    if (char_array[12] == '0') {
      pressedButton = 38;
      ////Serial.println(F("Selected 36 ");
    }
    if (char_array[13] == '0') {
      pressedButton = 39;
      ////Serial.println(F("Selected 37 ");
    }
    if (char_array[14] == '0') {
      pressedButton = 40;
      ////Serial.println(F("Selected 38 ");
    }
    if (char_array[15] == '0') {
      pressedButton = 41;
      ////Serial.println(F("Selected 39 ");
    }
    if (char_array[16] == '0') {
      pressedButton = 42;
      ////Serial.println(F("Selected 40 ");
    }
    if (char_array[17] == '0') {
      pressedButton = 43;
      ////Serial.println(F("Selected 41 ");
    }
    if (char_array[18] == '0') {
      pressedButton = 44;
      ////Serial.println(F("Selected 42 ");
    }
    if (char_array[19] == '0') {
      pressedButton = 45;
      ////Serial.println(F("Selected 43 ");
    }
    if (char_array[20] == '0') {
      pressedButton = 46;
      ////Serial.println(F("Selected 44 ");
    }
    if (char_array[21] == '0') {
      pressedButton = 47;
      ////Serial.println(F("Selected 45 ");
    }
    if (char_array[22] == '0') {
      pressedButton = 48;
      ////Serial.println(F("Selected 46 ");
    }
    if (char_array[23] == '0') {
      pressedButton = 49;
      ////Serial.println(F("Selected 47 ");
    }
    if (char_array[24] == '0') {
      pressedButton = 50;
      ////Serial.println(F("Selected 48 ");
    }
    if (char_array[25] == '0') {
      pressedButton = 51;
      ////Serial.println(F("Selected 49 ");
    }
    if (char_array[26] == '0') {
      pressedButton = 52;
      ////Serial.println(F("Selected 50 ");
    }
    if (char_array[27] == '0') {
      pressedButton = 53;
      ////Serial.println(F("Selected 51 ");
    }
    if (char_array[28] == '0') {
      pressedButton = 54;
      ////Serial.println(F("Selected 52 ");
    }
    if (char_array[29] == '0') {
      pressedButton = 55;
      ////Serial.println(F("Selected 53 ");
    }
    if (char_array[30] == '0') {
      pressedButton = 56;
      ////Serial.println(F("Selected 54 ");
    }
    if (char_array[31] == '0') {
      pressedButton = 57;
      ////Serial.println(F("Selected 55 ");
    }
    if (char_array[32] == '0') {
      pressedButton = 58;
      ////Serial.println(F("Selected 56 ");
    }
    if (char_array[33] == '0') {
      pressedButton = 59;
      ////Serial.println(F("Selected 57 ");
    }
    if (char_array[34] == '0') {
      pressedButton = 60;
      ////Serial.println(F("Selected 58 ");
    }
    if (char_array[35] == '0') {
      pressedButton = 61;
      ////Serial.println(F("Selected 59 ");
    }
    if (char_array[36] == '0') {
      pressedButton = 62;
      ////Serial.println(F("Selected 60 ");
    }

    counter++;
    delay(100);
  }
  return buttonToBePressed == pressedButton;
}

int UV::reset() {

  int pressed = 0;

  float voltage1 = analogRead(constants.UV_Light1_Input_BUTTON) * (5.0 / 1023.0);
  if (voltage1 < 2.5) {
    ledHoursRun1 = 0;
    ledlastBuzzed1 = 0;
    pressed = 1;
    erroredLight[0] = 0;
    ////Serial.println(F("Reset pressed on 1 ");
  }
  float voltage2 = analogRead(constants.UV_Light2_Input_BUTTON) * (5.0 / 1023.0);
  if (voltage2 < 2.5) {
    ledHoursRun2 = 0;
    ledlastBuzzed2 = 0;
    pressed = 2;
    erroredLight[1] = 0;
    ////Serial.println(F("Reset pressed on 2 ");
  }
  float voltage3 = analogRead(constants.UV_Light3_Input_BUTTON) * (5.0 / 1023.0);
  if (voltage3 < 2.5) {
    ledHoursRun3 = 0;
    ledlastBuzzed3 = 0;
    pressed = 3;
    erroredLight[2] = 0;
    ////Serial.println(F("Reset pressed on 3 ");
  }
  float voltage4 = analogRead(constants.UV_Light4_Input_BUTTON) * (5.0 / 1023.0);
  if (voltage4 < 2.5) {
    ledHoursRun4 = 0;
    ledlastBuzzed4 = 0;
    pressed = 4;
    erroredLight[3] = 0;
    ////Serial.println(F("Reset pressed on 4 ");
  }
  float voltage5 = analogRead(constants.UV_Light5_Input_BUTTON) * (5.0 / 1023.0);
  if (voltage5 < 2.5) {
    ledHoursRun5 = 0;
    ledlastBuzzed5 = 0;
    pressed = 5;
    erroredLight[4] = 0;
    ////Serial.println(F("Reset pressed on 5 ");
  }
  float voltage6 = analogRead(constants.UV_Light6_Input_BUTTON) * (5.0 / 1023.0);
  if (voltage6 < 2.5) {
    ledHoursRun6 = 0;
    ledlastBuzzed6 = 0;
    pressed = 6;
    erroredLight[5] = 0;
    ////Serial.println(F("Reset pressed on 6 ");
  }
  float voltage7 = analogRead(constants.UV_Light7_Input_BUTTON) * (5.0 / 1023.0);
  if (voltage7 < 2.5) {
    ledHoursRun7 = 0;
    ledlastBuzzed7 = 0;
    pressed = 7;
    erroredLight[6] = 0;
    ////Serial.println(F("Reset pressed on 7 ");
  }
  float voltage8 = analogRead(constants.UV_Light8_Input_BUTTON) * (5.0 / 1023.0);
  if (voltage8 < 2.5) {
    ledHoursRun8 = 0;
    ledlastBuzzed8 = 0;
    pressed = 8;
    erroredLight[7] = 0;
    ////Serial.println(F("Reset pressed on 8 ");
  }

  if (digitalRead(constants.UV_Light9_Input_BUTTON) == LOW) {
    ledHoursRun9 = 0;
    ledlastBuzzed9 = 0;
    pressed = 9;
    erroredLight[8] = 0;
    ////Serial.println(F("Reset pressed on 9 ");
  }
  if (digitalRead(constants.UV_Light10_Input_BUTTON) == LOW) {
    ledHoursRun10 = 0;
    ledlastBuzzed10 = 0;
    pressed = 10;
    erroredLight[9] = 0;
    ////Serial.println(F("Reset pressed on 10 ");
  }
  if (digitalRead(constants.UV_Light11_Input_BUTTON) == LOW) {
    ledHoursRun11 = 0;
    ledlastBuzzed11 = 0;
    pressed = 11;
    erroredLight[10] = 0;
    ////Serial.println(F("Reset pressed on 11 ");
  }
  if (digitalRead(constants.UV_Light12_Input_BUTTON) == LOW) {
    ledHoursRun12 = 0;
    ledlastBuzzed12 = 0;
    pressed = 12;
    erroredLight[11] = 0;
    ////Serial.println(F("Reset pressed on 12 ");
  }
  if (digitalRead(constants.UV_Light13_Input_BUTTON) == LOW) {
    ledHoursRun13 = 0;
    ledlastBuzzed13 = 0;
    pressed = 13;
    erroredLight[12] = 0;
    ////Serial.println(F("Reset pressed on 13 ");
  }
  if (digitalRead(constants.UV_Light14_Input_BUTTON) == LOW) {
    ledHoursRun14 = 0;
    ledlastBuzzed14 = 0;
    pressed = 14;
    erroredLight[13] = 0;
    ////Serial.println(F("Reset pressed on 14 ");
  }
  if (digitalRead(constants.UV_Light15_Input_BUTTON) == LOW) {
    ledHoursRun15 = 0;
    ledlastBuzzed15 = 0;
    pressed = 15;
    erroredLight[14] = 0;
    ////Serial.println(F("Reset pressed on 15 ");
  }
  if (digitalRead(constants.UV_Light16_Input_BUTTON) == LOW) {
    ledHoursRun16 = 0;
    ledlastBuzzed16 = 0;
    pressed = 16;
    erroredLight[15] = 0;
    ////Serial.println(F("Reset pressed on 16 ");
  }
  if (digitalRead(constants.UV_Light17_Input_BUTTON) == LOW) {
    ledHoursRun17 = 0;
    ledlastBuzzed17 = 0;
    pressed = 17;
    erroredLight[16] = 0;
    ////Serial.println(F("Reset pressed on 17 ");
  }
  if (digitalRead(constants.UV_Light18_Input_BUTTON) == LOW) {
    ledHoursRun18 = 0;
    ledlastBuzzed18 = 0;
    pressed = 18;
    erroredLight[17] = 0;
    ////Serial.println(F("Reset pressed on 18 ");
  }
  if (digitalRead(constants.UV_Light19_Input_BUTTON) == LOW) {
    ledHoursRun19 = 0;
    ledlastBuzzed19 = 0;
    pressed = 19;
    erroredLight[18] = 0;
    ////Serial.println(F("Reset pressed on 19 ");
  }
  if (digitalRead(constants.UV_Light20_Input_BUTTON) == LOW) {
    ledHoursRun20 = 0;
    ledlastBuzzed20 = 0;
    pressed = 20;
    erroredLight[19] = 0;
    ////Serial.println(F("Reset pressed on 20 ");
  }
  if (digitalRead(constants.UV_Light21_Input_BUTTON) == LOW) {
    ledHoursRun21 = 0;
    ledlastBuzzed21 = 0;
    pressed = 21;
    erroredLight[20] = 0;
    ////Serial.println(F("Reset pressed on 21 ");
  }
  if (digitalRead(constants.UV_Light22_Input_BUTTON) == LOW) {
    ledHoursRun22 = 0;
    ledlastBuzzed22 = 0;
    pressed = 22;
    erroredLight[21] = 0;
    ////Serial.println(F("Reset pressed on 22 ");
  }
  if (digitalRead(constants.UV_Light23_Input_BUTTON) == LOW) {
    ledHoursRun23 = 0;
    ledlastBuzzed23 = 0;
    pressed = 23;
    erroredLight[22] = 0;
    ////Serial.println(F("Reset pressed on 23 ");
  }
  if (digitalRead(constants.UV_Light24_Input_BUTTON) == LOW) {
    ledHoursRun24 = 0;
    ledlastBuzzed24 = 0;
    pressed = 24;
    erroredLight[23] = 0;
    ////Serial.println(F("Reset pressed on 24 ");
  }

  String buttonPressedData1 = "";
    
  if (Serial3.available() > 0) {
    char bfr[100];
    memset(bfr, 0, 100);
    Serial3.readBytesUntil('\n', bfr, 50);
    Serial3.flush();
    Serial.println(String(bfr));
    if (bfr[0] == 'a' && bfr[37] == 'e') {
      buttonPressedData1 = String(bfr);
    }
  }

  char char_array[buttonPressedData1.length() + 1];
  buttonPressedData1.toCharArray(char_array, buttonPressedData1.length() + 1);

  if (char_array[1] == '0') {
    ledHoursRun25 = 0;
    ledlastBuzzed25 = 0;
    pressed = 25;
    erroredLight[24] = 0;
    ////Serial.println(F("Reset pressed on 25 ");
  }

  if (char_array[2] == '0') {
    ledHoursRun26 = 0;
    ledlastBuzzed26 = 0;
    pressed = 26;
    erroredLight[25] = 0;
    ////Serial.println(F("Reset pressed on 26 ");
  }
  if (char_array[3] == '0') {
    ledHoursRun27 = 0;
    ledlastBuzzed27 = 0;
    pressed = 27;
    erroredLight[26] = 0;
    ////Serial.println(F("Reset pressed on 27 ");
  }
  if (char_array[4] == '0') {
    ledHoursRun28 = 0;
    ledlastBuzzed28 = 0;
    pressed = 28;
    erroredLight[27] = 0;
    ////Serial.println(F("Reset pressed on 28 ");
  }
  if (char_array[5] == '0') {
    ledHoursRun29 = 0;
    ledlastBuzzed29 = 0;
    pressed = 29;
    erroredLight[28] = 0;
    ////Serial.println(F("Reset pressed on 29 ");
  }
  if (char_array[6] == '0') {
    ledHoursRun30 = 0;
    ledlastBuzzed30 = 0;
    pressed = 30;
    erroredLight[29] = 0;
    ////Serial.println(F("Reset pressed on 30 ");
  }
  if (char_array[7] == '0') {
    ledHoursRun31 = 0;
    ledlastBuzzed31 = 0;
    pressed = 31;
    erroredLight[30] = 0;
    ////Serial.println(F("Reset pressed on 31 ");
  }
  if (char_array[8] == '0') {
    ledHoursRun32 = 0;
    ledlastBuzzed32 = 0;
    pressed = 32;
    erroredLight[31] = 0;
    ////Serial.println(F("Reset pressed on 32 ");
  }
  if (char_array[9] == '0') {
    ledHoursRun33 = 0;
    ledlastBuzzed33 = 0;
    pressed = 33;
    erroredLight[32] = 0;
    ////Serial.println(F("Reset pressed on 33 ");
  }
  if (char_array[10] == '0') {
    ledHoursRun34 = 0;
    ledlastBuzzed34 = 0;
    pressed = 34;
    erroredLight[33] = 0;
    ////Serial.println(F("Reset pressed on 34 ");
  }
  if (char_array[11] == '0') {
    ledHoursRun35 = 0;
    ledlastBuzzed35 = 0;
    pressed = 35;
    erroredLight[34] = 0;
    ////Serial.println(F("Reset pressed on 35 ");
  }
  if (char_array[12] == '0') {
    ledHoursRun36 = 0;
    ledlastBuzzed36 = 0;
    pressed = 36;
    erroredLight[35] = 0;
    ////Serial.println(F("Reset pressed on 36 ");
  }
  if (char_array[13] == '0') {
    ledHoursRun37 = 0;
    ledlastBuzzed37 = 0;
    pressed = 37;
    erroredLight[36] = 0;
    ////Serial.println(F("Reset pressed on 37 ");
  }
  if (char_array[14] == '0') {
    ledHoursRun38 = 0;
    ledlastBuzzed38 = 0;
    pressed = 38;
    erroredLight[37] = 0;
    ////Serial.println(F("Reset pressed on 38 ");
  }
  if (char_array[15] == '0') {
    ledHoursRun39 = 0;
    ledlastBuzzed39 = 0;
    pressed = 39;
    erroredLight[38] = 0;
    ////Serial.println(F("Reset pressed on 39 ");
  }
  if (char_array[16] == '0') {
    ledHoursRun40 = 0;
    ledlastBuzzed40 = 0;
    pressed = 40;
    erroredLight[39] = 0;
    ////Serial.println(F("Reset pressed on 40 ");
  }
  if (char_array[17] == '0') {
    ledHoursRun41 = 0;
    ledlastBuzzed41 = 0;
    pressed = 41;
    erroredLight[40] = 0;
    ////Serial.println(F("Reset pressed on 41 ");
  }
  if (char_array[18] == '0') {
    ledHoursRun42 = 0;
    ledlastBuzzed42 = 0;
    pressed = 42;
    erroredLight[41] = 0;
    ////Serial.println(F("Reset pressed on 42 ");
  }
  if (char_array[19] == '0') {
    ledHoursRun43 = 0;
    ledlastBuzzed43 = 0;
    pressed = 43;
    erroredLight[42] = 0;
    ////Serial.println(F("Reset pressed on 43 ");
  }
  if (char_array[20] == '0') {
    ledHoursRun44 = 0;
    ledlastBuzzed44 = 0;
    pressed = 44;
    erroredLight[43] = 0;
    ////Serial.println(F("Reset pressed on 44 ");
  }
  if (char_array[21] == '0') {
    ledHoursRun45 = 0;
    ledlastBuzzed45 = 0;
    pressed = 45;
    erroredLight[44] = 0;
    ////Serial.println(F("Reset pressed on 45 ");
  }
  if (char_array[22] == '0') {
    ledHoursRun46 = 0;
    ledlastBuzzed46 = 0;
    pressed = 46;
    erroredLight[45] = 0;
    ////Serial.println(F("Reset pressed on 46 ");
  }
  if (char_array[23] == '0') {
    ledHoursRun47 = 0;
    ledlastBuzzed47 = 0;
    pressed = 47;
    erroredLight[46] = 0;
    ////Serial.println(F("Reset pressed on 47 ");
  }
  if (char_array[24] == '0') {
    ledHoursRun48 = 0;
    ledlastBuzzed48 = 0;
    pressed = 48;
    erroredLight[47] = 0;
    ////Serial.println(F("Reset pressed on 48 ");
  }
  if (char_array[25] == '0') {
    ledHoursRun49 = 0;
    ledlastBuzzed49 = 0;
    pressed = 49;
    erroredLight[48] = 0;
    ////Serial.println(F("Reset pressed on 49 ");
  }
  if (char_array[26] == '0') {
    ledHoursRun50 = 0;
    ledlastBuzzed50 = 0;
    pressed = 50;
    erroredLight[49] = 0;
    ////Serial.println(F("Reset pressed on 50 ");
  }
  if (char_array[27] == '0') {
    ledHoursRun51 = 0;
    ledlastBuzzed51 = 0;
    pressed = 51;
    erroredLight[50] = 0;
    ////Serial.println(F("Reset pressed on 51 ");
  }
  if (char_array[28] == '0') {
    ledHoursRun52 = 0;
    ledlastBuzzed52 = 0;
    pressed = 52;
    erroredLight[51] = 0;
    ////Serial.println(F("Reset pressed on 52 ");
  }
  if (char_array[29] == '0') {
    ledHoursRun53 = 0;
    ledlastBuzzed53 = 0;
    pressed = 53;
    erroredLight[52] = 0;
    ////Serial.println(F("Reset pressed on 53 ");
  }
  if (char_array[30] == '0') {
    ledHoursRun54 = 0;
    ledlastBuzzed54 = 0;
    pressed = 54;
    erroredLight[53] = 0;
    ////Serial.println(F("Reset pressed on 54 ");
  }
  if (char_array[31] == '0') {
    ledHoursRun55 = 0;
    ledlastBuzzed55 = 0;
    pressed = 55;
    erroredLight[54] = 0;
    ////Serial.println(F("Reset pressed on 55 ");
  }
  if (char_array[32] == '0') {
    ledHoursRun56 = 0;
    ledlastBuzzed56 = 0;
    pressed = 56;
    erroredLight[55] = 0;
    ////Serial.println(F("Reset pressed on 56 ");
  }
  if (char_array[33] == '0') {
    ledHoursRun57 = 0;
    ledlastBuzzed57 = 0;
    pressed = 57;
    erroredLight[56] = 0;
    ////Serial.println(F("Reset pressed on 57 ");
  }
  if (char_array[34] == '0') {
    ledHoursRun58 = 0;
    ledlastBuzzed58 = 0;
    pressed = 58;
    erroredLight[57] = 0;
    ////Serial.println(F("Reset pressed on 58 ");
  }
  if (char_array[35] == '0') {
    ledHoursRun59 = 0;
    ledlastBuzzed59 = 0;
    pressed = 59;
    erroredLight[58] = 0;
    ////Serial.println(F("Reset pressed on 59 ");
  }
  if (char_array[36] == '0') {
    ledHoursRun60 = 0;
    ledlastBuzzed60 = 0;
    pressed = 60;
    erroredLight[59] = 0;
    ////Serial.println(F("Reset pressed on 60 ");
  }

  return pressed;
}

void UV::statusOfUV() {

  led1Status = '0';
  led2Status = '0';
  led3Status = '0';
  led4Status = '0';
  led5Status = '0';
  led6Status = '0';
  led7Status = '0';
  led8Status = '0';
  led9Status = '0';
  led10Status = '0';
  led11Status = '0';
  led12Status = '0';
  led13Status = '0';
  led14Status = '0';
  led15Status = '0';
  led16Status = '0';
  led17Status = '0';
  led18Status = '0';
  led19Status = '0';
  led20Status = '0';
  led21Status = '0';
  led22Status = '0';
  led23Status = '0';
  led24Status = '0';
  led25Status = '0';
  led26Status = '0';
  led27Status = '0';
  led28Status = '0';
  led29Status = '0';
  led30Status = '0';
  led31Status = '0';
  led32Status = '0';
  led33Status = '0';
  led34Status = '0';
  led35Status = '0';
  led36Status = '0';
  led37Status = '0';
  led38Status = '0';
  led39Status = '0';
  led40Status = '0';
  led41Status = '0';
  led42Status = '0';
  led43Status = '0';
  led44Status = '0';
  led45Status = '0';
  led46Status = '0';
  led47Status = '0';
  led48Status = '0';
  led49Status = '0';
  led50Status = '0';
  led51Status = '0';
  led52Status = '0';
  led53Status = '0';
  led54Status = '0';
  led55Status = '0';
  led56Status = '0';
  led57Status = '0';
  led58Status = '0';
  led59Status = '0';
  led60Status = '0';

  float voltage1 = analogRead(constants.UV_Light1_Input_PIN) * (5.0 / 1023.0);
  if (voltage1 < 2.5) {
    led1Status = '1';
    ////Serial.println(F("Led 1 is ON ");
  }
  float voltage2 = analogRead(constants.UV_Light2_Input_PIN) * (5.0 / 1023.0);
  if (voltage2 < 2.5) {
    led2Status = '1';
    ////Serial.println(F("Led 2 is ON ");
  }
  float voltage3 = analogRead(constants.UV_Light3_Input_PIN) * (5.0 / 1023.0);
  if (voltage3 < 2.5) {
    led3Status = '1';
    ////Serial.println(F("Led 3 is ON ");
  }
  float voltage4 = analogRead(constants.UV_Light4_Input_PIN) * (5.0 / 1023.0);
  if (voltage4 < 2.5) {
    led4Status = '1';
    ////Serial.println(F("Led 4 is ON ");
  }
  float voltage5 = analogRead(constants.UV_Light5_Input_PIN) * (5.0 / 1023.0);
  if (voltage5 < 2.5) {
    led5Status = '1';
    ////Serial.println(F("Led 5 is ON ");
  }
  float voltage6 = analogRead(constants.UV_Light6_Input_PIN) * (5.0 / 1023.0);
  if (voltage6 < 2.5) {
    led6Status = '1';
    ////Serial.println(F("Led 6 is ON ");
  }
  float voltage7 = analogRead(constants.UV_Light7_Input_PIN) * (5.0 / 1023.0);
  if (voltage7 < 2.5) {
    led7Status = '1';
    ////Serial.println(F("Led 7 is ON ");
  }
  float voltage8 = analogRead(constants.UV_Light8_Input_PIN) * (5.0 / 1023.0);
  if (voltage8 < 2.5) {
    led8Status = '1';
    ////Serial.println(F("Led 8 is ON ");
  }


  if (digitalRead(constants.UV_Light9_Input_PIN) == LOW) {
    ////Serial.println(F("Led 9 is ON ");
    led9Status = '1';
  }
  if (digitalRead(constants.UV_Light10_Input_PIN) == LOW) {
    ////Serial.println(F("Led 10 is ON ");
    led10Status = '1';
  }
  if (digitalRead(constants.UV_Light11_Input_PIN) == LOW) {
    ////Serial.println(F("Led 11 is ON ");
    led11Status = '1';
  }
  if (digitalRead(constants.UV_Light12_Input_PIN) == LOW) {
    ////Serial.println(F("Led 12 is ON ");
    led12Status = '1';
  }
  if (digitalRead(constants.UV_Light13_Input_PIN) == LOW) {
    ////Serial.println(F("Led 13 is ON ");
    led13Status = '1';
  }
  if (digitalRead(constants.UV_Light14_Input_PIN) == LOW) {
    ////Serial.println(F("Led 14 is ON ");
    led14Status = '1';
  }
  if (digitalRead(constants.UV_Light15_Input_PIN) == LOW) {
    ////Serial.println(F("Led 15 is ON ");
    led15Status = '1';
  }
  if (digitalRead(constants.UV_Light16_Input_PIN) == LOW) {
    ////Serial.println(F("Led 16 is ON ");
    led16Status = '1';
  }
  if (digitalRead(constants.UV_Light17_Input_PIN) == LOW) {
    ////Serial.println(F("Led 17 is ON ");
    led17Status = '1';
  }
  if (digitalRead(constants.UV_Light18_Input_PIN) == LOW) {
    ////Serial.println(F("Led 18 is ON ");
    led18Status = '1';
  }
  if (digitalRead(constants.UV_Light19_Input_PIN) == LOW) {
    ////Serial.println(F("Led 19 is ON ");
    led19Status = '1';
  }
  if (digitalRead(constants.UV_Light20_Input_PIN) == LOW) {
    ////Serial.println(F("Led 20 is ON ");
    led20Status = '1';
  }
  if (digitalRead(constants.UV_Light21_Input_PIN) == LOW) {
    ////Serial.println(F("Led 21 is ON ");
    led21Status = '1';
  }
  if (digitalRead(constants.UV_Light22_Input_PIN) == LOW) {
    ////Serial.println(F("Led 22 is ON ");
    led22Status = '1';
  }
  if (digitalRead(constants.UV_Light23_Input_PIN) == LOW) {
    ////Serial.println(F("Led 23 is ON ");
    led23Status = '1';
  }
  if (digitalRead(constants.UV_Light24_Input_PIN) == LOW) {
    ////Serial.println(F("Led 24 is ON ");
    led24Status = '1';
  }

  char char_array[lightData.length() + 1];
  lightData.toCharArray(char_array, lightData.length() + 1);

  if (char_array[1] == '0') {
    ////Serial.println(F("Led 25 is ON ");
    led25Status = '1';
  }
  if (char_array[2] == '0') {
    ////Serial.println(F("Led 26 is ON ");
    led26Status = '1';
  }
  if (char_array[3] == '0') {
    ////Serial.println(F("Led 27 is ON ");
    led27Status = '1';
  }
  if (char_array[4] == '0') {
    ////Serial.println(F("Led 28 is ON ");
    led28Status = '1';
  }
  if (char_array[5] == '0') {
    ////Serial.println(F("Led 29 is ON ");
    led29Status = '1';
  }
  if (char_array[6] == '0') {
    ////Serial.println(F("Led 30 is ON ");
    led30Status = '1';
  }
  if (char_array[7] == '0') {
    ////Serial.println(F("Led 31 is ON ");
    led31Status = '1';
  }
  if (char_array[8] == '0') {
    ////Serial.println(F("Led 32 is ON ");
    led32Status = '1';
  }
  if (char_array[9] == '0') {
    ////Serial.println(F("Led 33 is ON ");
    led33Status = '1';
  }
  if (char_array[10] == '0') {
    ////Serial.println(F("Led 34 is ON ");
    led34Status = '1';
  }
  if (char_array[11] == '0') {
    ////Serial.println(F("Led 35 is ON ");
    led35Status = '1';
  }
  if (char_array[12] == '0') {
    ////Serial.println(F("Led 36 is ON ");
    led36Status = '1';
  }
  if (char_array[13] == '0') {
    ////Serial.println(F("Led 37 is ON ");
    led37Status = '1';
  }
  if (char_array[14] == '0') {
    ////Serial.println(F("Led 38 is ON ");
    led38Status = '1';
  }
  if (char_array[15] == '0') {
    ////Serial.println(F("Led 39 is ON ");
    led39Status = '1';
  }
  if (char_array[16] == '0') {
    ////Serial.println(F("Led 40 is ON ");
    led40Status = '1';
  }
  if (char_array[17] == '0') {
    ////Serial.println(F("Led 41 is ON ");
    led41Status = '1';
  }
  if (char_array[18] == '0') {
    ////Serial.println(F("Led 42 is ON ");
    led42Status = '1';
  }
  if (char_array[19] == '0') {
    ////Serial.println(F("Led 43 is ON ");
    led43Status = '1';
  }
  if (char_array[20] == '0') {
    ////Serial.println(F("Led 44 is ON ");
    led44Status = '1';
  }
  if (char_array[21] == '0') {
    ////Serial.println(F("Led 45 is ON ");
    led45Status = '1';
  }
  if (char_array[22] == '0') {
    ////Serial.println(F("Led 46 is ON ");
    led46Status = '1';
  }
  if (char_array[23] == '0') {
    ////Serial.println(F("Led 47 is ON ");
    led47Status = '1';
  }
  if (char_array[24] == '0') {
    ////Serial.println(F("Led 48 is ON ");
    led48Status = '1';
  }
  if (char_array[25] == '0') {
    ////Serial.println(F("Led 49 is ON ");
    led49Status = '1';
  }
  if (char_array[26] == '0') {
    ////Serial.println(F("Led 50 is ON ");
    led50Status = '1';
  }
  if (char_array[27] == '0') {
    ////Serial.println(F("Led 51 is ON ");
    led51Status = '1';
  }
  if (char_array[28] == '0') {
    ////Serial.println(F("Led 52 is ON ");
    led52Status = '1';
  }
  if (char_array[29] == '0') {
    ////Serial.println(F("Led 53 is ON ");
    led53Status = '1';
  }
  if (char_array[30] == '0') {
    ////Serial.println(F("Led 54 is ON ");
    led54Status = '1';
  }
  if (char_array[31] == '0') {
    ////Serial.println(F("Led 55 is ON ");
    led55Status = '1';
  }
  if (char_array[32] == '0') {
    ////Serial.println(F("Led 56 is ON ");
    led56Status = '1';
  }
  if (char_array[33] == '0') {
    ////Serial.println(F("Led 57 is ON ");
    led57Status = '1';
  }
  if (char_array[34] == '0') {
    ////Serial.println(F("Led 58 is ON ");
    led58Status = '1';
  }
  if (char_array[35] == '0') {
//    ////Serial.println(F("Led 59 is ON ");
    led59Status = '1';
  }
  if (char_array[36] == '0') {
    //Led 60 is ON ");
    led60Status = '1';
  }

}

void UV::updateUVStat() {

  led1Status = '0';
  led2Status = '0';
  led3Status = '0';
  led4Status = '0';
  led5Status = '0';
  led6Status = '0';
  led7Status = '0';
  led8Status = '0';
  led9Status = '0';
  led10Status = '0';
  led11Status = '0';
  led12Status = '0';
  led13Status = '0';
  led14Status = '0';
  led15Status = '0';
  led16Status = '0';
  led17Status = '0';
  led18Status = '0';
  led19Status = '0';
  led20Status = '0';
  led21Status = '0';
  led22Status = '0';
  led23Status = '0';
  led24Status = '0';
  led25Status = '0';
  led26Status = '0';
  led27Status = '0';
  led28Status = '0';
  led29Status = '0';
  led30Status = '0';
  led31Status = '0';
  led32Status = '0';
  led33Status = '0';
  led34Status = '0';
  led35Status = '0';
  led36Status = '0';
  led37Status = '0';
  led38Status = '0';
  led39Status = '0';
  led40Status = '0';
  led41Status = '0';
  led42Status = '0';
  led43Status = '0';
  led44Status = '0';
  led45Status = '0';
  led46Status = '0';
  led47Status = '0';
  led48Status = '0';
  led49Status = '0';
  led50Status = '0';
  led51Status = '0';
  led52Status = '0';
  led53Status = '0';
  led54Status = '0';
  led55Status = '0';
  led56Status = '0';
  led57Status = '0';
  led58Status = '0';
  led59Status = '0';
  led60Status = '0';

  float voltage1 = analogRead(constants.UV_Light1_Input_PIN) * (5.0 / 1023.0);
  if (voltage1 < 2.5) {
    ledHoursRun1 = ledHoursRun1 + 1;
    led1Status = '1';
    ////Serial.println("Led 1 is ON ");
  }
  float voltage2 = analogRead(constants.UV_Light2_Input_PIN) * (5.0 / 1023.0);
  if (voltage2 < 2.5) {
    ledHoursRun2 = ledHoursRun2 + 1;
    led2Status = '1';
    ////Serial.println("Led 2 is ON ");
  }
  float voltage3 = analogRead(constants.UV_Light3_Input_PIN) * (5.0 / 1023.0);
  if (voltage3 < 2.5) {
    ledHoursRun3 = ledHoursRun3 + 1;
    led3Status = '1';
    ////Serial.println("Led 3 is ON ");
  }
  float voltage4 = analogRead(constants.UV_Light4_Input_PIN) * (5.0 / 1023.0);
  if (voltage4 < 2.5) {
    ledHoursRun4 = ledHoursRun4 + 1;
    led4Status = '1';
    ////Serial.println("Led 4 is ON ");
  }
  float voltage5 = analogRead(constants.UV_Light5_Input_PIN) * (5.0 / 1023.0);
  if (voltage5 < 2.5) {
    ledHoursRun5 = ledHoursRun5 + 1;
    led5Status = '1';
    ////Serial.println("Led 5 is ON ");
  }
  float voltage6 = analogRead(constants.UV_Light6_Input_PIN) * (5.0 / 1023.0);
  if (voltage6 < 2.5) {
    ledHoursRun6 = ledHoursRun6 + 1;
    led6Status = '1';
    ////Serial.println("Led 6 is ON ");
  }
  float voltage7 = analogRead(constants.UV_Light7_Input_PIN) * (5.0 / 1023.0);
  if (voltage7 < 2.5) {
    ledHoursRun7 = ledHoursRun7 + 1;
    led7Status = '1';
    ////Serial.println("Led 7 is ON ");
  }
  float voltage8 = analogRead(constants.UV_Light8_Input_PIN) * (5.0 / 1023.0);
  if (voltage8 < 2.5) {
    ledHoursRun8 = ledHoursRun8 + 1;
    led8Status = '1';
    ////Serial.println("Led 8 is ON ");
  }

  if (digitalRead(constants.UV_Light9_Input_PIN) == LOW) {
    ////Serial.println("Led 9 is ON ");
    ledHoursRun9 = ledHoursRun9 + 1;
    led9Status = '1';
  }
  if (digitalRead(constants.UV_Light10_Input_PIN) == LOW) {
    ////Serial.println("Led 10 is ON ");
    ledHoursRun10 = ledHoursRun10 + 1;
    led10Status = '1';
  }
  if (digitalRead(constants.UV_Light11_Input_PIN) == LOW) {
    ////Serial.println("Led 11 is ON ");
    ledHoursRun11 = ledHoursRun11 + 1;
    led11Status = '1';
  }
  if (digitalRead(constants.UV_Light12_Input_PIN) == LOW) {
    ////Serial.println("Led 12 is ON ");
    ledHoursRun12 = ledHoursRun12 + 1;
    led12Status = '1';
  }
  if (digitalRead(constants.UV_Light13_Input_PIN) == LOW) {
    ////Serial.println("Led 13 is ON ");
    ledHoursRun13 = ledHoursRun13 + 1;
    led13Status = '1';
  }
  if (digitalRead(constants.UV_Light14_Input_PIN) == LOW) {
    ////Serial.println("Led 14 is ON ");
    ledHoursRun14 = ledHoursRun14 + 1;
    led14Status = '1';
  }
  if (digitalRead(constants.UV_Light15_Input_PIN) == LOW) {
    ////Serial.println("Led 15 is ON ");
    ledHoursRun15 = ledHoursRun15 + 1;
    led15Status = '1';
  }
  if (digitalRead(constants.UV_Light16_Input_PIN) == LOW) {
    ////Serial.println("Led 16 is ON ");
    ledHoursRun16 = ledHoursRun16 + 1;
    led16Status = '1';
  }
  if (digitalRead(constants.UV_Light17_Input_PIN) == LOW) {
    ////Serial.println("Led 17 is ON ");
    ledHoursRun17 = ledHoursRun17 + 1;
    led17Status = '1';
  }
  if (digitalRead(constants.UV_Light18_Input_PIN) == LOW) {
    ////Serial.println("Led 18 is ON ");
    ledHoursRun18 = ledHoursRun18 + 1;
    led18Status = '1';
  }
  if (digitalRead(constants.UV_Light19_Input_PIN) == LOW) {
    ////Serial.println("Led 19 is ON ");
    ledHoursRun19 = ledHoursRun19 + 1;
    led19Status = '1';
  }
  if (digitalRead(constants.UV_Light20_Input_PIN) == LOW) {
    ////Serial.println("Led 20 is ON ");
    ledHoursRun20 = ledHoursRun20 + 1;
    led20Status = '1';
  }
  if (digitalRead(constants.UV_Light21_Input_PIN) == LOW) {
    ////Serial.println("Led 21 is ON ");
    ledHoursRun21 = ledHoursRun21 + 1;
    led21Status = '1';
  }
  if (digitalRead(constants.UV_Light22_Input_PIN) == LOW) {
    ////Serial.println("Led 22 is ON ");
    ledHoursRun22 = ledHoursRun22 + 1;
    led22Status = '1';
  }
  if (digitalRead(constants.UV_Light23_Input_PIN) == LOW) {
    ////Serial.println("Led 23 is ON ");
    ledHoursRun23 = ledHoursRun23 + 1;
    led23Status = '1';
  }
  if (digitalRead(constants.UV_Light24_Input_PIN) == LOW) {
    ////ln("Led 24 is ON ");
    ledHoursRun24 = ledHoursRun24 + 1;
    led24Status = '1';
  }

  char char_array[lightData.length() + 1];
  lightData.toCharArray(char_array, lightData.length() + 1);

  if (char_array[1] == '0') {
    ledHoursRun25 = ledHoursRun25 + 1;
    led25Status = '1';
  }
  if (char_array[2] == '0') {
    ledHoursRun26 = ledHoursRun26 + 1;
    led26Status = '1';
  }
  if (char_array[3] == '0') {
    ledHoursRun27 = ledHoursRun27 + 1;
    led27Status = '1';
  }
  if (char_array[4] == '0') {
    ledHoursRun28 = ledHoursRun28 + 1;
    led28Status = '1';
  }
  if (char_array[5] == '0') {
    ledHoursRun29 = ledHoursRun29 + 1;
    led29Status = '1';
  }
  if (char_array[6] == '0') {
    ledHoursRun30 = ledHoursRun30 + 1;
    led30Status = '1';
  }
  if (char_array[7] == '0') {
    ledHoursRun31 = ledHoursRun31 + 1;
    led31Status = '1';
  }
  if (char_array[8] == '0') {
    ledHoursRun32 = ledHoursRun32 + 1;
    led32Status = '1';
  }
  if (char_array[9] == '0') {
    ledHoursRun33 = ledHoursRun33 + 1;
    led33Status = '1';
  }
  if (char_array[10] == '0') {
    ledHoursRun34 = ledHoursRun34 + 1;
    led34Status = '1';
  }
  if (char_array[11] == '0') {
    ledHoursRun35 = ledHoursRun35 + 1;
    led35Status = '1';
  }
  if (char_array[12] == '0') {
    ledHoursRun36 = ledHoursRun36 + 1;
    led36Status = '1';
  }
  if (char_array[13] == '0') {
    ledHoursRun37 = ledHoursRun37 + 1;
    led37Status = '1';
  }
  if (char_array[14] == '0') {
    ledHoursRun38 = ledHoursRun38 + 1;
    led38Status = '1';
  }
  if (char_array[15] == '0') {
    ledHoursRun39 = ledHoursRun39 + 1;
    led39Status = '1';
  }
  if (char_array[16] == '0') {
    ledHoursRun40 = ledHoursRun40 + 1;
    led40Status = '1';
  }
  if (char_array[17] == '0') {
    ledHoursRun41 = ledHoursRun41 + 1;
    led41Status = '1';
  }
  if (char_array[18] == '0') {
    ledHoursRun42 = ledHoursRun42 + 1;
    led42Status = '1';
  }
  if (char_array[19] == '0') {
    ledHoursRun43 = ledHoursRun43 + 1;
    led43Status = '1';
  }
  if (char_array[20] == '0') {
    ledHoursRun44 = ledHoursRun44 + 1;
    led44Status = '1';
  }
  if (char_array[21] == '0') {
    ledHoursRun45 = ledHoursRun45 + 1;
    led45Status = '1';
  }
  if (char_array[22] == '0') {
    ledHoursRun46 = ledHoursRun46 + 1;
    led46Status = '1';
  }
  if (char_array[23] == '0') {
    ledHoursRun47 = ledHoursRun47 + 1;
    led47Status = '1';
  }
  if (char_array[24] == '0') {
    ledHoursRun48 = ledHoursRun48 + 1;
    led48Status = '1';
  }
  if (char_array[25] == '0') {
    ledHoursRun49 = ledHoursRun49 + 1;
    led49Status = '1';
  }
  if (char_array[26] == '0') {
    ledHoursRun50 = ledHoursRun50 + 1;
    led50Status = '1';
  }
  if (char_array[27] == '0') {
    ledHoursRun51 = ledHoursRun51 + 1;
    led51Status = '1';
  }
  if (char_array[28] == '0') {
    ledHoursRun52 = ledHoursRun52 + 1;
    led52Status = '1';
  }
  if (char_array[29] == '0') {
    ledHoursRun53 = ledHoursRun53 + 1;
    led53Status = '1';
  }
  if (char_array[30] == '0') {
    ledHoursRun54 = ledHoursRun54 + 1;
    led54Status = '1';
  }
  if (char_array[31] == '0') {
    ledHoursRun55 = ledHoursRun55 + 1;
    led55Status = '1';
  }
  if (char_array[32] == '0') {
    ledHoursRun56 = ledHoursRun56 + 1;
    led56Status = '1';
  }
  if (char_array[33] == '0') {
    ledHoursRun57 = ledHoursRun57 + 1;
    led57Status = '1';
  }
  if (char_array[34] == '0') {
    ledHoursRun58 = ledHoursRun58 + 1;
    led58Status = '1';
  }
  if (char_array[35] == '0') {
    ledHoursRun59 = ledHoursRun59 + 1;
    led59Status = '1';
  }

  if (char_array[36] == '0') {
    ledHoursRun60 = ledHoursRun60 + 1;
    led60Status = '1';
  } 
 
}
