## Author: Adam Keim
set(TOOLCHAIN_PREFIX arm-none-eabi)
set(TOOLCHAIN_ROOT /usr/local)
set(TEENSY_CORES_ROOT ${CMAKE_SOURCE_DIR}/cores)
set(TEENSY_ROOT ${TEENSY_CORES_ROOT}/teensy4)
set(VERBOSE 1)
set(TEENSY_FREQUENCY 600)
set(TEENSY_USB_MODE serial)
set(MCU IMXRT1062)
set(MCU_LOWER imxrt1062)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING 1)


set(CMAKE_C_COMPILER "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-gcc" CACHE PATH "gcc" FORCE)
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-g++" CACHE PATH "g++" FORCE)
set(CMAKE_AR "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-ar" CACHE PATH "archive" FORCE)
set(CMAKE_LINKER "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-ld" CACHE PATH "linker" FORCE)
set(CMAKE_NM "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-nm" CACHE PATH "nm" FORCE)
set(CMAKE_OBJCOPY "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-objcopy" CACHE PATH "objcopy" FORCE)
set(CMAKE_OBJDUMP "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-objdump" CACHE PATH "objdump" FORCE)
set(CMAKE_STRIP "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-strip" CACHE PATH "strip" FORCE)
set(CMAKE_RANLIB "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-ranlib" CACHE PATH "ranlib" FORCE)

include_directories("${TEENSY_ROOT}")


#set(TARGET_FLAGS "-mfloat-abi=hard -mfpu=fpv5-d16 -mthumb -mcpu=cortex-m7 ")
#set(BASE_FLAGS "-Os ${TARGET_FLAGS}")
#
#set(CMAKE_C_FLAGS "${BASE_FLAGS} -DTIME_T=1421620748" CACHE STRING "c flags") # XXX Generate TIME_T dynamically.
#set(CMAKE_CXX_FLAGS "${BASE_FLAGS} -fno-exceptions -fno-rtti -felide-constructors -std=gnu++14" CACHE STRING "c++ flags")

set(OPTIONS "-DF_CPU=${TEENSY_FREQUENCY}000000 -DUSB_SERIAL -D__${MCU}__ -DARDUINO=10810 -DTEENSYDUINO=149 -DARDUINO_TEENSY40 -DLAYOUT_US_ENGLISH")
set(CPU_OPTIONS "-mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -mthumb")
set(BASE_FLAGS "-Wall -g -O2 ${CPU_OPTIONS} -MMD ${OPTIONS} -I. -ffunction-sections -fdata-sections")
set(CMAKE_C_FLAGS "${BASE_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=gnu++14 -felide-constructors -fno-exceptions -fpermissive -fno-rtti -Wno-error=narrowing")


set(LINKER_FLAGS "-O3 -Wl,--gc-sections,--relax ${CPU_OPTIONS} -T${TEENSY_ROOT}/${MCU_LOWER}.ld")
#set(LINKER_LIBS  "-larm_cortexM7lfsp_math -lm -lstdc++")
set(LINKER_LIBS  "-lm -lstdc++")
#set(LINKER_FLAGS "-Os -Wl,--gc-sections ${TARGET_FLAGS} -T${TEENSY_ROOT}/imxrt1062.ld" )
#set(LINKER_LIBS "--verbose  -lm -lstdc++" )
set(CMAKE_SHARED_LINKER_FLAGS "${LINKER_FLAGS}" CACHE STRING "linker flags" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS "${LINKER_FLAGS}" CACHE STRING "linker flags" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "${LINKER_FLAGS}" CACHE STRING "linker flags" FORCE)

set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_C_COMPILER> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> -o <TARGET>  <OBJECTS> <LINK_LIBRARIES> ${LINKER_LIBS}" CACHE STRING "Linker command line" FORCE)
