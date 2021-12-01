void setup() {
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A0));
  if(analogRead(A0) > 150) {
    Serial.println("flame detected A0");
    digitalWrite(9, HIGH);
   } else {
      digitalWrite(9, LOW);
   }

  Serial.println(analogRead(A1));
  if(analogRead(A1) > 150) {
    Serial.println("flame detected A1");
    digitalWrite(8, HIGH);
   } else {
      digitalWrite(8, LOW);
   }

     Serial.println(analogRead(A2));
  if(analogRead(A2) > 150) {
    Serial.println(" A2 flame detected");
    digitalWrite(10, HIGH);
   } else {
      digitalWrite(10, LOW);
   }

     Serial.println(analogRead(A3));
  if(analogRead(A3) > 150) {
    Serial.println("flame detected A3");
    digitalWrite(7, HIGH);
   } else {
      digitalWrite(7, LOW);
   }
}
