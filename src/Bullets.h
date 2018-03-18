#ifndef bullets_h
#define bullets_h

#include "Thing.h"
#include "ScreenArea.h"

class Bullets
{
    protected:
        struct Bullet {
            point position;
            point previous;
            bool  direction;
        };
        Area& area;
        int speed;
        unsigned int nextIndex;

    public:
        static const unsigned int SIZE = 20;
        Bullet bullets[SIZE];
        
    public:
        Bullets(Area& freeArea) : area(freeArea), speed(5), nextIndex(0) {

        }

        // Add a new bullet in the game
        void create(point position, bool direction) {
            bullets[nextIndex].position = position;
            bullets[nextIndex].previous = position;
            bullets[nextIndex].direction = direction;
            ++nextIndex;
            if (nextIndex >= SIZE) nextIndex = 0;
        }

        void moveAll() {
            for (unsigned int index = 0; index < SIZE; ++index) {
                if (!bullets[index].position.isNull()) {
                    bullets[index].previous.y = bullets[index].position.y;
                    if (bullets[index].direction) {
                        bullets[index].position.y += speed;                        
                    } else {
                        bullets[index].position.y -= speed;
                    }
                }
                if (!area.isInside(bullets[index].position)) {
                    bullets[index].position.clear();
                }
            }
        }
};

#endif