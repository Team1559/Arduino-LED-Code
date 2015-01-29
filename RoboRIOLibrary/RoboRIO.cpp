#include "Arduino.h"
#include "RoboRIO.h"
RoboRIO::RoboRIO(int pin1,int pin2, int pin3, int pin4){
	pinMode(pin1, INPUT);
	pinMode(pin2, INPUT);
	pinMode(pin3, INPUT);
	pinMode(pin4, INPUT);
	commPort1 = pin1;
	commPort2 = pin2;
	commPort3 = pin3;
	commPort4 = pin4;
}
int RoboRIO::read(){
    stuff[0] = digitalRead(commPort1);
    stuff[1] = digitalRead(commPort2);
    stuff[2] = digitalRead(commPort3);
    stuff[3] = digitalRead(commPort4);
    parsedData = ((stuff[0] << 0)|(stuff[1] << 1)|(stuff[2] << 2)|(stuff[3] << 3));
    return parsedData;
  }