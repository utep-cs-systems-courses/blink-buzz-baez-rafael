#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "timeMethods.h"

static char toyState = 0;

void lights(char sig)
{
  if (!sig)
    {
      toyState = 0;
      led_update(0);
      return;
    }
  else
    {
      switch(sig)
	{
	case 1:
	  led_update(4);
	  break;
	case 2:
	  led_update(5);
	  break;
	case 3:
	  led_update(4);
	  led_update(5);
	  break;
	}
    }
}

void switch_state(char sig)
{
  /*
  if (!sig)
    {
      toyState = 0;
      led_update(0);
      return;
    }
  */
  switch(toyState)
    {
    case 1:
      lights(sig);
      break;
    case 2:
      toyState = 2;
      break;
    case 3:
      toyState = 3;
      break;
    default:
      toyState = sig;
      led_update(sig);
    }
}
