
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

set(SOURCE_FILES
        TFT_ILI93XX/TFT_ILI93XX.cpp
            )

add_library(oled STATIC ${SOURCE_FILES})
target_include_directories(oled PUBLIC TFT_ILI93XX TFT_ILI93XX/_includes)
target_link_libraries(oled SPI Wire)