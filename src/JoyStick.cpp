#include "JoyStick.h"

JoyStick::JoyStick(byte xPosPin, byte yPosPin, byte bPin) :
   xPin(xPosPin),
   yPin(yPosPin),
   buttonPin(bPin),
   calibX(0),
   calibY(0)
{
    pinMode(buttonPin,INPUT);
}

int JoyStick::readX(){
    int value = analogRead(xPin);
    //delay(2);
    value += analogRead(xPin);
    value /= 2;
    return value - 512; 
}

int JoyStick::readY(){
    int value = analogRead(yPin);
    //delay(2);
    value += analogRead(yPin);
    value /= 2;
    return value - 512; 
}

bool JoyStick::readIsPushed(){
    //digitalRead(buttonPin);
    //delay(10);
    if (digitalRead(buttonPin) == LOW) { 
        return false; 
    } 
    else {
        return true; 
    }
}

void JoyStick::record() {
    x = readX() - calibX;
    y = readY() - calibY;
    pushed = readIsPushed();
}

void JoyStick::calibrate() {
    calibX = readX();
    calibY = readY();
}


