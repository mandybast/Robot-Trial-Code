
#include <AFMotor.h>

AF_DCMotor rightWheel(1, MOTOR12_64KHZ); //attached to Port 1
AF_DCMotor leftWheel(2, MOTOR12_64KHZ); //attached to Port 2
// so now we have 2 motors called "rightWheel" and "leftWheel"

void setup() {
Serial.begin(9600);
Serial.println("Motor test!");

rightWheel.setSpeed(200);    
leftWheel.setSpeed(200);
}

void loop() {
Serial.print("tick");

rightWheel.run(FORWARD);
leftWheel.run(FORWARD);
delay(1000);

Serial.print("tock");
rightWheel.run(BACKWARD);
leftWheel.run(BACKWARD);
delay(1000);

Serial.print("tack");
rightWheel.run(RELEASE);
leftWheel.run(RELEASE);
delay(1000);
}
