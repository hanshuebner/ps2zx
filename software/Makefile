
CC=avr-gcc

CFLAGS=-mmcu=atmega8 -DF_CPU=16000000UL -O2 -g

all: ps2zx.hex

ps2zx.hex: ps2kbd.o ps2kbd_test.o
