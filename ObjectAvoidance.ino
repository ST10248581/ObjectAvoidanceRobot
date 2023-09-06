#include <AFMotor.h>

// Defines Pins for sensors
#define Trig 12
#define Echo 13

//Defines pins for motor drive module
//Motor One
#define ENA 5
#define IN1 3
#define IN2 4
// Motor Two
#define ENB 6
#define IN3 2
#define IN4 7

// Stores distance of object from sensor
float cm; 
// Temp for calculating distance
float temp; 

void setup() {

  Serial.begin(9600);

  // Assigns sensor pins to input and output
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  // Assigns motor pins to output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {

  // Sends signal (sound) out of ultrasonic sensor
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  // Reads the signal back
  temp = float(pulseIn(Echo, HIGH));
  //Uses temp to calculate distance of object from sensor
  cm = (temp * 17 ) / 1000;


  if (cm < 30 && cm > 10)
  {
    back();
    delay(500);
      Left();
    delay(200);
  }

  if (cm >= 30)
  {
    forward();
    delay(100);
  }


  if (cm < 10 && cm > 3)
  {
    delay(500);
    back();
  }

  if(cm < 3 ){
    STOP();
  }


  Serial.print("Echo =");
  Serial.print(temp);
  Serial.print(" | | Distance = ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100);
}

void forward() {
  // Turns motor on at speed 240
  analogWrite(ENA, 240);
  analogWrite(ENB, 240);

  //Motor One foward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Motor Two foward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void back() {
  // Turns motor on at speed 240
  analogWrite(ENA, 240);
  analogWrite(ENB, 240);
  
  //Motor one Backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Motor Two Backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}


void Right() {
  // Turns motor on at speed 240
  analogWrite(ENA, 240);
  analogWrite(ENB, 240);

  // Motor One Bakcward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Motor Two Foward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Left");
}

void Left() {
  // Turns motor on at speed 240
  analogWrite(ENA, 240);
  analogWrite(ENB, 240);

  // Motor One Foward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Motor Two Backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}

void STOP() {
  // Everything is low, both motors stop
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("STOP");
}
