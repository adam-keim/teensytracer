set(TARGET_NAME Teensy)
set(CMAKE_VERBOSE_MAKEFILE 1)

set(TEENSY_C_CORE_FILES
        ${TEENSY_ROOT}/keylayouts.c
        ${TEENSY_ROOT}/clockspeed.c
        ${TEENSY_ROOT}/interrupt.c
        ${TEENSY_ROOT}/digital.c
        ${TEENSY_ROOT}/tempmon.c
        ${TEENSY_ROOT}/bootdata.c
        ${TEENSY_ROOT}/usb.c
        ${TEENSY_ROOT}/rtc.c
        ${TEENSY_ROOT}/usb_joystick.c
        ${TEENSY_ROOT}/usb_mouse.c
        ${TEENSY_ROOT}/analog.c
        ${TEENSY_ROOT}/usb_seremu.c
        ${TEENSY_ROOT}/nonstd.c
        ${TEENSY_ROOT}/libc.c
        ${TEENSY_ROOT}/debugprintf.c
        ${TEENSY_ROOT}/delay.c
        ${TEENSY_ROOT}/usb_serial3.c
        ${TEENSY_ROOT}/eeprom.c
        ${TEENSY_ROOT}/usb_serial2.c
        ${TEENSY_ROOT}/usb_midi.c
        ${TEENSY_ROOT}/usb_keyboard.c
        ${TEENSY_ROOT}/usb_rawhid.c
        ${TEENSY_ROOT}/pwm.c
        ${TEENSY_ROOT}/usb_serial.c
        ${TEENSY_ROOT}/usb_touch.c
        ${TEENSY_ROOT}/usb_desc.c
        ${TEENSY_ROOT}/startup.c
        )

set(TEENSY_CXX_CORE_FILES
        ${TEENSY_ROOT}/Tone.cpp
        ${TEENSY_ROOT}/serialEventUSB2.cpp
        ${TEENSY_ROOT}/IPAddress.cpp
        ${TEENSY_ROOT}/serialEventUSB1.cpp
        ${TEENSY_ROOT}/WString.cpp
        ${TEENSY_ROOT}/DMAChannel.cpp
        ${TEENSY_ROOT}/Print.cpp
        ${TEENSY_ROOT}/AudioStream.cpp
        ${TEENSY_ROOT}/HardwareSerial8.cpp
        ${TEENSY_ROOT}/serialEvent8.cpp
        ${TEENSY_ROOT}/new.cpp
        ${TEENSY_ROOT}/serialEvent6.cpp
        ${TEENSY_ROOT}/HardwareSerial7.cpp
        ${TEENSY_ROOT}/HardwareSerial.cpp
        ${TEENSY_ROOT}/HardwareSerial6.cpp
        ${TEENSY_ROOT}/serialEvent7.cpp
        ${TEENSY_ROOT}/serialEvent5.cpp
        ${TEENSY_ROOT}/HardwareSerial4.cpp
        ${TEENSY_ROOT}/HardwareSerial5.cpp
        ${TEENSY_ROOT}/serialEvent4.cpp
        ${TEENSY_ROOT}/serialEvent.cpp
        ${TEENSY_ROOT}/Stream.cpp
        ${TEENSY_ROOT}/HardwareSerial1.cpp
        ${TEENSY_ROOT}/serialEvent1.cpp
        ${TEENSY_ROOT}/HardwareSerial2.cpp
        ${TEENSY_ROOT}/serialEvent3.cpp
        ${TEENSY_ROOT}/serialEvent2.cpp
        ${TEENSY_ROOT}/HardwareSerial3.cpp
        ${TEENSY_ROOT}/usb_flightsim.cpp
        ${TEENSY_ROOT}/IntervalTimer.cpp
        ${TEENSY_ROOT}/usb_audio.cpp
        ${TEENSY_ROOT}/usb_inst.cpp
        ${TEENSY_ROOT}/main.cpp
        ${TEENSY_ROOT}/yield.cpp
        ${TEENSY_ROOT}/EventResponder.cpp
        ${TEENSY_ROOT}/WMath.cpp

        )

add_library(${TARGET_NAME}_TC
        ${TEENSY_C_CORE_FILES}
        ${TEENSY_CXX_CORE_FILES}
        )
set_source_files_properties(${TEENSY_C_CORE_FILES}
        PROPERTIES COMPILE_FLAGS ${TARGET_C_FLAGS})
set_source_files_properties(${TEENSY_CXX_CORE_FILES}
        PROPERTIES COMPILE_FLAGS ${TARGET_CXX_FLAGS})
target_include_directories(${TARGET_NAME}_TC PUBLIC ${TEENSY_ROOT})
add_executable(
        ${TARGET_NAME} main.cpp
)
target_link_libraries(${TARGET_NAME} raytracer_lib ${TARGET_NAME}_TC)
set_target_properties(${TARGET_NAME} PROPERTIES
        OUTPUT_NAME ${TARGET_NAME}
        SUFFIX ".elf"
        )
set(TARGET_ELF "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.elf")
message("${TARGET_ELF}")
set(EEPROM_OPTS -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0)
set(HEX_OPTS -O ihex -R .eeprom)
add_custom_command(OUTPUT ${TARGET_ELF}.eep
        COMMAND ${CMAKE_OBJCOPY} ${EEPROM_OPTS} ${TARGET_ELF} ${TARGET_ELF}.eep --verbose
        DEPENDS ${TARGET_NAME})
add_custom_command(OUTPUT ${TARGET_ELF}.hex
        COMMAND ${CMAKE_OBJCOPY} ${HEX_OPTS} ${TARGET_ELF} ${TARGET_ELF}.hex
        DEPENDS ${TARGET_NAME})
add_custom_target(${TARGET_NAME}_Firmware ALL
        DEPENDS ${TARGET_ELF}.eep ${TARGET_ELF}.hex)
add_dependencies(${TARGET_NAME}_Firmware ${TARGET_NAME})
