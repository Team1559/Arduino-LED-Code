int i;
int switchCaseVar = 1;
void setup() {
  // Start off with the LED off.
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  switch(switchCaseVar){
  case 1:
    setRGB1(255,i,0);
    setRGB2(255,0,i);
    if (i>=255){
      switchCaseVar = 2;
      i=0;
    }
    break;
  case 2:
    setRGB1((255-i),255,0);
    setRGB2((255-i),0,255);
    if (i>=255){
      switchCaseVar = 3;
      i=0;
    }
    break;
  case 3:
    setRGB1(0,255,i);
    setRGB2(0,i,255);
    if(i>=255){
      switchCaseVar = 4;
      i=0;
    }
    break;
  case 4:
    setRGB1(0,(255-i),255);
    setRGB2(0,255,(255-i));
    if (i>=255){
      switchCaseVar = 5;
      i=0;
    }
    break;
  case 5:
    setRGB1(i,0,255);
    setRGB2(i,255,0);
    if(i>=255){
      switchCaseVar = 6;
      i=0;
    }
    break;
  case 6:
    setRGB1(255,0,(255-i));
    setRGB2(255,(255-i),0);
    if(i>=255){
      switchCaseVar = 1;
      i=0;
    }
    break;
  }
  delay(4);
  i++;
}
void setRGB1(int R,int G,int B){
  analogWrite(9,R);
  analogWrite(11,G);
  analogWrite(10,B);
}
void setRGB2(int R,int G, int B){
  analogWrite(5,R);
  analogWrite(6,G);
  analogWrite(3,B);
}




