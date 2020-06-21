
CC=avr-gcc

CFLAGS=-mmcu=atmega8 -DF_CPU=16000000UL -O2 -g
LIBOBJ=ps2kbd.o

all: ps2kbd_test.hex ps2kbd_test.lst

ps2kbd_test.hex: $(LIBOBJ)

clean:
	$(RM) *.hex *.elf *.lst *.o

.SUFFIXES: .elf .hex .lst

.o.elf:
	$(CC) $(CFLAGS) -o $*.elf $*.o $(LIBOBJ)

.elf.lst:
	avr-objdump -h -S $*.elf > $*.lst

.elf.hex:
	avr-objcopy -j .text -j .data -O ihex $*.elf $*.hex
