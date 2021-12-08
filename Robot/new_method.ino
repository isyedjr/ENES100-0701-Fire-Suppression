#include "Enes100.h"
#include <math.h> 

int RightTrigPin=52;
int RightEchoPin=53;
int RightPingTravelTime;

int LeftTrigPin=51;
int LeftEchoPin=50;
int LeftPingTravelTime;


void forward(){
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);
 }

void reverse(){
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  }

void left(){
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  }

void right(){
   digitalWrite(11, HIGH);
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   digitalWrite(10, LOW);
  }

void Stop(){
   digitalWrite(11, LOW);
   digitalWrite(13, LOW);
   digitalWrite(12, LOW);
   digitalWrite(10, LOW);
  }


//setup
 void setup(){
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
 
  Enes100.begin("SWAT2", FIRE, 11, 6, 7);

 }



void loop(){
 
  if(Enes100.location.y > 1){

    float desired= Enes100.location.theta- (-1.5);
    float time=  763.4* desired;
    right();
    delay(time);
    
    }
   else{
    
    float desired= Enes100.location.theta- (1.5);
    float time=  763.4* desired;
    right();
    delay(time);
    
    }

    Stop();
    foward();
    //for how long?
    
  
}
