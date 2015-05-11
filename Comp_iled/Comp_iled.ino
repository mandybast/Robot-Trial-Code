#include "AFMotor.h" //for motors
#include "TimerOne.h" //for color sensor


AF_DCMotor leftWheel(1);
AF_DCMotor rightWheel(2);
int leftSensor = 0;
int middleSensor = 1;
int rightSensor = 2;
int count=0;

void setup() {
  Serial.begin(115200);
  leftWheel.run(RELEASE);
  leftWheel.setSpeed(0);
  rightWheel.run(RELEASE);
  rightWheel.setSpeed(0);
  
  TSC_Init();
  Serial.begin(115200);
  Timer1.initialize();             // defaulte is 1s
  Timer1.attachInterrupt(TSC_Callback);  
  attachInterrupt(0, TSC_Count, RISING);  
 
  delay(4000);
 
  for(int i=0; i<3; i++)
    Serial.println(g_array[i]);
 
  g_SF[0] = 255.0/ g_array[0];     //R Scale factor
  g_SF[1] = 255.0/ g_array[1] ;    //G Scale factor
  g_SF[2] = 255.0/ g_array[2] ;    //B Scale factor
 
  Serial.print("-> Scale Factor R=");
  Serial.println(g_SF[0]);
  Serial.print("-> Scale Factor G=");
  Serial.println(g_SF[1]);
  Serial.print("-> Scale Factor B=");
  Serial.println(g_SF[2]);
  
  delay(200);
  
  Serial.begin(115200);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT); 

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
}


 
//COLOR SENSOR LOOP
/***************
Arduino UNO                                Color Sensor
Digital 6                 -                     S0
Digital 5                 -                     S1  
Digital 4                 -                    S2
Digital 3                 -                     S3
Digital 2                 -                     OUT
VCC                      -                     VCC
GND                      -                    GND*/
 
#define S0     6   // Please notice the Pin's define
#define S1     5
#define S2     4
#define S3     3
#define OUT    2
 
int   g_count = 0;    // count the frequecy
int   g_array[3];     // store the RGB value
int   g_flag = 0;     // filter of RGB queue
float g_SF[3];        // save the RGB Scale factor
int color = 0;
int green = 1;
int brown = 2;
int yellow = 3;
 

//initial declaration so it can be called anywhere
void ShouldIGetThePlant(boolean Tall, boolean Short, int Color);

// Init TSC b230 and setting Frequency.
void TSC_Init()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
 
  digitalWrite(S0, LOW);  // OUTPUT FREQUENCY SCALING 2%
  digitalWrite(S1, HIGH); 
}
 
// Select the filter color 
void TSC_FilterColor(int Level01, int Level02)
{
  if(Level01 != 0)
    Level01 = HIGH;
 
  if(Level02 != 0)
    Level02 = HIGH;
 
  digitalWrite(S2, Level01); 
  digitalWrite(S3, Level02); 
}
 
void TSC_Count()
{
  g_count ++ ;
}
 
void TSC_Callback()
{
  switch(g_flag)
  {
    case 0: 
         Serial.println("->WB Start");
         TSC_WB(LOW, LOW);              //Filter without Red
         break;
    case 1:
         Serial.print("->Frequency R=");
         Serial.println(g_count);
         g_array[0] = g_count;
         TSC_WB(HIGH, HIGH);            //Filter without Green
         break;
    case 2:
         Serial.print("->Frequency G=");
         Serial.println(g_count);
         g_array[1] = g_count;
         TSC_WB(LOW, HIGH);             //Filter without Blue
         break;
 
    case 3:
         Serial.print("->Frequency B=");
         Serial.println(g_count);
         Serial.println("->WB End");
         g_array[2] = g_count;
         TSC_WB(HIGH, LOW);             //Clear(no filter)   
         break;
   default:
         g_count = 0;
         break;
  }
}
 
void TSC_WB(int Level0, int Level1)      //White Balance
{
  g_count = 0;
  g_flag ++;
  TSC_FilterColor(Level0, Level1);
  Timer1.setPeriod(1000000);             // set 1s period
}

