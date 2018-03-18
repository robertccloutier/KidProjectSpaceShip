
#include <Arduino.h>
#include "JoyStick.h"
#include "screen.h"
#include "Game.h"

//JoyStick player1(A2, A3, 2);
//JoyStick player2(A0, A1, 12);
Game     game;
Screen   screen;

void setup() {
    Serial.begin(9600);
    Serial.println("Link start!!!");
    // put your setup code here, to run once:
    game.calibrate();
    screen.setup();
}

void loop() {
    static int count = 0;
    static long time = millis();

    switch(game.state) {
        case Starting:
            screen.displayHome();
            game.spawnEnemies(20);
            game.state = Running;
            break;
        case LevelClear:
            screen.displayVictory();
            game.state = Starting;
            game.reset();
            break;
        case Running:
            if (millis() - time > 40) {
                time = millis();
                game.record();
                game.collision();
                screen.refresh(game);

                ++count;
                if (count == 10) {
                    count = 0;
                    game.bullets.create(game.getShip2().getGunPosition(), false);
                    game.bullets.create(game.getShip1().getGunPosition(), true);
                }   
            }
            break;     
    }
}