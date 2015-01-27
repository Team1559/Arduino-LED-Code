#include <RoboRIO.h>

RoboRIO roboRIO(12,7,8);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.println(roboRIO.read());
}
