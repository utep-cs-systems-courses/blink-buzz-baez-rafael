#include <msp430.h>
#include "timeMethods.h"
#include "stateMusic.h"
#include "stateLights.h"

static char ticks;
static char delay;

void wait(char numTicks)
{
  delay = numTicks;
}
void waitCycle()
{
  ticks++;
  if(ticks >= delay){
    advanceMusic();
    advanceLights();
    ticks = 0;
  }
}

void tickMethod()
{
  waitCycle();
}


