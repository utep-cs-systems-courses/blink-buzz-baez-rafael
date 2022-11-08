# Makefile
COMMON_OBJECTS = main.o led.o buzzer.o stateMachines.o switches.o timeMethods.o stateMusic.o stateLights.o p2_interrupt_handler.o wdInterruptHandler.o
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

# Switching Compiler
CC	       = msp430-elf-gcc
AS	       = msp430-elf-as

# Default
all: final.elf

# Clean
clean:
	rm -f *.o *.elf

# Last rules
final.elf: ${COMMON_OBJECTS} tickMethod-c.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
final-s.elf: ${COMMON_OBJECTS} tickMethod-s.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
load: final.elf
	msp430loader.sh final.elf
load-s: final-s.elf
	msp430loader.sh final-s.elf

tickMethod-c.o: timeMethods.h

wdInterruptHandler.o: timeMethods.h
