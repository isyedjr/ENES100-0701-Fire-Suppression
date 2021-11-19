int trigPin=11;
int echoPin=12;
int pingTravelTime;
int ledPin= 9; 

//adjust this code (like variables and stuff) to account for 2 sensors? should I place this code into the navigation code?
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime= pulseIn(echoPin,HIGH);
  delay(25);
  //speed of the sound is 340 m/s
  //So in order to get the distance in cm 
  //we need to multiply the received travel time value from the echo pin by 0.034 and divide it by 2.
  //ig if everything is in meters just adjust this to be in memters
  //currently returns centimeters
  Serial.println(pingTravelTime*.034/2);
  
}
