#include <msp430.h>
#include "led.h"
#include "timeMethods.h"
#include "stateLights.h"

static char enable = 0;
void setEnableL(char signal)
{
  if (signal < 0)
    {
      if (enable == 0)
	{
	  enable = 1;
	}
      else
	{
	  enable = 0;
	}
      return;
    }
  enable = signal;
}
void useSignal(char signal)
{
  switch(signal)
    {
    case 1:
      wait(62);
      break;
    case 2:
      wait(125);
      break;
    case 3:
      setEnableL(-1);
      break;
    }
}
void advanceLights()
{
  if (!enable)
    {
      return;
    }
  led_update(4);
}
