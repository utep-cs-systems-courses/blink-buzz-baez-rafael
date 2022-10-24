#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (LED_RED | LED_GREEN)
#define RED_ON 1
#define GREEN_ON 2

#define SW1 BIT3
#define SWITCHES SW1

void main(void)
{
  configureClocks();
  enableWDTInterrupts();
  
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;

  P1REN |= SWITCHES;
  P1IE |= SWITCHES;
  P1OUT |= SWITCHES;
  P1DIR &= ~SWITCHES;
  
  or_sr(0x18);
}

int state = 0;
void switch_interrupt_handler()
{
  char p1val = P1IN;

  P1IES |= (p1val & SWITCHES);
  P1IES &= (p1val | ~SWITCHES);

  if (state == 0)
    { 
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
      state = 1;
    }
  if (!(p1val & SW1)){
    if (state > 1){
      state = 1;
    }
    else{
      state = 2;
    }
  }
}

void __interrupt_vec(PORT1_VECTOR) Port_1()
{
  if (P1IFG & SWITCHES)
    {
      P1IFG &= ~SWITCHES;
      switch_interrupt_handler();
    }
}

int secondCount = 0;
void __interrupt_vec(WDT_VECTOR) WDT()
{
  if (state == 0){return;}
  secondCount++;
  if (state == 1){
    P1OUT &= ~LED_GREEN;
  }
  if(state == 2){
    P1OUT &= ~LED_RED;
  }
  if (secondCount >= 250)
    {
      secondCount = 0;
      if (state == 1)
	{
//P1OUT &= ~LED_GREEN;
          P1OUT ^= LED_RED;
        }
      if (state == 2)
	{
//P1OUT &= ~LED_RED;
          P1OUT ^= LED_GREEN;
        }
    }
}


