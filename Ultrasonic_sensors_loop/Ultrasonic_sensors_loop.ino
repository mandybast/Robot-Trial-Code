//Plant height measurement loop 
int trigPin1 = 8;
int echoPin1 = 7;
int trigPin2 = 6;
int echoPin2 = 5;
float v = 331.5+0.6*20; // m/s

boolean TallPlant = false;
boolean ShortPlant = false;

void setup() 
{
  Serial.begin(115200);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT); 

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
}

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




void loop () 
{
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
   
  delay(200); //ms
}

