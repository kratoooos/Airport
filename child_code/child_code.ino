#include "Constants.h"
#include "PCF8574.h"

Constants constants;
PCF8574 pcf8574(0x38);
PCF8574 pcf8574A(0x3c);
String output = "";
String output1 = "";
bool outputStat = false;


void setup() {

  Serial.begin(115200);
  Serial3.begin(500000);

  pcf8574.begin();
  pcf8574A.begin();
  pinMode(constants.INPUT_LIGHT_33, INPUT);
  pinMode(constants.INPUT_BTN_33, INPUT);
  pinMode(constants.INPUT_LIGHT_34, INPUT);
  pinMode(constants.INPUT_BTN_34, INPUT);
  pinMode(constants.INPUT_LIGHT_35, INPUT);
  pinMode(constants.INPUT_BTN_35, INPUT);
  pinMode(constants.INPUT_LIGHT_36, INPUT);
  pinMode(constants.INPUT_BTN_36, INPUT);
  pinMode(constants.INPUT_LIGHT_37, INPUT);
  pinMode(constants.INPUT_BTN_37, INPUT);
  pinMode(constants.INPUT_LIGHT_38, INPUT);
  pinMode(constants.INPUT_BTN_38, INPUT);
  pinMode(constants.INPUT_LIGHT_39, INPUT);
  pinMode(constants.INPUT_BTN_39, INPUT);
  pinMode(constants.INPUT_LIGHT_40, INPUT);
  pinMode(constants.INPUT_BTN_40, INPUT);
  pinMode(constants.INPUT_LIGHT_41, INPUT);
  pinMode(constants.INPUT_BTN_41, INPUT);
  pinMode(constants.INPUT_LIGHT_42, INPUT);
  pinMode(constants.INPUT_BTN_42, INPUT);
  pinMode(constants.INPUT_LIGHT_43, INPUT);
  pinMode(constants.INPUT_BTN_43, INPUT);
  pinMode(constants.INPUT_LIGHT_44, INPUT);
  pinMode(constants.INPUT_BTN_44, INPUT);
  pinMode(constants.INPUT_LIGHT_45, INPUT);
  pinMode(constants.INPUT_BTN_45, INPUT);
  pinMode(constants.INPUT_LIGHT_46, INPUT);
  pinMode(constants.INPUT_BTN_46, INPUT);
  pinMode(constants.INPUT_LIGHT_47, INPUT);
  pinMode(constants.INPUT_BTN_47, INPUT);
  pinMode(constants.INPUT_LIGHT_48, INPUT);
  pinMode(constants.INPUT_BTN_48, INPUT);
  pinMode(constants.INPUT_LIGHT_49, INPUT);
  pinMode(constants.INPUT_BTN_49, INPUT);
  pinMode(constants.INPUT_LIGHT_50, INPUT);
  pinMode(constants.INPUT_BTN_50, INPUT);
  pinMode(constants.INPUT_LIGHT_51, INPUT);
  pinMode(constants.INPUT_BTN_51, INPUT);
  pinMode(constants.INPUT_LIGHT_52, INPUT);
  pinMode(constants.INPUT_BTN_52, INPUT);


}

