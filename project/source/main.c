#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

void main(void)
{
  configureClocks();
  switch_initialize();
  led_initialize();

  enableWDTInterrupts();

  or_sr(0x18);
}
