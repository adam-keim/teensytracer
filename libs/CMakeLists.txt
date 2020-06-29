set(SOURCE_FILES
        Adafruit_BusIO/Adafruit_BusIO_Register.cpp
        Adafruit_BusIO/Adafruit_I2CDevice.cpp
        Adafruit_BusIO/Adafruit_SPIDevice.cpp
        Adafruit-GFX-Library/Adafruit_GFX.cpp
        Adafruit-GFX-Library/Adafruit_MonoOLED.cpp
        Adafruit-GFX-Library/Adafruit_SPITFT.cpp
        Adafruit_ILI9341/Adafruit_ILI9341.cpp
        )

add_library(adafruit STATIC ${SOURCE_FILES})
target_include_directories(adafruit PUBLIC Adafruit_ILI9341 Adafruit-GFX-Library Adafruit_BusIO)
