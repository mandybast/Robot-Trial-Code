#include "Servo.h"
 
//Servo GripMotor;  // create servo objects to control a servo 
Servo WristMotor;            
 
float pos = 90;    // variable to store the servo position 

void setup() 
{ 
 // GripMotor.attach(10);  // attaches the servo on pin 10 to the servo object 
  WristMotor.attach(10);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  
  for(pos = 170; pos>= 20; pos-=pos)     // goes from 180 degrees to 0 degrees 
  {                                
   // GripMotor.write(pos);              // tell servo to go to position in variable 'pos' 
   // delay(15);                       // waits 15ms for the servo to reach the position 
    WristMotor.write(pos);  
    delay(15);       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  for(pos = 20; pos <= 170; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
   // GripMotor.write(pos);              // tell servo to go to position in variable 'pos' 
    //delay(15);       // waits 15ms for the servo to reach the position
    WristMotor.write(pos);  
    delay(15);       // waits 15ms for the servo to reach the position
  } 
} 
