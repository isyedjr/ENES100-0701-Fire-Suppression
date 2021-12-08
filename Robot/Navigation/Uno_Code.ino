#include "Enes100.h"
#include <math.h> 

int RightTrigPin=52;
int RightEchoPin=53;
int RightPingTravelTime;

int LeftTrigPin=51;
int LeftEchoPin=50;
int LeftPingTravelTime;

void rotateBy(float radians){
  
  Enes100.updateLocation();
  float current= Enes100.location.theta;
  
  //rotate left
        if (radians<0){
        //(Alternate code) Enes100.location.theta>goal+.01 ||Enes100.location.theta<goal-.01
          while(fabs(Enes100.location.theta-current)<fabs(radians)){
             left();
             Enes100.updateLocation();
          }
        }
  //rotate right
       else{
         while(fabs(Enes100.location.theta-current)<radians){
            right();
            Enes100.updateLocation();
          }
       }

      Stop();
  
}

void rotateTo(float goal){
  
    Enes100.updateLocation();
    float current= Enes100.location.theta;
    float difference= current- goal;

    if (fabs(difference)>.2){
    
      rotateBy(difference);
    }
  
 }

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

 void setup(){
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
 
  Enes100.begin("SWAT2", FIRE, 11, 6, 7);
  /*
    Enes100.updateLocation();
  if (Enes100.location.y<1){
    rotateTo(1.5);
   }
   //if starting point is in upper half
   else{
    rotateTo(-1.5);
   }
   */
 }
  
void loop(){
 
  Enes100.updateLocation();
  Enes100.print(Enes100.location.x);
  Enes100.print(" ");
  Enes100.print(Enes100.location.y);
  Enes100.print(" ");
  Enes100.print(Enes100.location.theta);
  Enes100.print(" ");
  Enes100.println(" ");

  if(Enes100.location.y > 1){
    while(!(Enes100.location.theta > -1.6 && Enes100.location.theta < -1.48)){
    right();
    delay(1000);
    Stop();
    delay(1000);
    }
    }
  
}
