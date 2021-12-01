#include <Enes100.h>
#include <Wire.h>
// Left back motor setup
#define LB_rev 5
#define LB_for 6
#define enLF 7

// Left front motor setup
#define LF_rev 11
#define LF_for 12
#define enLB 13

//Right back motor setup
#define RF_rev 2
#define RF_for 3
#define enRF 4
// Right front motor setup
#define enRB 10
#define RB_rev 8
#define RB_for 9
#define Ystart A8

// Setting up the left distance sensor
int LeftTrigPin=51;
int LeftEchoPin=50;
int LeftPingTravelTime;

// Setting up the right distance sensor
int RightTrigPin=52;
int RightEchoPin=53;
int RightPingTravelTime;

double localX, localT;
char localY;
void start(){
  digitalWrite(enLF, HIGH);
  digitalWrite(enLB, HIGH);
  digitalWrite(enRB, HIGH);
  digitalWrite(enRF, HIGH);   
}

float getDistanceLeft(){
  digitalWrite(LeftTrigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(LeftTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(LeftTrigPin, LOW);
  LeftPingTravelTime= pulseIn(LeftEchoPin,HIGH);
  delay(25);
  return (LeftPingTravelTime*.034/2);
 }

float getDistanceRight(){
  digitalWrite(RightTrigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(RightTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(RightTrigPin, LOW);
  RightPingTravelTime= pulseIn(RightEchoPin,HIGH);
  delay(25);
  return (RightPingTravelTime*.034/2);
 }

void forward(){ //write miliseconds as parameter set how long motors run
  digitalWrite(LB_for, HIGH);
  digitalWrite(LB_rev, LOW);
  digitalWrite(LF_for, HIGH);
  digitalWrite(LF_rev, LOW);
  digitalWrite(RB_for, HIGH);
  digitalWrite(RB_rev, LOW);
  digitalWrite(RF_for, HIGH);
  digitalWrite(RF_rev, LOW);

}

void reverse(){
  digitalWrite(LB_for, LOW);
  digitalWrite(LB_rev, HIGH);
  digitalWrite(LF_for, LOW);
  digitalWrite(LF_rev, HIGH);
  digitalWrite(RB_for, LOW);
  digitalWrite(RB_rev, HIGH);
  digitalWrite(RF_for, LOW);
  digitalWrite(RF_rev, HIGH);


    
}

void turnLeft(){
  digitalWrite(LB_for, LOW);
  digitalWrite(LB_rev, HIGH);
  digitalWrite(LF_for, LOW);
  digitalWrite(LF_rev, HIGH);
  digitalWrite(RB_for, HIGH);
  digitalWrite(RB_rev, LOW);
  digitalWrite(RF_for, HIGH);
  digitalWrite(RF_rev, LOW);

}

void turnRight(){
  digitalWrite(LB_for, HIGH);
  digitalWrite(LB_rev, LOW);
  digitalWrite(LF_for, HIGH);
  digitalWrite(LF_rev, LOW);
  digitalWrite(RB_for, LOW);
  digitalWrite(RB_rev, HIGH);
  digitalWrite(RF_for, LOW);
  digitalWrite(RF_rev, HIGH);

}

 void Stop(){
  digitalWrite(LB_for, LOW);
  digitalWrite(LB_rev, LOW);
  digitalWrite(LF_for, LOW);
  digitalWrite(LF_rev, LOW);
  digitalWrite(RB_for, LOW);
  digitalWrite(RB_rev, LOW);
  digitalWrite(RF_for, LOW);
  digitalWrite(RF_rev, LOW);
  }
void setup() {
  // put your setup code here, to run once:
  pinMode( Ystart, INPUT);
  pinMode(LB_for, OUTPUT);
  pinMode(LB_rev, OUTPUT);
  pinMode(enLF, OUTPUT);
  pinMode(enLB, OUTPUT);
  pinMode(LF_for, OUTPUT);
  pinMode(LF_rev, OUTPUT);
  pinMode(RB_for, OUTPUT);
  pinMode(RB_rev, OUTPUT);
  pinMode(RF_for, OUTPUT);
  pinMode(RF_rev, OUTPUT);
  start();
  pinMode(RightTrigPin, OUTPUT);
  pinMode (RightEchoPin, INPUT);
    pinMode(LeftTrigPin, OUTPUT);
  pinMode (LeftEchoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  Serial.print(analogRead(A8));
  Serial.println(" test");
  
  /*
  if(analogRead(A8) >= 700){
     Serial.println("Turning Right");
     turnRight();
     delay(1000);
     Stop();
     delay(1000);
    }
    else{
     Serial.println("Turning Left");
     Stop();
     delay(2000);
      }
    */
}
