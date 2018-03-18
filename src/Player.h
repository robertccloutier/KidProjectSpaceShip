
#ifndef player_h
#define player_h

#include "JoyStick.h"
#include "ScreenArea.h"
#include "SpaceShip.h"

class Player
{
    public:
        JoyStick    joystick;
        Area        area;
        SpaceShip   spaceShip;
        int         pv;
        int         color;
        int         score;
};

#endif