#ifndef velocity_h
#define velocity_h

#include <Arduino.h>
#include "Point.h"

class velocity
{
    public:
        double x, y;
        
    public:
        velocity() : x(0.0), y(0.0) {}

        velocity(double x1, double y1) : x(x1), y(y1) {}
    
        velocity(const point &p2) : x(p2.x), y(p2.y) {}

        velocity& operator=(const velocity& other) // copy assignment
        {
            if (this != &other) { // self-assignment check expected
                x = other.x;
                y = other.y;
            }
            return *this;
        }

        velocity& operator+=(const velocity& rhs) 
        {       
            x += rhs.x;
            y += rhs.y;
            return *this; 
        }
        
        friend velocity operator+(velocity lhs, const velocity& rhs) 
        {
            lhs += rhs; 
            return lhs; 
        }  

        void clear() {
            x = 0;y = 0;
        }      
};

#endif