void loop() {

  output = "";
  output1 = "";

  output = "a";
  output1 = "b";

  float voltage1 = analogRead(constants.INPUT_BTN_25) * (5.0 / 1023.0);
  float voltage2 = analogRead(constants.INPUT_BTN_26) * (5.0 / 1023.0);
  float voltage3 = analogRead(constants.INPUT_BTN_27) * (5.0 / 1023.0);
  float voltage4 = analogRead(constants.INPUT_BTN_28) * (5.0 / 1023.0);
  float voltage5 = analogRead(constants.INPUT_BTN_29) * (5.0 / 1023.0);
  float voltage6 = analogRead(constants.INPUT_BTN_30) * (5.0 / 1023.0);
  float voltage7 = analogRead(constants.INPUT_BTN_31) * (5.0 / 1023.0);
  float voltage8 = analogRead(constants.INPUT_BTN_32) * (5.0 / 1023.0);



  if (voltage1 > 2.5) {
    output = output + "1";
  } else {
    output = output + "0";
  }

  if (voltage2 > 2.5) {
    output = output + "1";
  } else {
    output = output + "0";
  }

  if (voltage3 > 2.5) {
    output = output + "1";
  } else {
    output = output + "0";
  }

  if (voltage4 > 2.5) {
    output = output + "1";
  } else {
    output = output + "0";
  }

  if (voltage5 > 2.5) {
    output = output + "1";
  } else {
    output = output + "0";
  }

  if (voltage6 > 2.5) {
    output = output + "1";
  } else {
    output = output + "0";
  }

  if (voltage7 > 2.5) {
    output = output + "1";
  } else {
    output = output + "0";
  }

  if (voltage8 > 2.5) {
    output = output + "1";
    ////Serial.print("1");
  } else {
    output = output + "0";
    ////Serial.print("0");
  }

  ////Serial.print(digitalRead(constants.INPUT_BTN_33));
  output = output + String(digitalRead(constants.INPUT_BTN_33));
  ////Serial.print(',');
  ////Serial.print(digitalRead(constants.INPUT_BTN_34));
  output = output + String(digitalRead(constants.INPUT_BTN_34));
  ////Serial.print(',');
  ////Serial.print(digitalRead(constants.INPUT_BTN_35));
  output = output + String(digitalRead(constants.INPUT_BTN_35));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_36));
  output = output + String(digitalRead(constants.INPUT_BTN_36));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_37));
  output = output + String(digitalRead(constants.INPUT_BTN_37));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_38));
  output = output + String(digitalRead(constants.INPUT_BTN_38));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_39));
  output = output + String(digitalRead(constants.INPUT_BTN_39));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_40));
  output = output + String(digitalRead(constants.INPUT_BTN_40));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_41));
  output = output + String(digitalRead(constants.INPUT_BTN_41));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_42));
  output = output + String(digitalRead(constants.INPUT_BTN_42));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_43));
  output = output + String(digitalRead(constants.INPUT_BTN_43));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_44));
  output = output + String(digitalRead(constants.INPUT_BTN_44));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_45));
  output = output + String(digitalRead(constants.INPUT_BTN_45));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_46));
  output = output + String(digitalRead(constants.INPUT_BTN_46));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_47));
  output = output + String(digitalRead(constants.INPUT_BTN_47));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_48));
  output = output + String(digitalRead(constants.INPUT_BTN_48));
  //Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_49));
  output = output + String(digitalRead(constants.INPUT_BTN_49));
  //Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_50));
  output = output + String(digitalRead(constants.INPUT_BTN_50));
  //Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_51));
  output = output + String(digitalRead(constants.INPUT_BTN_51));
  //Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_52));
  output = output + String(digitalRead(constants.INPUT_BTN_52));
  //Serial.print(',');

  if (pcf8574.read(0) == 1) { //Serial.println("Led 1 is ON ");
    output = output + "1";
    //Serial.print("1");
  } else {
    output = output + "0";
    //Serial.print("0");
  }

  //  if (pcf8574.read(1) == 1){ //Serial.println("Led 1 is ON ");
  //    //Serial.print("1");
  //  }else{
  //    //Serial.print("0");
  //  }

  if (pcf8574.read(2) == 1) { //Serial.println("Led 1 is ON ");
    output = output + "1";
    //Serial.print("1");
  } else {
    output = output + "0";
    //Serial.print("0");
  }

  //  if (pcf8574.read(3) == 1){ //Serial.println("Led 1 is ON ");
  //    //Serial.print("1");
  //  }else{
  //    //Serial.print("0");
  //  }

  if (pcf8574.read(4) == 1) { //Serial.println("Led 1 is ON ");
    output = output + "1";
    //Serial.print("1");
  } else {
    output = output + "0";
    //Serial.print("0");
  }

  //  if (pcf8574.read(5) == 1){ //Serial.println("Led 1 is ON ");
  //    //Serial.print("1");
  //  }else{
  //    //Serial.print("0");
  //  }

  if (pcf8574.read(6) == 1) { //Serial.println("Led 1 is ON ");
    output = output + "1";
    //Serial.print("1");
  } else {
    output = output + "0";
    //Serial.print("0");
  }

  //  if (pcf8574.read(7) == 1){ //Serial.println("Led 1 is ON ");
  //    Serial.print("1");
  //  }else{
  //    Serial.print("0");
  //  }


  if (pcf8574A.read(0) == 1) { //Serial.println("Led 1 is ON ");
    output = output + "1";
    //Serial.print("1");
  } else {
    output = output + "0";
    //Serial.print("0");
  }

  //  if (pcf8574A.read(1) == 1){ //Serial.println("Led 1 is ON ");
  //    //Serial.print("1");
  //  }else{
  //    //Serial.print("0");
  //  }

  if (pcf8574A.read(2) == 1) { //Serial.println("Led 1 is ON ");
    output = output + "1";
    //Serial.print("1");
  } else {
    output = output + "0";
    //Serial.print("0");
  }

  //  if (pcf8574A.read(3) == 1){ //Serial.println("Led 1 is ON ");
  //    //Serial.print("1");
  //  }else{
  //    //Serial.print("0");
  //  }

  if (pcf8574A.read(4) == 1) { //Serial.println("Led 1 is ON ");
    output = output + "1";
    //Serial.print("1");
  } else {
    output = output + "0";
    //Serial.print("0");
  }

  //  if (pcf8574A.read(5) == 1){ //Serial.println("Led 1 is ON ");
  //    //Serial.print("1");
  //  }else{
  //    //Serial.print("0");
  //  }

  if (pcf8574A.read(6) == 1) { //Serial.println("Led 1 is ON ");
    output = output + "1";
    //Serial.print("1");
  } else {
    output = output + "0";
    //Serial.print("0");
  }

  //  if (pcf8574A.read(7) == 1){ //Serial.println("Led 1 is ON ");
  //    Serial.print("1");
  //  }else{
  //    Serial.print("0");
  //  }

  //Serial.println(output);
  float voltage9 = analogRead(constants.INPUT_LIGHT_25) * (5.0 / 1023.0);
  float voltage10 = analogRead(constants.INPUT_LIGHT_26) * (5.0 / 1023.0);
  float voltage11 = analogRead(constants.INPUT_LIGHT_27) * (5.0 / 1023.0);
  float voltage12 = analogRead(constants.INPUT_LIGHT_28) * (5.0 / 1023.0);
  float voltage13 = analogRead(constants.INPUT_LIGHT_29) * (5.0 / 1023.0);
  float voltage14 = analogRead(constants.INPUT_LIGHT_30) * (5.0 / 1023.0);
  float voltage15 = analogRead(constants.INPUT_LIGHT_31) * (5.0 / 1023.0);
  float voltage16 = analogRead(constants.INPUT_LIGHT_32) * (5.0 / 1023.0);

  if (voltage9 > 2.5) {
    output1 = output1 + "1";
  } else {
    output1 = output1 + "0";
  }

  if (voltage10 > 2.5) {
    output1 = output1 + "1";
  } else {
    output1 = output1 + "0";
  }

  if (voltage11 > 2.5) {
    output1 = output1 + "1";
  } else {
    output1 = output1 + "0";
  }

  if (voltage12 > 2.5) {
    output1 = output1 + "1";
  } else {
    output1 = output1 + "0";
  }

  if (voltage13 > 2.5) {
    output1 = output1 + "1";
  } else {
    output1 = output1 + "0";
  }

  if (voltage14 > 2.5) {
    output1 = output1 + "1";
  } else {
    output1 = output1 + "0";
  }

  if (voltage15 > 2.5) {
    output1 = output1 + "1";
  } else {
    output1 = output1 + "0";
  }

  if (voltage16 > 2.5) {
    output1 = output1 + "1";
    ////Serial.print("1");
  } else {
    output1 = output1 + "0";
    ////Serial.print("0");
  }

  ////Serial.print(digitalRead(constants.INPUT_BTN_33));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_33));
  ////Serial.print(',');
  ////Serial.print(digitalRead(constants.INPUT_BTN_34));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_34));
  ////Serial.print(',');
  ////Serial.print(digitalRead(constants.INPUT_BTN_35));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_35));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_36));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_36));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_37));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_37));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_38));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_38));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_39));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_39));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_40));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_40));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_41));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_41));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_42));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_42));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_43));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_43));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_44));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_44));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_45));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_45));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_46));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_46));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_47));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_47));
  ////Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_48));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_48));
  //Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_49));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_49));
  //Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_50));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_50));
  //Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_51));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_51));
  //Serial.print(',');
  //Serial.print(digitalRead(constants.INPUT_BTN_52));
  output1 = output1 + String(digitalRead(constants.INPUT_LIGHT_52));

  if (pcf8574.read(1) == 1) { //Serial.println("Led 1 is ON ");
    output1 = output1 + "1";
    //Serial.print("1");
  } else {
    output1 = output1 + "0";
    //Serial.print("0");
  }
  if (pcf8574.read(3) == 1) { //Serial.println("Led 1 is ON ");
    output1 = output1 + "1";
    //Serial.print("1");
  } else {
    output1 = output1 + "0";
    //Serial.print("0");
  }
  if (pcf8574.read(5) == 1) { //Serial.println("Led 1 is ON ");
    output1 = output1 + "1";
    //Serial.print("1");
  } else {
    output1 = output1 + "0";
    //Serial.print("0");
  }
  if (pcf8574.read(7) == 1) { //Serial.println("Led 1 is ON ");
    output1 = output1 + "1";
    //Serial.print("1");
  } else {
    output1 = output1 + "0";
    //Serial.print("0");
  }
  if (pcf8574A.read(1) == 1) { //Serial.println("Led 1 is ON ");
    output1 = output1 + "1";
    //Serial.print("1");
  } else {
    output1 = output1 + "0";
    //Serial.print("0");
  }
  if (pcf8574A.read(3) == 1) { //Serial.println("Led 1 is ON ");
    output1 = output1 + "1";
    //Serial.print("1");
  } else {
    output1 = output1 + "0";
    //Serial.print("0");
  }
  if (pcf8574A.read(5) == 1) { //Serial.println("Led 1 is ON ");
    output1 = output1 + "1";
    //Serial.print("1");
  } else {
    output1 = output1 + "0";
    //Serial.print("0");
  }
  if (pcf8574A.read(7) == 1) { //Serial.println("Led 1 is ON ");
    output1 = output1 + "1";
    //Serial.print("1");
  } else {
    output1 = output1 + "0";
    //Serial.print("0");
  }

  char * foutput = "";
  if(outputStat){
    foutput = output.c_str();
    strcat (foutput, "e");
    outputStat = false;
  }else{
    foutput = output1.c_str();
    strcat (foutput, "e");
    outputStat = true;
  }

  Serial.println(foutput);
  
  Serial3.println(foutput);
  delay(1000);
}
