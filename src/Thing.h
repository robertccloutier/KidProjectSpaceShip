
#ifndef thing_h
#define thing_h

#include <Arduino.h>
#include "ScreenArea.h"

class Thing {
    public:
        Area& area;
        point position;
        point previous;
        int sizeX;
        int sizeY;
        velocity speed;

    protected:
        int maxSpeed;
        float weight;

    public:
        inline Thing(Area& limitZone):
            area(limitZone),sizeX(3),sizeY(3),maxSpeed(5), weight(500.0)
        {}

        inline void move() {
            previous = position;
            position += speed;
            area.limit(position,speed);
        }

        inline bool hasMove() const {
            return previous != position;
        }

    protected:
        inline int speedLimit(int speed) {
            if (speed < -maxSpeed) return -maxSpeed;
            if (speed > maxSpeed) return maxSpeed;
            return speed;
        }
};

#endif