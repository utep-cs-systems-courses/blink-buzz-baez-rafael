#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  /*
  
  switch (stateR) {
  case 0:
    red_on = 1;
    stateR = 1;
    break;
  case 1:
    red_on = 0;
    stateR = 0;
    break;
    }*/
  return 1;			
}

char toggle_green()	/* only toggle green if red is on!  */
{
  /*
  static char stateG = 0;
  
  switch (stateG) {
  case 0:
    green_on = 1;
    stateG = 1;
    break;
  case 1:
    green_on = 0;
    stateG = 0;
    break;
    }*/
  return 1;
}


void state_advance()		/* alternate between toggling red & green */
{
  static int state = -1;  
  state++;
  if (state >= 4){
    state = 0;
  }
  switch (state){
  case 0: red_on = 0; green_on = 0; break;
  case 1: red_on = 1; green_on = 0; break;
  case 2: red_on = 0; green_on = 1; break;
  case 3: red_on = 1; green_on = 1; break;
  }

  led_changed = 1;
  led_update();
}



