## Author: Adam Keim
set(TOOLCHAIN_PREFIX arm-none-eabi-)
set(TOOLCHAIN_ROOT /usr/local)
set(TEENSY_CORES_ROOT cores)
set(TEENSY_ROOT ${TEENSY_CORES_ROOT}/teensy4)

set(TEENSY_FREQUENCY 600)
set(TEENSY_USB_MODE serial)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING 1)

set(CMAKE_C_COMPILER "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-g++")
set(CMAKE_AR "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-ar")
set(CMAKE_LINKER "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-ld")
set(CMAKE_NM "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-nm")
set(CMAKE_OBJCOPY "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-objcopy")
set(CMAKE_OBJDUMP "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-objdump")
set(CMAKE_STRIP "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-strip")
set(CMAKE_RANLIB "${TOOLCHAIN_ROOT}/bin/${TOOLCHAIN_PREFIX}-ranlib")

include_directories("${TEENSY_ROOT}")

