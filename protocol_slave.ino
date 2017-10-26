const char slaveId = 51;
char readBuffer[4];

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);    
}

void loop()
{
  
  if (Serial.available()>0) {
      Serial.readBytes(readBuffer, 4);
     
    if(readBuffer[0]==63 && readBuffer[3]==35) {
      if(readBuffer[1]==slaveId) {
        if (readBuffer[2] == 72)
        {
          digitalWrite(13, HIGH);
          Serial.write("?0H#");
        }
        else if (readBuffer[2] == 76)
        {
          digitalWrite(13, LOW);
          Serial.write("?0L#");
        }
        delay(50);
      } else {
        Serial.end();
        delay(50);
        Serial.begin(9600);
      }
     }
   
  }
  

}
