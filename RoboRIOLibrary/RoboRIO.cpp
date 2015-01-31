#include "Arduino.h"
#include "RoboRIO.h"
RoboRIO::RoboRIO(int pin1,int pin2, int pin3){
	pinMode(pin1, INPUT);
	pinMode(pin2, INPUT);
	pinMode(pin3, INPUT);
	commPort1 = pin1;
	commPort2 = pin2;
	commPort3 = pin3;
}
int RoboRIO::read(){
    stuff[0] = (int)digitalRead(commPort1);
    stuff[1] = (int)digitalRead(commPort2);
    stuff[2] = (int)digitalRead(commPort3);
    parsedData = ((stuff[0] << 0)|(stuff[1] << 1)|(stuff[2] << 2));
    return parsedData;
}

