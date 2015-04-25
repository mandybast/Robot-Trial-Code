#include <Servo.h> // include the Servo library

// create the servo objects
Servo leftMotor;
Servo rightMotor;

void setup()
{
  leftMotor.attach(10);  // attaches the servo on pin 10 to a servo object
  rightMotor.attach(9); // attaches the servo on pin 9 to a servo object
}

void loop()
{
  leftMotor.write(180);  // left motor is going in the wrong direction 
  rightMotor.write(0);  // Have to code opposite for left motor 
}
