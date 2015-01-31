//This is a Library for Interfacing with the RoboRIO over 3 DIO Pins
#ifndef RoboRIO_h
#define RoboRIO_h
#include "Arduino.h"
class RoboRIO
{
public:
	RoboRIO(int pin1,int pin2,int pin3);
	int commPort3;
	int commPort2;
	int commPort1;
	int read();
private:
	int parsedData;
	int stuff[3];
};
#endif