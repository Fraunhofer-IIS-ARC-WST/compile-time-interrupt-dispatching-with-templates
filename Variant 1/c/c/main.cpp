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

#include "InterruptDispatcher.h"

extern "C" void __dtors_end();

void reset(void) __attribute__((naked));

void reset(void) {
  asm("clr r1");
  SREG = 0;
  SP = RAMEND;
  goto *&__dtors_end;
}

int main() {
  while(1);
}

extern "C"  void _exit();

void jmp_main(void) __attribute__((naked, section(".init9")));

void jmp_main(void) {
  main();
  goto *&_exit;
}
