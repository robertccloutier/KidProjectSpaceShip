
#ifndef spaceship_h
#define spaceship_h

#include <Arduino.h>
#include "Thing.h"
#include "JoyStick.h"

enum SpaceShipType {
    ePlayer = 0,
    eMini = 1,
    eMedium = 2,
    eLarge = 3
};

class SpaceShip : public Thing {
    public:
        inline SpaceShip(Area& limitZone, SpaceShipType selectedType = ePlayer): Thing(limitZone), pv(1)
        {
            type = selectedType;
        }

        inline void accelerate(const JoyStick& joyStick) {
            speed.x += ((float)joyStick.getX())/weight;
            speed.y += ((float)joyStick.getY())/weight;
            speed.x = speedLimit(speed.x);
            speed.y = speedLimit(speed.y);
        }

    public:
        unsigned int pv;
        point getGunPosition() const {
            point pos = position;
            pos.y += 3;
            return pos;
        }

    private:
        SpaceShipType type;
};

#endif