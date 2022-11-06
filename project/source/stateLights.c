#include <msp430.h>
#include "led.h"
#include "timeMethods.h"
#include "stateLights.h"

static char enable = 0;
void setEnableL(int signal)
{
  if (signal == -1)
    {
      enable = (enable)?0:1;
    }
  else
    {
      enable = signal;
    }
}
void useSignal(char signal)
{
  switch(signal)
    {
    case 1:
      setCycle(62);
      break;
    case 2:
      setCycle(125);
      break;
    case 3:
      setEnableL(-1);
      break;
    }
}
void advanceLights()
{
  if (enable)
    {
      led_update(4);
    }
}
