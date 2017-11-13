ARDUINO_DIR            = /usr/share/arduino
TARGET                 = blink
ARDUINO_LIBS           =
BOARD_TAG              = mega2560
MCU                    = atmega2560
F_CPU                  = 16000000
ARDUINO_PORT           = /dev/ttyACM0
AVRDUDE_ARD_BAUDRATE   = 115200

CPPFLAGS               = -fdiagnostics-color=always -IArduino_FreeRTOS_Library/src
LOCAL_CPP_SRCS         ?= $(wildcard ./Arduino_FreeRTOS_Library/src/*.cpp *.cpp)
LOCAL_C_SRCS           ?= $(wildcard ./Arduino_FreeRTOS_Library/src/*.c *.c)

include /usr/share/arduino/Arduino.mk
