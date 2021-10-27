#include <Stepper.h>
#define STEPS 2038
Stepper ligma(STEPS, 6,8,7,9);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
 

}

  // This converts the angle we want into # of steps motor takes
  int getSteps( int angle){                      
    int steps = ((2038/360) * angle);
    return steps;
    }
    

   
void loop() {
  
  // put your main code here, to run repeatedly:
  //This code moves the stepper motor back and forth. We set the degrees in .step functions. 
      
    Serial.println(getSteps(90));
    ligma.setSpeed(10);
    ligma.step(getSteps(180));
    delay(1000);
    ligma.setSpeed(10);
    ligma.step(-getSteps(180));
    delay(1000);

}
