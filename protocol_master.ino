#include <SoftwareSerial.h>

SoftwareSerial deviceSerial(5, 6);


void setup(){
  Serial.begin(9600);
  deviceSerial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

int buttonState1 = 0;
int lastButtonState1 = 0;

int buttonState2 = 0;
int lastButtonState2 = 0;

int buttonState3 = 0;
int lastButtonState3 = 0;

void loop(){
  // message frame
  // ?1L#
  // Serial.write("?1L#");

  buttonState1 = digitalRead(10);
  buttonState2 = digitalRead(11);
  buttonState3 = digitalRead(12);
  
  //button 1
  if(buttonState1!=lastButtonState1) {
    if(buttonState1==HIGH) {
      deviceSerial.write("?1H#");
      Serial.write("?1H#");
    } else {
      deviceSerial.write("?1L#");
      Serial.write("?1L#");
    }
  }
  
  lastButtonState1=buttonState1;

  
  //button 2
  if(buttonState2!=lastButtonState2) {
    if(buttonState2==HIGH) {
      deviceSerial.write("?2H#");
      Serial.write("?2H#");
    } else {
      deviceSerial.write("?2L#");
      Serial.write("?2L#");
    }
  }
  
  lastButtonState2=buttonState2;
  
  
  //button 3
  if(buttonState3!=lastButtonState3) {
    if(buttonState3==HIGH) {
      deviceSerial.write("?3H#");
      Serial.write("?3H#");
    } else {
      deviceSerial.write("?3L#");
      Serial.write("?3L#");
    }
  }
  
  lastButtonState3=buttonState3;

delay(50);

if (deviceSerial.available()) {
    Serial.write(deviceSerial.read());
  }
}
