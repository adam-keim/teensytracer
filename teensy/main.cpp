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
#include "include/shapes.h"
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



int x_width = 240;
int y_height = 240;
float loops = 0.0;
auto color = ILI9341_CYAN;
auto s = Sphere();
auto ray_origin = Point(0,0,-5);
float wall_z = 10;
float wall_size = 7.0;
float pixel_size = wall_size / x_width;
float half = wall_size / 2;

void setup() {
    pinMode(6, OUTPUT);
    digitalWriteFast(6, LOW);
    Serial.begin(38400);
    delay(1000);
    tft.begin();
    tft.fillScreen(ILI9341_BLACK);
    digitalWriteFast(6, HIGH);
    for(int y = 0; y < y_height; y++) {
        float world_y = half - pixel_size * y;
        for(int x = 0; x < x_width; x++) {
//            Serial.print(x);
//            Serial.print(" ");
//            Serial.println(y);
            float world_x = -half + pixel_size * x;
            auto position = Point(world_x, world_y, wall_z);
            auto r = Ray(ray_origin, (position - ray_origin).normalized());
            auto xs = s.intersect(r);
            auto ray_hit = hit(xs);
            if(not ray_hit.isBlank) {
                tft.drawPixel(x, y, color);
            }
        }

    }

}
void loop(void) {

}