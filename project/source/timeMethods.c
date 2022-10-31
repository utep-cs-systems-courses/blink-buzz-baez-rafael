#include <msp430.h>
#include "timeMethods.h"

static char ticks;

void wait(char delay)
{
  ticks = 0;
  
}

void tickMethod()
{
  ticks++;
}


