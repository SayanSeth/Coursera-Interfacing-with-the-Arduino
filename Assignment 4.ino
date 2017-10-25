/*
Build a circuit that contains two push buttons, an LED, and any other basic components you think you need. 
The LED should only light when both push buttons are pressed. Only use your Arduino for power and ground.
*/


#include <Servo.h>

int sensorValue;			//value of potentiometer, 0 - 1023
int analogInPin = A0;	//Arduino pin connected to potentiometer 
int analogOutPin = 6;		//Arduino pin connected to LED

Servo myLED;		//LED controlled by servo library

void setup(){
}

void loop(){
	sensorValue = analogRead(analogInPin);
  	sensorValue = map(sensorValue, 0, 1023, 0, 225); //analogRead ranges from 0 to 1023; analogWrite ranges from 0 to 255; this maps the sensorValue to the lower output range
  	analogWrite(analogOutPin,sensorValue);
}