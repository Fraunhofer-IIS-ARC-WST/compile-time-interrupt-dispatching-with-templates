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

int main(void) {
  millisB::init_millis_func();
  while (1) {
    volatile uint32_t time = millisB::millis_func();
  }
}

