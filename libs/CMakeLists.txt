
set(SPI_SOURCE_FILES
       SPI/spi.cpp
        )
add_library(SPI STATIC ${SPI_SOURCE_FILES})
target_include_directories(SPI PUBLIC
        SPI)

set(WIRE_SOURCE_FILES
        Wire/Wire.cpp
        Wire/WireIMXRT.cpp
        Wire/WireKinetis.cpp
        )
add_library(Wire STATIC ${WIRE_SOURCE_FILES})
target_include_directories(Wire PUBLIC Wire)


set(TFT_SOURCE_FILES
        ILI9341_t3/ILI9341_t3.cpp
        ILI9341_t3/glcdfont.c
        )
add_library(oled STATIC ${TFT_SOURCE_FILES})
target_include_directories(oled PUBLIC ILI9341_t3)

target_link_libraries(oled SPI Wire)