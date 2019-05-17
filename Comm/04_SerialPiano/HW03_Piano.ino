int speaker = 3;
int c = 262;
int d = 294;
int e = 330;
int f = 349;
int g = 392;
int a = 440;
int b = 466; // 플랫
int c2 = 523;
int d2 = 587;
int incomingByte = 0;

void setup(){
  Serial.begin(9600);  
}

void loop(){
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if(incomingByte == '1')
    {
         tone(speaker, c, 500);
    }
    else if(incomingByte == '2')
    {
         tone(speaker, d, 500);
    }
    else if(incomingByte == '3')
    {
         tone(speaker, e, 500);
    }
    else if(incomingByte == '4')
    {
         tone(speaker, f, 500);
    }
    else if(incomingByte == '5')
    {
         tone(speaker, g, 500);
    }
    else if(incomingByte == '6')
    {
         tone(speaker, a, 500);
    }
    else if(incomingByte == '7')
    {
         tone(speaker, b, 500);
    }
    else if(incomingByte == '8')
    {
         tone(speaker, c2, 500);
    }
    else if(incomingByte == '9')
    {
         tone(speaker, d2, 500);
    }
  }
}

