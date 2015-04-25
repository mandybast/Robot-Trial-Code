int leftInput = 4;
int rightInput = 13;
int middleInput = 8;
int leftMotor = 10;
int rightMotor = 9;
int leftValue = 0;
int rightValue = 0;
int middleValue = 0;

void setup()
{
  pinMode (leftMotor, OUTPUT);
  pinMode (rightMotor, OUTPUT);
}

void loop()
{
  leftValue = analogRead (leftInput);
  rightValue = analogRead (rightInput);

 if
   (middleValue == LOW) //middle sensor is on the line
   {
     digitalWrite (leftMotor, HIGH);
     digitalWrite (rightMotor, HIGH);
     Serial.print("Middle sensor on the line");
   }
   else
   {
     if
     (leftValue == LOW && rightValue == HIGH) //left sensor on line
    {
      digitalWrite (leftMotor, LOW);
      digitalWrite (rightMotor, HIGH);
      Serial.print("left sensor is on the line");
    }
 else {
   if (leftValue == HIGH && rightValue == LOW) //right sensor on line
   {
   digitalWrite (rightMotor, HIGH);
   digitalWrite (leftMotor, LOW);
   Serial.print("right sensor is on the line");
   }
   else
   {
     if (leftValue == LOW && rightValue == LOW) //both sensors on line
     {
       digitalWrite (rightMotor, LOW);
       digitalWrite (leftMotor, LOW);
       Serial.print("All sensors are on the line!");
     }
   }
 }
   }
}
