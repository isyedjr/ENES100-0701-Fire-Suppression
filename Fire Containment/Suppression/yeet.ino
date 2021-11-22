void setup() {
pinMode(A0, INPUT);
pinMode(7, OUTPUT); 
Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A0));
  if(analogRead(A0) > 150) {
    Serial.println("flame detected");
    digitalWrite(7, HIGH);
   } else {
      digitalWrite(7, LOW);
   }
}
