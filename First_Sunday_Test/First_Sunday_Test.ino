#include "AFMotor.h"

AF_DCMotor leftWheel(1); //motor 1 on port 1
AF_DCMotor rightWheel(2); //motor 2 on port 2

int leftInput = 0;
int middleInput = 1;
int rightInput = 2;

void setup()
{
  Serial.begin(9600);
  leftWheel.run(FORWARD);
  leftWheel.setSpeed(100);
  rightWheel.run(FORWARD);
  rightWheel.setSpeed(100);
}

void loop() {
  
  int leftSensor = digitalRead(leftInput);
  int middleSensor = digitalRead(middleInput);
  int rightSensor = digitalRead(rightInput);
  
  Serial.println(leftSensor);
  Serial.println(rightSensor);
  Serial.println(middleSensor);
  
  if(middleSensor == 0)
  {
    leftWheel.run(FORWARD);
    leftWheel.setSpeed(200);
    rightWheel.run(FORWARD);
    rightWheel.setSpeed(200);
    delay(1000);
  }
  else
  {
    leftWheel.run(BACKWARD);
    leftWheel.setSpeed(100);
    rightWheel.run(BACKWARD);
    rightWheel.setSpeed(100);
    delay(1000);
  }
}
