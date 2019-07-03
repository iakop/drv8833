#include "drv8833.h"

drv8833::drv8833(uint8_t a1, uint8_t a2, uint8_t b1, uint8_t b2){
	ina1 = a1;
	ina2 = a2;
	inb1 = b1;
	inb2 = b2;
}

void drv8833::init(void){
	pinMode(ina1, OUTPUT);
	pinMode(ina1, OUTPUT);
	pinMode(ina1, OUTPUT);
	pinMode(ina1, OUTPUT);
}

void drv8833::speeds(int left, int right){
	switch(left >= 0){
		case true:
			digitalWrite(ina2, LOW);
			analogWrite(ina1, (uint8_t) left);
			break;
		case false:
			left = left*(-1);
			digitalWrite(ina1, LOW);
			analogWrite(ina2, (uint8_t) left);
			break;
		default:
			digitalWrite(ina1, LOW);
			digitalWrite(ina2, LOW);
			break;
	}
	switch(right >= 0){
		case true:
			digitalWrite(inb2, LOW);
			analogWrite(inb1, (uint8_t) right);
			break;
		case false:
			right = right*(-1);
			digitalWrite(inb1, LOW);
			analogWrite(inb2, (uint8_t) right);
			break;
		default:
			digitalWrite(inb1, LOW);
			digitalWrite(inb2, LOW);
			break;
	}
}
      

void drv8833::forward(uint8_t speed){
	digitalWrite(ina2, LOW);
	analogWrite(ina1, speed);

	digitalWrite(inb2, LOW);
	analogWrite(inb1, speed);
}
void drv8833::back(uint8_t speed){
	digitalWrite(ina1, LOW);
	analogWrite(ina2, speed);

	digitalWrite(inb1, LOW);
	analogWrite(inb2, speed);
}

void drv8833::stop(void){
	digitalWrite(ina1, LOW);
	digitalWrite(ina2, LOW);

	digitalWrite(inb1, LOW);
	digitalWrite(inb2, LOW);
}

void drv8833::hardstop(void){
	digitalWrite(ina1, HIGH);
	digitalWrite(ina2, HIGH);

	digitalWrite(inb1, HIGH);
	digitalWrite(inb2, HIGH);
	delay(10);

	digitalWrite(ina1, LOW);
	digitalWrite(ina2, LOW);

	digitalWrite(inb1, LOW);
	digitalWrite(inb2, LOW);
}


