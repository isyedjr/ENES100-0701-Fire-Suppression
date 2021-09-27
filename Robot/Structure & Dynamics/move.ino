#include "config.h"

void setup() {
		pinMode(RF, OUTPUT);
		pinMode(RB, OUTPUT);
		pinMode(LF, OUTPUT);
		pinMode(LB, OUTPUT);
		pinMode(enR, OUTPUT);
		pinMode(enL, OUTPUT);
}

void MotorL(char dir, int on) {
		if(on == 1) {
				digitalWrite(enL, HIGH);
		} else {
				digitalWrite(enL, LOW);
		}
		if(dir == 'f') {
				digitalWrite(LF, HIGH);
				digitalWrite(LB, LOW);
		} else if(dir == 'b') {
				digitalWrite(LB, HIGH);
				digitalWrite(LF, LOW);
		}
}

void MotorR(char dir, int on) {
		if(on == 1) {
				digitalWrite(enR, HIGH);
		} else {
				digitalWrite(enR, LOW);
		}
		if(dir == 'f') {
				digitalWrite(RF, HIGH);
				digitalWrite(RB, LOW);
		} else if(dir == 'b') {
				digitalWrite(RB, HIGH);
				digitalWrite(RF, LOW);
		}
}

void loop() {
	
		/* ----------------------------------------------------------------------
		 *													MOTOR TESTING
		 */----------------------------------------------------------------------
	
}
