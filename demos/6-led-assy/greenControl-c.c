#include <msp430.h>
#include "led.h"

void greenControl(int on)
{
  if (on) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
}

static int blinkLimit = 5;
void blinkUpdate()
{
  static int blinkCount = 0;
  blinkCount ++;
  if (blinkCount >= blinkLimit){
     blinkCount = 0;
     greenControl(1);
  }
  else{
    greenControl(0);
  }
}
