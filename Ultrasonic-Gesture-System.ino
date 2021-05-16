const int trigger1 = 2; 
const int echo1 = 3; 
const int trigger2 = 4; 
const int echo2 = 5;
const int led1=6;
const int led2=7;

long time_taken;
int dist,distL,distR;

void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
}

void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>50)
dist = 50;
}

void loop() { 
calculate_distance(trigger1,echo1);
distL =dist; 

calculate_distance(trigger2,echo2);
distR =dist; 



if ((distL >40 && distR>40) && (distL <50 && distR<50))
{
Serial.println("Play/Pause"); delay (500);}

calculate_distance(trigger1,echo1);
distL =dist;

calculate_distance(trigger2,echo2);
distR =dist;

if (distL>=13 && distL<=17)
{
  delay(100); 
  calculate_distance(trigger1,echo1);
  distL =dist;
  if (distL>=13 && distL<=17)
  {
    Serial.println("Left Locked");
    digitalWrite(led1,HIGH);
    while(distL<=40)
    {
      calculate_distance(trigger1,echo1);
      distL =dist;
      if (distL<10) 
      {Serial.println ("Vup"); delay (300);}
      if (distL>20)
      {Serial.println ("Vdown"); delay (300);}
    }
    digitalWrite(led1,LOW);
  }
}


if (distR>=13 && distR<=17)
{
  delay(100); 
  calculate_distance(trigger2,echo2);
  distR =dist;
  if (distR>=13 && distR<=17)
  {
    Serial.println("Right Locked");
    digitalWrite(led2,HIGH);
    while(distR<=40)
    {
      calculate_distance(trigger2,echo2);
      distR =dist;
      if (distR<10)
      {Serial.println ("Rewind"); delay (300);}
      if (distR>20) 
      {Serial.println ("Forward"); delay (300);}
    }
    digitalWrite(led2,LOW);
  }
}

delay(200);
}
