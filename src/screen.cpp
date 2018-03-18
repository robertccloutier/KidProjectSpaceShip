// Henry's Bench
//  1.44"  128 * 128  SPI  V1.1 Display Tutorial

//#include <SPI.h>
//#include <Adafruit_GFX.h>
//#include <TFT_ILI9163C.h>
#include "Screen.h"

#define BLACK   0x0000
#define GRAY    0x8410
#define WHITE   0xFFFF
#define RED     0xF800
#define ORANGE  0xFA60
#define YELLOW  0xFFE0  
#define LIME    0x07FF
#define GREEN   0x07E0
#define CYAN    0x07FF
#define AQUA    0x04FF
#define BLUE    0x001F
#define MAGENTA 0xF81F
#define PINK    0xF8FF

Screen::Screen() {

}

/*
Your Connections to an Uno (Through a Level Shifter)

 LED to 3.3V
 SCK to D13
 SDA to D11
 A0 to D8
 RST to D9
 CS to D10
 GND to GND
 VCC to 3.3V 
 */
void Screen::setup() {
    // initialize the screen
    screen.begin();
    // make the background black
    screen.background(0,0,0);
}

void Screen::displayVictory() {
    screen.background(250,250,250);
    screen.setCursor(30,64);
    screen.setTextColor(BLACK, WHITE);
    screen.textSize(2);
    screen.print("Win!");   
    delay(3000);  
    screen.background(0,0,0);
}

void Screen::displayHome() {
    screen.background(250,250,250);
    screen.setCursor(30,64);
    screen.setTextColor(BLACK, WHITE);
    screen.textSize(2);
    screen.print("Start!");
    delay(3000);  
    screen.background(0,0,0);
}

void Screen::refresh(const Game& game){
    drawSpaceShip(game.getShip1(), GREEN);
    drawSpaceShip(game.getShip2(), RED);
    drawEnemies(game, YELLOW);
    drawBullets(game, WHITE);

    /*screen.setCursor(5,15);
    screen.setTextColor(WHITE, BLACK);
    screen.print("P2 (");
    screen.print(game.getShip2().x);
    screen.print(",");
    screen.print(game.getShip2().y);
    screen.print(") (");
    screen.print(game.getShip2().speedX);
    screen.print(",");
    screen.print(game.getShip2().speedY);
    screen.print(")");

    screen.setCursor(5,5);
    screen.setTextColor(WHITE, BLACK);
    screen.print("P2 (");
    screen.print(game.getShip1().x);
    screen.print(",");
    screen.print(game.getShip1().y);
    screen.print(") (");
    screen.print(game.getShip1().speedX);
    screen.print(",");
    screen.print(game.getShip1().speedY);
    screen.print(")");*/
}

void Screen::drawSpaceShip(const SpaceShip& ship, int color) {
    if (ship.hasMove()) {
        screen.fillCircle(ship.previous.x,ship.previous.y,ship.sizeX,BLACK);
        screen.fillCircle(ship.position.x,ship.position.y,ship.sizeX,color);
    }
}

void Screen::drawEnemies(const Game& game, int color) {
    for (unsigned int index = 0; index < game.enemiesCount; ++index){
        if (game.enemies[index]->hasMove()) {
            screen.fillCircle(game.enemies[index]->previous.x,game.enemies[index]->previous.y,2,BLACK);
            if (game.enemies[index]->pv != 0) {
                screen.fillCircle(game.enemies[index]->position.x,game.enemies[index]->position.y,2,color);
            }
        }
    }
}

void Screen::drawBullets(const Game& game, int color) {
    for (unsigned int index = 0; index < game.bullets.SIZE; ++index){
        if (!game.bullets.bullets[index].position.isNull()) {
            screen.stroke(255,255,255);
            screen.point(game.bullets.bullets[index].position.x,game.bullets.bullets[index].position.y);
            screen.stroke(0,0,0);
            screen.point(game.bullets.bullets[index].previous.x,game.bullets.bullets[index].previous.y);
        }
    }
}
