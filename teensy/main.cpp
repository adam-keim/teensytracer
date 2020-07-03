/***************************************************
  This is our GFX example for the Adafruit ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651
  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
  NOTE: This version is the same of the ILI9340_t3 library
  here just for testing...
 ****************************************************/

#include "arduinomacrofix.h"
#include <SPI.h>
#include <ILI9341_t3.h>
#include "include/tuple.h"
#include "include/color.h"
#include <Eigen/Dense>


// For the Adafruit shield, these are the default.
#define TFT_DC  9
#define TFT_CS 10
#define TFT_RST 15
#define TFT_MOSI 11
#define TFT_CLK 13
#define TFT_MISO 12

uint8_t errorCode = 0;


ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_CLK, TFT_MISO);

struct Projectile {
    Projectile(Tuple const &pos, Tuple const &vel) : m_position(pos), m_velocity(vel) {
    }

    Tuple m_position;
    Tuple m_velocity;
};

struct Environment {
    Environment(Tuple const &gravity, Tuple const &wind) : m_gravity(gravity), m_wind(wind) {
    }

    Tuple m_gravity;
    Tuple m_wind;

};

void tick(Environment const &env, Projectile &proj) {
    proj.m_position = proj.m_position + proj.m_velocity;
    proj.m_velocity = proj.m_velocity + env.m_gravity + env.m_wind;
}


void setup() {
    pinMode(6, OUTPUT);
    digitalWriteFast(6, LOW);
    Serial.begin(38400);
    tft.begin();
    tft.fillScreen(ILI9341_BLACK);
    digitalWriteFast(6, HIGH);

}
float loops = 0.0;
auto color = ILI9341_GREEN;
void loop(void) {
    Tuple start = Point(20, 20, 0);
    Tuple vel = Vector(.7, max(4 - loops, 0), 0).normalized() * 6;
    Projectile p = Projectile(start, vel);
    Environment e = Environment(Vector(0, -.1, 0), Vector(-.01, 0, 0));
    if(loops <= 100.0) {
        do {
            tick(e, p);
            tft.drawPixel(int(p.m_position.x()), int(320 - p.m_position.y()), color);
            // Plot as 3x3 squares centered at pos
            tft.drawPixel(int(p.m_position.x() - 1), int(320 - p.m_position.y() - 1), color);
            tft.drawPixel(int(p.m_position.x()), int(320 - p.m_position.y() - 1), color);
            tft.drawPixel(int(p.m_position.x() + 1), int(320 - p.m_position.y() - 1), color);
            tft.drawPixel(int(p.m_position.x() - 1), int(320 - p.m_position.y()), color);
            tft.drawPixel(int(p.m_position.x()), int(320 - p.m_position.y()), color);
            tft.drawPixel(int(p.m_position.x() + 1), int(320 - p.m_position.y()), color);
            tft.drawPixel(int(p.m_position.x() - 1), int(320 - p.m_position.y() + 1), color);
            tft.drawPixel(int(p.m_position.x()), int(320 - p.m_position.y() + 1), color);
            tft.drawPixel(int(p.m_position.x() + 1), int(320 - p.m_position.y() + 1), color);
        } while (p.m_position.y() > 0);
    }
    loops += .15;

}