void ShouldIGetThePlant(boolean Tall, boolean Short, int Color)
{
  Serial.println("Asking myself if I should grab the plant");
  if( (Tall || Short))
  {
    switch(Color)//Color = 1,2,3 (green,brown,yellow)
    {
      case 1: //green
        if(Tall && array[TallGreen] == 0)//if I dont have a tall green plant and this is one
        {
          Serial.println("Found a new tall green plant");
          array[TallGreen] = 1; // I now have this plant
         // GrabThePlant();
        }
        else if(Short && array[ShortGreen] == 0)//if I dont have a tall green plant and this is one
        {
          Serial.println("Found a new short green plant");
          array[ShortGreen] = 1; // I now have this plant
          //GrabThePlant();
        }
        else
        {
          String plantSize = Tall == true ? "tall" : "short";
          Serial.println("I already have this "+ plantSize +" green plant");
        }
        break;
        
      case 2: //brown
        if(Tall && array[TallBrown] == 0)//if I dont have a tall brown plant and this is one
        {
          Serial.println("Found a new tall brown plant");
          array[TallBrown] = 1; // I now have this plant
         // GrabThePlant();
        }
        else if(Short && array[ShortBrown] == 0)//if I dont have a tall Brown plant and this is one
        {
          Serial.println("Found a new short brown plant");
          array[ShortBrown] = 1; // I now have this plant
         // GrabThePlant();
        }
        else
        {
          String plantSize = Tall == true ? "tall" : "short";
          Serial.println("I already have this "+ plantSize +" brown plant");
        }
        break;
      case 3: //yellow
        if(Tall && array[TallYellow] == 0)//if I dont have a tall Yellow plant and this is one
        {
          Serial.println("Found a new tall yellow plant");
          array[TallYellow] = 1; // I now have this plant
         // GrabThePlant();
        }
        else if(Short && array[ShortYellow] == 0)//if I dont have a tall yellow plant and this is one
        {
          Serial.println("Found a new short yellow plant");
          array[ShortYellow] = 1; // I now have this plant
          //GrabThePlant();
        }
        else
        {
          String plantSize = Tall == true ? "tall" : "short";
          Serial.println("I already have this "+ plantSize +" yellow plant");
        }
        break;
       default:
       Serial.println("The color sensor did not detect a color it knows");
         break;
    }
  }
  else
  {
    Serial.println("The height sensor did not detect a plant within range");
  }
  
  
}

//Plant height measurement loop 
int trigPin1 = 10;
int echoPin1 = 9;
int trigPin2 = 8;
int echoPin2 = 7;
float v = 331.5+0.6*20; // m/s

boolean TallPlant = false;
boolean ShortPlant = false;


float DistanceM1() {
  //Send sound pulse
  
digitalWrite(trigPin1, LOW);
delayMicroseconds(3);
digitalWrite(trigPin1,HIGH);
delayMicroseconds(5);
digitalWrite(trigPin1, LOW);

//listen for echo

float t1Us1 = pulseIn(echoPin1, HIGH); //microseconds
float t1 = t1Us1 / 1000.0 / 1000.0 / 2; //s
float dists = t1*v ;
return dists*100; //cm
}


float DistanceM2() {
  //Send sound pulse
  
digitalWrite(trigPin2, LOW);
delayMicroseconds(3);
digitalWrite(trigPin2,HIGH);
delayMicroseconds(5);
digitalWrite(trigPin2, LOW);

//listen for echo

float t2Us2 = pulseIn(echoPin2, HIGH); //microseconds
float t2 = t2Us2 / 1000.0 / 1000.0 / 2; //s
float distt = t2*v ;
return distt*100; //cm
}

int isdistsInRange(float dists)
{
	if(dists > 10 && dists < 50)
		return 1;
	return 0;
}

int isdisttInRange(float distt)
{
	if(distt > 10 && distt < 50)
		return 1;
	return 0;
}


