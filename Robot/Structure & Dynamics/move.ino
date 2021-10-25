#include "config.h"

void setup() {
	pinMode(RF, OUTPUT);
	pinMode(RB, OUTPUT);
	pinMode(LF, OUTPUT);
	pinMode(LB, OUTPUT);
	pinMode(enR, OUTPUT);
	pinMode(enL, OUTPUT);
}

void MotorL(char dir, int on, int power) {
	if(on == 1) {
		digitalWrite(enL, HIGH);
	} else {
		digitalWrite(enL, LOW);
	}
	if(dir == 'f') {
		analogWrite(LF, power);
		digitalWrite(LB, LOW);
	} else if(dir == 'b') {
		analogWrite(LB, power);
		digitalWrite(LF, LOW);
	}
}

void MotorR(char dir, int on, int power) {
	if(on == 1) {
		digitalWrite(enR, HIGH);
	} else {
		digitalWrite(enR, LOW);
	}
	if(dir == 'f') {
		analogWrite(RF, power);
		digitalWrite(RB, LOW);
	} else if(dir == 'b') {
		analogWrite(RB, power);
		digitalWrite(RF, LOW);
	}
}

void loop() {
	
/* ----------------------------------------------------------------------
 *			      MOTOR TESTING
 */----------------------------------------------------------------------
	
}
