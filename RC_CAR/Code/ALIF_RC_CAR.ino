  const int motorAspeed  = 3;
  const int motorA1      = 4;  
  const int motorA2      = 5;  
  const int motorB1      = 6;
  const int motorB2      = 7; 
  const int motorBspeed  = 8;

  int command;    
  int vSpeed=200;     
void setup() {  
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT); 
    
    Serial.begin(9600); 

  } 

void goAhead(){
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,HIGH);                       
  delay(1);
  
  digitalWrite (motorB1,HIGH);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
  }

void goAheadLeft(){
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,HIGH);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
    }

void goAheadRight(){
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,HIGH);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, vSpeed);
    }

void goBack(){
  digitalWrite (motorA1,HIGH);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }

void goBackLeft(){
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, vSpeed);
    }
void goBackRight(){
  digitalWrite (motorA1,HIGH);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
    }
void goLeft(){
  digitalWrite (motorA2,HIGH);
  delay(1);
  digitalWrite(motorA1,LOW);                       
  delay(1);
  
  digitalWrite (motorB2,HIGH);
  delay(1);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }

void goRight(){
  digitalWrite (motorA2,LOW);
  delay(1);
  digitalWrite(motorA1,HIGH);                       
  delay(1);
  
  digitalWrite (motorB2,LOW);
  delay(1);
  digitalWrite(motorB1,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);    
    }

   
void stopRobot(){
   analogWrite(motorA1, 0);           analogWrite(motorA2, 0); 
   analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }
    
  
void loop(){
  
if (Serial.available() > 0) {
  command = Serial.read();
  stopRobot();  


switch (command) {
case 'F':goAhead();break;
case 'B':goBack();break;
case 'L':goLeft();break;
case 'R':goRight();break;
case 'I':goAheadRight();break;
case 'G':goAheadLeft();break;
case 'J':goBackRight();break;
case 'H':goBackLeft();break;
case 'D':stopRobot();break;
case '0':vSpeed = 0;break;
case '1':vSpeed = 25.5;break;
case '2':vSpeed = 51;break;
case '3':vSpeed = 76.5;break;
case '4':vSpeed = 102;break;
case '5':vSpeed = 127.5;break;
case '6':vSpeed = 153;break;
case '7':vSpeed = 178.5;break;
case '8':vSpeed = 204;break;
case '9':vSpeed = 229.5;break;
case 'q':vSpeed = 255;break;
         
}
}
}
