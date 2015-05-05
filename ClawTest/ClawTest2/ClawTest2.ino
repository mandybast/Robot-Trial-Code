#include <Servo.h> 
 
Servo GripMotor;  // create servo objects to control a servo 
Servo WristMotor;            
 
int pos = 35;    // variable to store the servo position 

void setup() 
{ 
  GripMotor.attach(10);  // attaches the servo on pin 10 to the servo object 
  WristMotor.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  for(pos = 35; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    GripMotor.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);       // waits 15ms for the servo to reach the position
    WristMotor.write(pos);  
    delay(15);       // waits 15ms for the servo to reach the position
  } 
  for(pos = 180; pos>=35; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    GripMotor.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
    WristMotor.write(pos);  
    delay(15);       // waits 15ms for the servo to reach the position
  } 
} 
