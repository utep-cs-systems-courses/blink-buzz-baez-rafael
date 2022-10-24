# Makefile config (Obtained from 8-switch)
COMMON_OBJECTS = main.o
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

# Switch compiler to msp430 one
CC	       = msp430-elf-gcc
AS	       = msp420-elf-as

all: final.elf

# Some rules for file(s)
final.elf: ${COMMON_OBJECTS} ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: final.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
