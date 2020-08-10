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
#include "config.h"

extern "C" void __dtors_end();

void reset(void) __attribute__((naked));

void reset(void) {
  asm("clr r1");
  SREG = 0;
  SP = RAMEND;
  goto *&__dtors_end;
}

int main(void) {
  millisB::init_millis_func();
  while (1) {
    volatile uint32_t time = millisB::millis_func();
  }
}

extern "C"  void _exit();

void jmp_main(void) __attribute__((naked, section(".init9")));

void jmp_main(void) {
  main();
  goto *&_exit;
}

