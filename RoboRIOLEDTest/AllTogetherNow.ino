#include <RoboRIO.h>
RoboRIO roboRIO(12,8,7);
int i = 0;
int switchCaseVar = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  switch (roboRIO.read()){
  case 0:
    setRGBBoth(0,0,0);
    switchCaseVar = 1;
    i = 0;
    break;
  case 1:
    //Rave Mode
    setRGBBoth(255,0,0);
    if (i >= 25 && i < 50){
      setRGBBoth(0,255,0);
    }
    if (i >= 50 && i <75){
      setRGBBoth(0,0,255);
    }
    if (i >= 75){
      i = 0;
    }
    break;
  case 2:
    //Blue Gold Flashing
    if(i < 500){
      setRGBBoth(0,43,237);
    }
    if(i >= 500){
      setRGBBoth(237,194,0);
    }
    if(i >= 1000){
      i=0;
    }
    break;
  case 3:
    //Synchronus RGB Fade
    switch(switchCaseVar){
    case 1:
      setRGBBoth(255,i,0);
      if (i>=255){
        switchCaseVar = 2;
        i=0;
      }
      break;
    case 2:
      setRGBBoth((255-i),255,0);
      if (i>=255){
        switchCaseVar = 3;
        i=0;
      }
      break;
    case 3:
      setRGBBoth(0,255,i);
      if(i>=255){
        switchCaseVar = 4;
        i=0;
      }
      break;
    case 4:
      setRGBBoth(0,(255-i),255);
      if (i>=255){
        switchCaseVar = 5;
        i=0;
      }
      break;
    case 5:
      setRGBBoth(i,0,255);
      if(i>=255){
        switchCaseVar = 6;
        i=0;
      }
      break;
    case 6:
      setRGBBoth(255,0,(255-i));
      if(i>=255){
        switchCaseVar = 1;
        i=0;
      }
      break;
    }
    break;
  case 4:  
    //Asynchronus RGB Fade
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
    }
    break;
  case 5:
    //Random Garbage
    setRGB1((int)random(0,155),(int)random(0,155),(int)random(0,155));
    setRGB2((int)random(0,155),(int)random(0,155),(int)random(0,155));
    delay(60);
    break;
  case 6://Fades Thru White To Blue and Gold
    switch(switchCaseVar){
    case 1:
      setRGBBoth(0,42,237);
      if (i>=255){
        switchCaseVar=2;
        i=0;
      }
      break;
    case 2:
      setRGBBoth(i,(int)(42+((213*i)/255)),(int)(237+((18*i)/255)));
      if (i>=255){
        switchCaseVar=3;
        i=0;
      }
      break;
    case 3:
      setRGBBoth((255-(18*i)/255),255-((i*61)/255),255-i);
      if(i>255){
        switchCaseVar=4;
        i=0;
      }
      break;
    case 4:
      setRGBBoth(237,194,0);
      if (i>=255){
        switchCaseVar=5;
        i=0;
      }
      break;
      case 5:
      setRGBBoth(237+((18*i)/255),194+((61*i)/255),i);
      if(i>=255){
        switchCaseVar=6;
        i=0;
      }
      break;
      case 6:
      setRGBBoth(255-i,255-((213*i)/255),255-((18*i)/255));
      if(i>=255){
        switchCaseVar=1;
        i=0;
      }
      break;
    }
    break;
  }
  i++;
  delay(2);
}

void setRGB1(int R,int G,int B){
  analogWrite(9,R);
  analogWrite(10,B);
  analogWrite(11,G);
}

void setRGB2(int R,int G,int B){
  analogWrite(5,R);
  analogWrite(3,B);
  analogWrite(6,G);
}
void setRGBBoth(int R,int G,int B){
  setRGB1(R,G,B);
  setRGB2(R,G,B);
}






