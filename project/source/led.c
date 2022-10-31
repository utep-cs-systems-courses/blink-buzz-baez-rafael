#include <msp430.h>
#include "led.h"

// Turn on LEDS
void led_initialize()
{
  P1DIR |= LEDS;
  led_update(0);
}

/*
  Default case will turn off
  LEDS, 1-3 will turn the 
  LEDS on like a binary counter
  4 & 5 will toggle the red
  and green led respectively.
 */
void led_update(char combo)
{
  switch(combo)
    {
    case 1:
      P1OUT &= ~LED_GREEN;
      P1OUT |= LED_RED;
      break;
    case 2:
      P1OUT &= ~LED_RED;
      P1OUT |= LED_GREEN;
      break;
    case 3:
      P1OUT |= LEDS;
      break;
    case 4:
      P1OUT ^= LED_RED;
      break;
    case 5:
      P1OUT ^= LED_GREEN;
      break;
    default:
      P1OUT &= ~LEDS;
    }
}
