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


#include <SPI.h>
#include <TFT_ILI93XX.h>
//#include "include/tuple.h"
//#include "include/color.h"
#include <Eigen/Dense>


// For the Adafruit shield, these are the default.
#define TFT_DC  9
#define TFT_CS 10

uint8_t errorCode = 0;

TFT_ILI93XX tft = TFT_ILI93XX(TFT_CS, TFT_DC);
//
//struct Projectile {
//    Projectile(Tuple const &pos, Tuple const &vel) : m_position(pos), m_velocity(vel) {
//    }
//
//    Tuple m_position;
//    Tuple m_velocity;
//};
//
//struct Environment {
//    Environment(Tuple const &gravity, Tuple const &wind) : m_gravity(gravity), m_wind(wind) {
//    }
//
//    Tuple m_gravity;
//    Tuple m_wind;
//
//};
//
//void tick(Environment const &env, Projectile &proj) {
//    proj.m_position = proj.m_position + proj.m_velocity;
//    proj.m_velocity = proj.m_velocity + env.m_gravity + env.m_wind;
//}


void setup() {
    Serial.begin(38400);
    long unsigned debug_start = millis();
    while (!Serial && ((millis() - debug_start) <= 5000));
    tft.begin(false);
    delay(30);
    //the following it's mainly for Teensy
    //it will help you to understand if you have choosed the
    //wrong combination of pins!
    errorCode = tft.getErrorCode();
    if (errorCode != 0) {
        Serial.print("Init error! ");
        if (bitRead(errorCode, 0)) Serial.print("MOSI or SCLK pin mismach!\n");
        if (bitRead(errorCode, 1)) Serial.print("CS or DC pin mismach!\n");
    }
    else {
        Serial.println(F("Benchmark Sketch V1.1"));
        tft.setTextColor(YELLOW);
        tft.setTextScale(2);
    }


}
float loops = 0.0;

void loop(void) {
//    Tuple start = Point(20, 20, 0);
//    Tuple vel = Vector(1 + loops, 1.8 - loops, loops).normalized() * 11.25;
//    Projectile p = Projectile(start, vel);
//    Environment e = Environment(Vector(0, -.1, 0), Vector(-.01, 0, 0));
//    do {
//        tick(e, p);
//        tft.drawPixel(int(p.m_position.x()), int(p.m_position.y()), CYAN);
//        // Plot as 3x3 squares centered at pos
////            c.WritePixel(int(p.m_position.x-1), int(550 - p.m_position.y-1), Color(1,0,0));
////            c.WritePixel(int(p.m_position.x), int(550 - p.m_position.y-1), Color(1,0,0));
////            c.WritePixel(int(p.m_position.x+1), int(550 - p.m_position.y-1), Color(1,0,0));
////            c.WritePixel(int(p.m_position.x-1), int(550 - p.m_position.y), Color(1,0,0));
////            c.WritePixel(int(p.m_position.x), int(550 - p.m_position.y), Color(1,0,0));
////            c.WritePixel(int(p.m_position.x+1), int(550 - p.m_position.y), Color(1,0,0));
////            c.WritePixel(int(p.m_position.x-1), int(550 - p.m_position.y+1), Color(1,0,0));
////            c.WritePixel(int(p.m_position.x), int(550 - p.m_position.y+1), Color(1,0,0));
////            c.WritePixel(int(p.m_position.x+1), int(550 - p.m_position.y+1), Color(1,0,0));
//    } while (p.m_position.y() > 0);
//    loops += .05;
}