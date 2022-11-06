#include <msp430.h>
#include "timeMethods.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  tickMethod();
  increaseTime();
}
