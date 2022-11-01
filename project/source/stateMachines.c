#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "timeMethods.h"
#include "stateMusic.h"
#include "stateLights.h"

static char toyState = 0;

void lights(char sig)
{
  if (!sig)
    {
      toyState = 0;
      led_update(0);
      return;
    }
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

void flashing_lights(char sig)
{
  if(!sig)
    {
      setEnableL(0);
      toyState = 0;
      led_update(0);
      return;
    }
  useSignal(sig);
}

void music(char sig)
{
  if(!sig)
    {
      setEnable(0);
      setLocation(0);
      toyState = 0;
      led_update(0);
      return;
    }
  switch(sig)
    {
    case 1:
      setEnable(-1);
      break;
    case 2:
      setLocation(0);
      break;
    case 3:
      setLocation(-10);
      break;
    }
}

void switch_state(char sig)
{
  switch(toyState)
    {
    case 1:
      lights(sig);
      break;
    case 2:
      wait(250);
      flashing_lights(sig);
      break;
    case 3:
      music(sig);
      break;
    default:
      toyState = sig;
      led_update(sig);
    }
}
