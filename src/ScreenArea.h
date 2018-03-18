#ifndef screenarea_h
#define screenarea_h

#include <Arduino.h>
#include "Point.h"
#include "Velocity.h"

class Area {
    public:
        point minPos; 
        point maxPos;

    public:
        inline Area(int xmin, int xmax, int ymin, int ymax):
            minPos(xmin,ymin),maxPos(xmax,ymax)
        {}

        inline Area(const point& min1, const point& max1) : minPos(min1), maxPos(max1) {}

        inline const point& getMin() const { return minPos; }
        inline const point& getMax() const { return maxPos; }

        inline void limit(point& position, velocity& speed, bool collide = false) {
            limit(position.x, position.y, speed.x, speed.y, collide);
        }

        inline bool isInside(const point& position) {
            if ((position.x >= minPos.x && position.x <= maxPos.x) && 
                (position.y >= minPos.y && position.y <= maxPos.y)) {
                return true;
            }
            return false;
        }

        inline void limit(int& x, int& y, double& speedX, double& speedY, bool collide = false) {
            if (collide) {
                if (x < minPos.x) {x = minPos.x;speedX=0;}
                if (y < minPos.y) {y = minPos.y;speedY=0;}
                if (x > maxPos.x) {x = maxPos.x;speedX=0;}
                if (y > maxPos.y) {y = maxPos.y;speedY=0;}
            } else {
                if (x < minPos.x) {x = minPos.x;speedX=-speedX;}
                if (y < minPos.y) {y = minPos.y;speedY=-speedY;}
                if (x > maxPos.x) {x = maxPos.x;speedX=-speedX;}
                if (y > maxPos.y) {y = maxPos.y;speedY=-speedY;}
            }
        }
};

#endif