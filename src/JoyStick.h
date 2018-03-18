#ifndef joystick_h
#define joystick_h

#include <Arduino.h>

/* 
* Arduino & Analog Joystick
* Demo/Test Sketch
* Reads two analog inputs A0,A1
* And a button switch input at D12
* Joy Stck = 2-axis analog jostick made of two 10K potmeters
* Tested at TechNode Protolabz/July 2014
*/
class JoyStick {
    private:
        byte xPin;
        byte yPin;
        byte buttonPin;

        int     x;
        int     y;
        bool    pushed;

        int     calibX;
        int     calibY;

    public:
        JoyStick(byte xPosPin, byte yPosPin, byte bPin);

        inline int   getX() const { return x; }
        inline int   getY() const { return y; }
        inline bool  isPushed() const { return pushed; }

        void record();
        void calibrate();

    private:
        int readX();
        int readY();
        bool readIsPushed();
};

#endif