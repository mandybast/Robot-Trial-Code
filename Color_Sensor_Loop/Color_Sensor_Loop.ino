/***************
Arduino UNO                                Color Sensor
Digital 6                 -                     S0
Digital 5                 -                     S1  
Digital 4                 -                    S2
Digital 3                 -                     S3
Digital 2                 -                     OUT
VCC                      -                     VCC
GND                      -                    GND*/

#include "TimerOne.h"
 
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
 
 
// Init TSC230 and setting Frequency.
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
 
void setup()
{
  TSC_Init();
  Serial.begin(9600);
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
 
}
 
void loop()
{
   g_flag = 0;
   for(int i=0; i<3; i++)
    Serial.println(int(g_array[i] * g_SF[i]));


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

 delay(4000);
}
