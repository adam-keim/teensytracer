set(TARGET_NAME Teensy)

add_executable(
        ${TARGET_NAME} main.cpp
)
target_link_libraries(${TARGET_NAME} raytracer_lib)
set_target_properties(${TARGET_NAME} PROPERTIES
        OUTPUT_NAME ${TARGET_NAME}
        SUFFIX ".elf"
        )
set(TARGET_ELF "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME}.elf")
set(EEPROM_OPTS -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0)
set(HEX_OPTS -O ihex -R .eeprom)
add_custom_command(OUTPUT ${TARGET_ELF}.eep
        COMMAND ${CMAKE_OBJCOPY} ${EEPROM_OPTS} ${TARGET_ELF} ${TARGET_ELF}.eep
        DEPENDS ${TARGET_ELF})
add_custom_command(OUTPUT ${TARGET_ELF}.hex
        COMMAND ${CMAKE_OBJCOPY} ${HEX_OPTS} ${TARGET_ELF} ${TARGET_ELF}.hex
        DEPENDS ${TARGET_ELF})
add_custom_target(${TARGET_NAME}_Firmware ALL
        DEPENDS ${TARGET_ELF}.eep ${TARGET_ELF}.hex)
add_dependencies(${TARGET_NAME}_Firmware ${TARGET_NAME})
