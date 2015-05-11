#include "AFMotor.h"

AF_DCMotor leftWheel(1);
AF_DCMotor rightWheel(2);
int leftSensor = 0;
int middleSensor = 1;
int rightSensor = 2;
int count=0;

void setup() {
  Serial.begin(9600);
  leftWheel.run(RELEASE);
  leftWheel.setSpeed(0);
  rightWheel.run(RELEASE);
  rightWheel.setSpeed(0);
}

void loop() {
  int leftValue = digitalRead(leftSensor);
  int middleValue = digitalRead(middleSensor);
  int rightValue = digitalRead(rightSensor);
  
  switch (count) {
    case 0:
    {
      if(leftValue == 0 && middleValue == 1 && rightValue == 0)
      {
        leftWheel.run(FORWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(FORWARD);
        rightWheel.setSpeed(40);
      }
      else if(leftValue == 0 && middleValue == 0 && rightValue == 1)
      {
        leftWheel.run(BACKWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(FORWARD);
        rightWheel.setSpeed(40);
      }
      else if(leftValue == 0 && middleValue == 1 && rightValue == 1)
      {
        leftWheel.run(BACKWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(FORWARD);
        rightWheel.setSpeed(40);
      }
      else if(leftValue == 1 && middleValue == 1 && rightValue == 0)
      {
        leftWheel.run(FORWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(BACKWARD);
        rightWheel.setSpeed(40);
      }
      else if(leftValue == 1 && middleValue == 0 && rightValue == 0)
      {
        leftWheel.run(FORWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(BACKWARD);
        rightWheel.setSpeed(40);
      }
      else if(leftValue == 1 && middleValue == 1 && rightValue == 1)
      {
        leftWheel.run(RELEASE);
        leftWheel.setSpeed(0);
        rightWheel.run(RELEASE);
        rightWheel.setSpeed(0);
        delay(1000);
        leftWheel.run(BACKWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(FORWARD);
        rightWheel.setSpeed(40);
        delay(1000);
        leftWheel.run(FORWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(FORWARD);
        rightWheel.setSpeed(40);
        delay(1000);
        count++;
      }
    }

    break;
    case 1:
      {
      if(leftValue == 0 && middleValue == 1 && rightValue == 0)
        {
        leftWheel.run(FORWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(FORWARD);
        rightWheel.setSpeed(40);
        }
      else if(leftValue == 0 && middleValue == 1 && rightValue == 1)
        {
        leftWheel.run(BACKWARD);
        leftWheel.setSpeed(40);
        rightWheel.run(FORWARD);
        rightWheel.setSpeed(40);
        }
      else if(leftValue == 1 && middleValue == 0 && rightValue == 1)
        {
          leftWheel.run(FORWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(BACKWARD);
          rightWheel.setSpeed(40);
        }
      else if(leftValue == 0 && middleValue == 1 && rightValue == 1)
        {
          leftWheel.run(RELEASE);
          leftWheel.setSpeed(0);
          rightWheel.run(RELEASE);
          rightWheel.setSpeed(0);
          delay(1000);
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
          delay(1000);
          count++;
        }
      if(leftValue == 1 && middleValue == 1 && rightValue == 1)
        {
          leftWheel.run(RELEASE);
          leftWheel.setSpeed(0);
          rightWheel.run(RELEASE);
          rightWheel.setSpeed(0);
          delay(1000);
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
          delay(100);
          count++;
        }
    break;

    case 2:
      {
        if(leftValue == 0 && middleValue == 1 && rightValue == 0)
        {
          leftWheel.run(FORWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 1 && middleValue == 0 && rightValue == 0)
        {
          leftWheel.run(FORWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(BACKWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 0 && middleValue == 1 && rightValue == 1)
        {
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 0 && middleValue == 1 && rightValue == 1)
        {
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 1 && middleValue == 1 && rightValue == 1)
        {
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
        }
        delay(1000);
        count++;
      }
      }
      break;
      
      case 3:
      {
        if(leftValue == 0 && middleValue == 1 && rightValue == 0)
        {
          leftWheel.run(FORWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(BACKWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 0 && middleValue == 0 && rightValue == 1)
        {
          leftWheel.run(FORWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(BACKWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 1 && middleValue == 0 && rightValue == 0)
        {
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 1 && middleValue == 1 && rightValue == 1)
        {
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
          count=0;
        }
      }
      break;
  }
}
