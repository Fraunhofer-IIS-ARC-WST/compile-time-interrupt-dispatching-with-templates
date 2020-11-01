/*
 * Fraunhofer-Institute for Integrated Circuits IIS
 * Am Wolfsmantel 33, 91058 Erlangen, Germany
 * www.iis.fraunhofer.de
 *
 * Application Center Wireless Sensor Systems
 * Sonntagsanger 1, 96450 Coburg, Germany
 *
 * Copyright Fraunhofer IIS, All rights reserved.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

volatile uint32_t timer_millis = 0;

uint32_t millis_func() {
  uint32_t tmp;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    tmp = timer_millis;
  }
  return tmp;
}

int main(void) {
  TCB0.CCMP = static_cast<uint16_t>(F_CPU/1000);
  TCB0.INTCTRL = TCB_CAPT_bm; // TCB_CAPT_bm;
  TCB0.EVCTRL =	0;
  TCB0.CTRLB =	0;
  TCB0.CTRLA = TCB_ENABLE_bm;

  while (1) {
    volatile uint32_t time = millis_func();
  }
}

ISR(TCB0_INT_vect) {
  TCB0.INTFLAGS = TCB_CAPT_bm; 
   ++timer_millis;
}

ISR(BADISR_vect) {
  while(1);  // if needed, replace with a more sophisticated code to handle unexpected interrupts
}
