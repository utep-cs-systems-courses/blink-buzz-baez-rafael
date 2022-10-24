#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT6               // P1.0
#define LED_GREEN BIT0             // P1.6
#define LEDS (BIT0 | BIT6)

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1		/* only 1 switch on this board */

void main(void) 
{  
  configureClocks();
  enableWDTInterrupts();
  
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */

  or_sr(0x18);  // CPU off, GIE on
} 

static int state = 0;
void
switch_interrupt_handler()
{
  char p1val = P1IN;		/* switch is in P1 */

/* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */

  if (!(p1val & SW1)) {
    //P1OUT ^= LED_RED;
    //P1OUT ^= LED_GREEN;
    if (state == 1) state = 2;
    else if (state == 2) state = 1;
  }
  
  if (!(P1OUT & LEDS) & state == 0){
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
    state = 2;
  }
}


/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

static int secondCount = 0;
void __interrupt_vec(WDT_VECTOR) WDT()
{
  
  if (state == 1) P1OUT &= ~LED_GREEN;
  if (state == 2) P1OUT &= ~LED_RED;
  
  secondCount++;
  if (secondCount >= 250) {
    secondCount = 0;
    if (state == 1) P1OUT ^= LED_RED;
    if (state == 2) P1OUT ^= LED_GREEN;
  }
}
