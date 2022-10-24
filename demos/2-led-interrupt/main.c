//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

static int cycle = 1;
static int seconds = 0;

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  seconds++;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;
  if (seconds%cycle == 0)
    {
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    }
  if (seconds >= 500)
    {
      seconds = 0;
      cycle++;
    }
  if (cycle >= 6)
    {
      cycle = 1;
    }
  //P1OUT |= LED_GREEN;
} 

