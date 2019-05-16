#include <SoftwareSerial.h>

//SoftwareSerial BTSerial(4, 5);

int in1 = 9;
int in2 = 6;
int enA = 5;

int in3 = 10;
int in4 = 11;
int enB = 3;


int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);  
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);    
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);    
  pinMode(in4, OUTPUT);

  // Set initial rotation direction
  // forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Initial speed
  motorSpeedA = 128;// 0~255
  motorSpeedB = 128;
}
 
void loop() {
  
  analogWrite(enA, motorSpeedA);
  analogWrite(enB, motorSpeedB);// Send PWM signal to motor A
  
}



void serialEvent() {
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    if(inChar == '0')
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      
    }
    else if(inChar == 'f')
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if(inChar == 'b')
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      
    }
    else if(inChar == 'w')
    {
      motorSpeedA = motorSpeedA + 50; //10
      motorSpeedB = motorSpeedB + 50; //10
   
      if (motorSpeedA > 255 and motorSpeedB > 255) 
      {
        motorSpeedA = 255;
        motorSpeedB = 255;
      }
      
      Serial.println(motorSpeedA);
      Serial.println(motorSpeedB);
      
    }
    else if(inChar == 's')
    {
      motorSpeedA = motorSpeedA - 50; //10
      motorSpeedB = motorSpeedB - 50; //10
   
      if (motorSpeedA < 0 and motorSpeedB < 0) 
      {
        motorSpeedA = 0;
        motorSpeedB = 0;
      }
      
      Serial.println(motorSpeedA);
      Serial.println(motorSpeedB);
    }




    
  }
}
