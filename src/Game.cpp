
#include "Game.h"
#include "Point.h"

Game::Game() :
    fullScreen(5,128,5,128),
    player1Zone(5,128,5,28),
    player2Zone(5,128,100,128),
    enemiZone(5,128,29,99),
    player1(A2, A3, 2),
    player2(A0, A1, 12),
    ship1(player1Zone),
    ship2(player2Zone),
    enemies(NULL),
    bullets(fullScreen),
    enemiesCount(0),
    state(Starting)
{}

Game::~Game() {
    reset();
}

void Game::calibrate() {
    player1.calibrate();
    player2.calibrate();
}

void Game::record() {
    player1.record();
    player2.record();
    ship1.accelerate(player1);
    ship2.accelerate(player2);
    move();
}

void Game::reset() {
    for (unsigned int index = 0; index < enemiesCount; ++ index){
        delete &enemies[index];
    }
    delete[] enemies;
}

void Game::spawnEnemies(unsigned int count) {
    int xpos = 20;
    int ypos = 30;
    enemies = new SpaceShip*[count];
    Serial.println("Enemies Generated:");
    enemiesCount = count;
    for (unsigned int index = 0; index < enemiesCount; ++ index){
        enemies[index] = new SpaceShip(enemiZone);
        enemies[index]->position.x = xpos;//random(10,120);
        enemies[index]->position.y = ypos;//random(30, 90);
        enemies[index]->speed.x = 1;
        enemies[index]->speed.y = 1;
        xpos += 10;
        if (xpos >= 100) {
            xpos = 20;
            ypos += 10;
        }
        Serial.print(index);
        Serial.print(": (");
        Serial.print(enemies[index]->position.x);
        Serial.print(",");
        Serial.print(enemies[index]->position.y);
        Serial.print(")[");
        Serial.print(enemies[index]->speed.x);
        Serial.print(",");
        Serial.print(enemies[index]->speed.y);
        Serial.println("]");
    }
}

void Game::move() {
    ship1.move();
    ship2.move();

    for (unsigned int index = 0; index < enemiesCount; ++ index){
        enemies[index]->move();
    }
    bullets.moveAll();
}

void Game::collision() {
    for (unsigned int a = 0; a < enemiesCount; ++a) {
        if (enemies[a]->pv <= 0) continue;
        for (unsigned int b = 0; b < bullets.SIZE; ++b) {
            if (!bullets.bullets[b].position.isNull() && bullets.bullets[b].position.near(enemies[a]->position)) {
                --enemies[a]->pv;
                bullets.bullets[b].position.clear();
            }
        }
        if (enemies[a]->pv <= 0) {
            enemies[a]->speed.clear();
            if (!enemiesRemaining()) state = LevelClear;
        } 
    }
}

bool Game::enemiesRemaining() {
    for (unsigned int a = 0; a < enemiesCount; ++a) {
        if (enemies[a]->pv > 0) return true;
    }
    return false;
}