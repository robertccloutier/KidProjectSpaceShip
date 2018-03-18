#ifndef game_h
#define game_h

#include <Arduino.h>
#include "JoyStick.h"
#include "SpaceShip.h"
#include "Bullets.h"

enum GameState {
    Running = 0,
    LevelClear = 1,
    Completed = 2,
    Starting = 3
};

class Game {
    private:
        Area         fullScreen;
        Area         player1Zone;
        Area         player2Zone;
        Area         enemiZone;
        JoyStick     player1;
        JoyStick     player2;
        SpaceShip    ship1;
        SpaceShip    ship2;
    public:
        SpaceShip**  enemies;
        Bullets      bullets;
        unsigned int enemiesCount;
        GameState    state;
    
    public:
        Game();
        ~Game();

        inline const JoyStick& getPlayer1() const { return player1; }
        inline const JoyStick& getPlayer2() const { return player2; }
        inline const SpaceShip& getShip1() const { return ship1; }
        inline const SpaceShip& getShip2() const { return ship2; }

        void calibrate();
        void record();
        void collision();
        void reset();
        void spawnEnemies(unsigned int count);
        
    private:
        void move();
        bool enemiesRemaining();

};

#endif