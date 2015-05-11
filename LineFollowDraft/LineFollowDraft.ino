#include "AFMotor.h"


#include "AFMotor.h"
AF_DCMotor motor_FL(1);
AF_DCMotor motor_FR(2);
int Left_Follow = 0;
int Right_Follow = 1;
int Center_Follow = 2;

int count=0;



void setup() {
  Serial.begin(9600);          
  motor_FL.run(RELEASE);
    motor_FL.setSpeed(0);
  motor_FR.run(RELEASE);
    motor_FR.setSpeed(0);
    

    
int x;
int y;
int z;
int s;
}

void AllForward(int x)
{
  motor_FL.run(FORWARD);
    motor_FL.setSpeed(x);
  motor_FR.run(FORWARD);
    motor_FR.setSpeed(x);
}

void TurnRight(int y)
{
  motor_FL.run(BACKWARD);
    motor_FL.setSpeed(y);
  motor_FR.run(FORWARD);
    motor_FR.setSpeed(y);
}

void TurnRRight(int s)
{
  motor_FL.run(RELEASE);
    motor_FL.setSpeed(0);
  motor_FR.run(FORWARD);
    motor_FR.setSpeed(s);
}

void TurnLeft(int z)
{
  motor_FL.run(FORWARD);
    motor_FL.setSpeed(z);
  motor_FR.run(BACKWARD);
    motor_FR.setSpeed(z);
}

  
  
void AllStop()
{
  motor_FL.run(RELEASE);
    motor_FL.setSpeed(0);
  motor_FR.run(RELEASE);
    motor_FR.setSpeed(0);
}
       

void loop() {
  int LeftDFR = digitalRead(Left_Follow);
  int CenterDFR = digitalRead(Center_Follow);
  int RightDFR = digitalRead(Right_Follow);
  Serial.println();
  Serial.println();
  Serial.print(LeftDFR);
  Serial.print(CenterDFR);
  Serial.print(RightDFR);
  Serial.print(count);
//For our sensor zero means it found the line!!
 

 
 switch (count) {
   case 0:
 {
  if(LeftDFR == 1 && CenterDFR == 0 && RightDFR == 1){
   AllForward(175);
 }
   else if(LeftDFR == 1 && CenterDFR == 1 && RightDFR == 0){
     TurnRight(125);
   }
   else if (LeftDFR == 1 && CenterDFR == 0 && RightDFR == 0){
     TurnRight(125);
   }
   else if(LeftDFR == 0 && CenterDFR == 1 && RightDFR == 1){
     TurnLeft(150);
   }
   else if(LeftDFR == 0 && CenterDFR == 0 && RightDFR == 1){
     TurnLeft(125);
   }
   else if(LeftDFR == 0 && CenterDFR == 0 && RightDFR == 0){
     AllStop();
     delay(1000);
     TurnRRight(225);
     delay(800);
     AllForward(100);
     delay(150);
     count++;
   }
 }
   
  break;
  
  case 1:
  {
  if(LeftDFR == 1 && CenterDFR == 0 && RightDFR == 1){
   AllForward(125);
 }
 if(LeftDFR == 1 && CenterDFR == 1 && RightDFR == 0){
   TurnRight(125);
 }
 if(LeftDFR == 0 && CenterDFR == 1 && RightDFR == 1){
   TurnLeft(125);
 }
 if(LeftDFR == 1 && CenterDFR == 0 && RightDFR == 0){
   AllStop();
     delay(1000);
     TurnRRight(220);
     delay(800);
   
   count++;
 }
 if(LeftDFR == 0 && CenterDFR == 0 && RightDFR == 0){
   AllStop();
     delay(1000);
     TurnRRight(220);
     delay(800);
   
   count++;
  }
  }
 
 break;
 
 case 2:
 {
 if(LeftDFR == 1 && CenterDFR == 0 && RightDFR == 1){
   AllForward(200);
 }
   if(LeftDFR == 0 && CenterDFR == 1 && RightDFR == 1){
     TurnLeft(150);
   }
   if(LeftDFR == 1 && CenterDFR == 0 && RightDFR == 0){
     TurnRight(150);
   }
   if(LeftDFR == 1 && CenterDFR == 1 && RightDFR == 0){
   TurnRight(150);
   }
   if(LeftDFR == 0 && CenterDFR == 0 && RightDFR == 0){
   TurnLeft(225);
   delay(600);
   count++;
   }
 }
   
   
 
 break;
 
 case 3:
 {
 if(LeftDFR == 1 && CenterDFR == 0 &&RightDFR == 1){
 AllForward(200);
}
if(LeftDFR == 1 && CenterDFR == 1 && RightDFR == 0){
   TurnRight(150);
}
if(LeftDFR == 0 && CenterDFR == 1 && RightDFR == 1){
   TurnLeft(150);
}
if(LeftDFR == 0 && CenterDFR == 0 && RightDFR == 0){
   
  TurnRight(200);
  count=0;
}
 }

   break;
 
 
 
 /*else{
  motor_FL.run(RELEASE);
    motor_FL.setSpeed(0);
  motor_FR.run(RELEASE);
    motor_FR.setSpeed(0);*/
 
}
 }


