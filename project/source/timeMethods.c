#include <msp430.h>
#include "timeMethods.h"
#include "stateMusic.h"
#include "stateLights.h"

static int ticks;
static int cycle;
volatile unsigned int time = 0;

void setCycle(int numTicks)
{
  cycle = numTicks;
}
void waitCycle()
{
  ticks++;
  if(ticks >= cycle){
    advanceMusic();
    advanceLights();
    ticks = 0;
  }
}
void tickMethod()
{
  waitCycle();
}