void loop() 
{  //LINE FOLLOW LOOP
  void secondloop(); //run color sensor loop at the same time
  
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
      else if(leftValue == 1 && middleValue == 1 && rightValue == 0)
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
      else if(leftValue == 1 && middleValue == 0 && rightValue == 1)
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
        else if(leftValue == 0 && middleValue == 1 && rightValue == 1)
        {
          leftWheel.run(BACKWARD);
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
        else if(leftValue == 1 && middleValue == 1 && rightValue == 1)
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
        else if(leftValue == 0 && middleValue == 0 && rightValue == 1)
        {
          leftWheel.run(FORWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(BACKWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 1 && middleValue == 1 && rightValue == 1)
        {
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
        }
        else if(leftValue == 1 && middleValue == 0 && rightValue == 0)
        {
          leftWheel.run(BACKWARD);
          leftWheel.setSpeed(40);
          rightWheel.run(FORWARD);
          rightWheel.setSpeed(40);
          count=0;
        }
        }
      }
      break;
  }
}


void secondloop () 
{//COLOR SENSOR LOOP
   color = 0;
   g_flag = 0;
   for(int i=0; i<3; i++)
    Serial.println(int(g_array[i] * g_SF[i]));

 Serial.print("Color sensor detects");
 if(g_array[0] < 625 && g_array[0] > 310 && g_array[1] < 438 && g_array[1]>231 && g_array[2]<401 && g_array[2]>196  ) //These are the ranges of RGB freqencies that occur for the color brown
 {
   color = brown;
   Serial.println(" - Brown Plant ");

 }
 else if(g_array[0] < 584 && g_array[0] > 439 && g_array[1] < 399 && g_array[1]>331 && g_array[2]<425 && g_array[2]>333 ) //These are the ranges of RGB freqencies that occur for the color green
 {
      color = green;
   Serial.println(" - Green Plant ");
 }
 
  else if(g_array[0] < 625 && g_array[0] > 310 && g_array[1] < 438 && g_array[1]>231 && g_array[2]<401 && g_array[2]>196 ) //These are the ranges of RGB freqencies that occur for the color yellow
 {
      color = yellow;
   Serial.println(" - Yellow Plant ");     
 }
 
 else //if none of the values are within a plant color range  the main loop of the program keeps going
 {
   color = 0;
    Serial.println("  - No Plant "); 
 } 
 delay(20);

  int dists = DistanceM1();
  int distt = DistanceM2();
  
  Serial.print("High ");
  Serial.print(dists,DEC);
  Serial.print(' ');
  Serial.print("Low ");
  Serial.print(distt,DEC);
  
 
 
 if(isdistsInRange(dists) == 1 && isdisttInRange(distt) == 1 ) //if both the top and middle Ultrasonic sensor sense the plant, it is tall
 {
  	TallPlant = true;
        ShortPlant=false;
   Serial.println(" - Tall Plant ");

 }
 else if(isdistsInRange(dists) == 1 && isdisttInRange(distt) == 0 ) //if only the middle Ultrasonic sensor senses the plant, it is short
 {
     TallPlant = false;
      ShortPlant = true;
     Serial.println("  - Short Plant ");

 }
 else 
 {
   TallPlant = false;
   ShortPlant = false;
 }
 if(TallPlant == true || ShortPlant == true) 
 {
       
 }
 else //if niether of them sense a plant the main loop of the program keeps going
 
 {
   TallPlant = false;
   ShortPlant = false;
    Serial.println("  - No Plant ");

 }
 //ShortPlant = true;
 //color = 1;//1,2,3
 ShouldIGetThePlant(TallPlant, ShortPlant, color);
  delay(200); //ms
}


 

 
 



int array[6];
int TallGreen = 0;
int ShortGreen = 1;
int TallBrown = 2;
int ShortBrown = 3;
int TallYellow = 4;
int ShortYellow = 5;

/*void GrabThePlant()
{
  //use the claw
  //pick up block 
  //drop in basket.
  
}
*/
