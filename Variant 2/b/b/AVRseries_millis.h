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

#include <stdint.h>
#include <avr/io.h>
#include <util/atomic.h>
#include "InterruptHandler.h"

#ifndef AVRSERIES_MILLIS_H_
#define AVRSERIES_MILLIS_H_

enum TCXN_ADDR : uintptr_t {
	#ifdef TCA0
	TCA0_ADDR = (uintptr_t) &TCA0
	#endif
	#ifdef TCB0
	,
	TCB0_ADDR = (uintptr_t) &TCB0
	#endif
	#ifdef TCB1
	,
	TCB1_ADDR = (uintptr_t) &TCB1
	#endif
	#ifdef TCB2
	,
	TCB2_ADDR = (uintptr_t) &TCB2
	#endif
	#ifdef TCB3
	,
	TCB3_ADDR = (uintptr_t) &TCB3
	#endif
  #ifdef TCD0
  ,
  TCD0_ADDR = (uintptr_t) &TCD0
  #endif
};

template <uint32_t cpu_clk, TCXN_ADDR TCXN>
class AVRseries_millis :  InterruptHandler<AVRseries_millis<cpu_clk, TCXN> > {
 public:
	static uint32_t millis_func(void);
	static void init_millis_func(void);
  static void interruptServiceRoutine() __attribute__((signal));
  static volatile uint32_t timer_millis;

  static constexpr bool check(uint8_t vectNum) {
    switch (TCXN) {
      case TCB0_ADDR: return (vectNum == TCB0_INT_vect_num ? true : false);
      case TCA0_ADDR: return (vectNum == TCA0_OVF_vect_num ? true : false);
      case TCD0_ADDR: return (vectNum == TCD0_OVF_vect_num ? true : false);
      default: return false;
    }
  }
};

template <uint32_t cpu_clk, TCXN_ADDR TCXN>
volatile uint32_t AVRseries_millis<cpu_clk, TCXN>::timer_millis = 0;

template <uint32_t cpu_clk, TCXN_ADDR TCXN>
uint32_t AVRseries_millis<cpu_clk, TCXN>::millis_func(void) {
  uint32_t tmp;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
	  tmp = timer_millis;
  }  
  return tmp;
}

_Pragma("GCC diagnostic push")
_Pragma("GCC diagnostic ignored \"-Wmisspelled-isr\"")
template <uint32_t cpu_clk, TCXN_ADDR TCXN>
void AVRseries_millis<cpu_clk, TCXN>::interruptServiceRoutine() {
  switch (TCXN) {
    case TCB0_ADDR: TCB0.INTFLAGS = TCB_CAPT_bm; break;
    case TCA0_ADDR: TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm; break;
    case TCD0_ADDR: TCD0.INTFLAGS = TCD_OVF_bm; break;
    default: break;
  }
  ++timer_millis;
}
_Pragma("GCC diagnostic pop") \

template <uint32_t cpu_clk, TCXN_ADDR TCXN>
void AVRseries_millis<cpu_clk, TCXN>::init_millis_func(void) {
  if(TCXN == TCB0_ADDR) {
	  (*(TCB_t*) TCXN).CCMP =	static_cast<uint16_t>(cpu_clk/1000);
	  (*(TCB_t*) TCXN).INTCTRL = TCB_CAPT_bm;
	  (*(TCB_t*) TCXN).EVCTRL =	0;
	  (*(TCB_t*) TCXN).CTRLB = 0;
   	(*(TCB_t*) TCXN).CTRLA = TCB_ENABLE_bm;
  } else {
    (*(TCA_t*) TCXN).SINGLE.PER =	static_cast<uint16_t>(cpu_clk/1000);
    (*(TCA_t*) TCXN).SINGLE.INTCTRL =	TCA_SINGLE_OVF_bm;
    (*(TCA_t*) TCXN).SINGLE.EVCTRL = 0;
    (*(TCA_t*) TCXN).SINGLE.CTRLB =	0;
    (*(TCA_t*) TCXN).SINGLE.CTRLA =	TCA_SINGLE_CLKSEL_DIV1_gc | TCA_SINGLE_ENABLE_bm;
  }                 
}

#endif /* AVRSERIES_MILLIS_H_ */
