#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5);  //BLE 통신
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  BTSerial.begin(9600); //무선연결(BLE)
  //Serial.begin(9600); //유선연결(시리얼모니터)
}

void loop() {
  if (BTSerial.available()) {
    int incomingByte = BTSerial.read();
    
    if(incomingByte == '1')
    {
      digitalWrite(LED_BUILTIN, HIGH);
      //Serial.println("ON");
    }
    else if(incomingByte == '0')
    {
      digitalWrite(LED_BUILTIN, LOW);
      //Serial.println("OFF"); 
    }
  }
}
