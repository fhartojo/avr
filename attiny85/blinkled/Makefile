PROG = main.elf
HEX = main.hex
MCU = attiny85
CC = avr-gcc
CPPFLAGS = -DF_CPU=1000000
CFLAGS = -Wall -mmcu=$(MCU)
LDFLAGS = -mmcu=$(MCU)

AVR_SIZE = avr-size
AVR_OBJCOPY = avr-objcopy
AVRDUDE = avrdude

OBJS = main.o

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)
	$(AVR_SIZE) --format=avr --mcu=$(MCU) $(PROG)
	$(AVR_OBJCOPY) -j .text -j .data -O ihex $(PROG) $(HEX)

.c.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<

flash: $(HEX)
	sudo $(AVRDUDE) -c usbtiny -Pusb -p $(MCU) -U flash:w:$(HEX)
