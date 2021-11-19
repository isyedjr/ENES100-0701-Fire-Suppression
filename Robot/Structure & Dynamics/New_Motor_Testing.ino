// Left back motor setup
#define LB_rev 5
#define LB_for 6
#define enL 7

// Left front motor setup
#define LF_rev 11
#define LF_for 12
#define enL2 13

//Right back motor setup
#define RF_rev 2
#define RF_for 3
#define enRF 4
// Right front motor setup
#define enRB 10
#define RB_rev 8
#define RB_for 9

void start(){
  digitalWrite(enL, HIGH);
  digitalWrite(enL2, HIGH);
  digitalWrite(enRB, HIGH);
  digitalWrite(enRF, HIGH);   
}

void forward(int miliseconds){ //write miliseconds as parameter set how long motors run
  digitalWrite(LB_for, HIGH);
  digitalWrite(LB_rev, LOW);
  digitalWrite(LF_for, HIGH);
  digitalWrite(LF_rev, LOW);
  digitalWrite(RB_for, HIGH);
  digitalWrite(RB_rev, LOW);
  digitalWrite(RF_for, HIGH);
  digitalWrite(RF_rev, LOW);
  delay(miliseconds);
  digitalWrite(LB_for, LOW);
  digitalWrite(LB_rev, LOW);
  digitalWrite(LF_for, LOW);
  digitalWrite(LF_rev, LOW);
  digitalWrite(RB_for, LOW);
  digitalWrite(RB_rev, LOW);
  digitalWrite(RF_for, LOW);
  digitalWrite(RF_rev, LOW);
  delay(500);  
}

void reverse(int miliseconds){
  digitalWrite(LB_for, LOW);
  digitalWrite(LB_rev, HIGH);
  digitalWrite(LF_for, LOW);
  digitalWrite(LF_rev, HIGH);
  digitalWrite(RB_for, LOW);
  digitalWrite(RB_rev, HIGH);
  digitalWrite(RF_for, LOW);
  digitalWrite(RF_rev, HIGH);
  delay(miliseconds);
  digitalWrite(LB_for, LOW);
  digitalWrite(LB_rev, LOW);
  digitalWrite(LF_for, LOW);
  digitalWrite(LF_rev, LOW);
  digitalWrite(RB_for, LOW);
  digitalWrite(RB_rev, LOW);
  digitalWrite(RF_for, LOW);
  digitalWrite(RF_rev, LOW);
  delay(500);  
}

void turnLeft(int miliseconds){
  digitalWrite(LB_for, LOW);
  digitalWrite(LB_rev, HIGH);
  digitalWrite(LF_for, LOW);
  digitalWrite(LF_rev, HIGH);
  digitalWrite(RB_for, HIGH);
  digitalWrite(RB_rev, LOW);
  digitalWrite(RF_for, HIGH);
  digitalWrite(RF_rev, LOW);
  delay(miliseconds);
  digitalWrite(LB_for, LOW);
  digitalWrite(LB_rev, LOW);
  digitalWrite(LF_for, LOW);
  digitalWrite(LF_rev, LOW);
  digitalWrite(RB_for, LOW);
  digitalWrite(RB_rev, LOW);
  digitalWrite(RF_for, LOW);
  digitalWrite(RF_rev, LOW);
  delay(500);  
}

void setup() {
  // put your setup code here, to run once:
  //Enes100.begin("SWAT", FIRE, 3, 8, 9);
  pinMode(LB_for, OUTPUT);
  pinMode(LB_rev, OUTPUT);
  pinMode(enL, OUTPUT);
  start();
}

void loop() {
  forward(1000);
  reverse(1000);
  turnLeft(1000);

}
