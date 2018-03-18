// Henry's Bench
//  1.44"  128 * 128  SPI  V1.1 Display Tutorial

//#include <SPI.h>
//#include <Adafruit_GFX.h>
//#include <TFT_ILI9163C.h>

#ifndef screen_h
#define screen_h

#include <Arduino.h>
#include <SPI.h>
#include <TFT.h>            // Arduino LCD library

#include "Game.h"
#include "SpaceShip.h"

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

 VCC 3.3V
 SCL SPI Clock Input
 SDA SPI Data Input
 RES Reset
 DC  Data/Command Select
 CS  SPI Chip Select
 BL  Backlight Control

 On the board: 1.44' 128*128 TFT_LCD
 DRIVER IC:ST7735
 NOMEN_TEC V2.0
 */
class Screen {
    private:
        static const byte DC = 9;
        static const byte CS = 10;
    
        TFT screen = TFT(10, 9, 8);
        // Declare an instance of the ILI9163
        //TFT_ILI9163C tft = TFT_ILI9163C(9, 8, 10);  
        //TFT_ILI9163C tft = TFT_ILI9163C(9, 10);  

    public:
        Screen();

        void setup();
        void refresh(const Game& game);
        void displayVictory();
        void displayHome();

    private:
        void drawSpaceShip(const SpaceShip& ship, int color);
        void drawEnemies(const Game& game, int color);
        void drawBullets(const Game& game, int color);
};

#endif 