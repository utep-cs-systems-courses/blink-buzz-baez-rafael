#include <msp430.h>
#include "timeMethods.h"
#include "stateMachines.h"

static char enable = 0;
static char loc = 0;
void setEnable(char signal)
{
  enable = signal;
}
void setLocation(char idx)
{
  loc = idx;
}
void advanceMusic()
{
  enable = 1;
}
