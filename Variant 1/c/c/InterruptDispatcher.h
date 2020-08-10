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

#ifndef INTERRUPTDISPATCHER_H_
#define INTERRUPTDISPATCHER_H_

#include <avr/interrupt.h>

typedef void (*fptr)();

extern "C"  void __vector_default(void);

template<typename... Rest>
struct InterruptDispatcher {
  static constexpr fptr dispatch(uint8_t vectNum) __attribute__((always_inline)) {
    return __vector_default;
  }
};
  
template <typename First, typename ...Rest>
struct InterruptDispatcher<First, Rest...> {
  static constexpr fptr dispatch(uint8_t vectNum) __attribute__((always_inline)) {
    constexpr bool result = First::check(vectNum);
    if(result) {
      return First::interruptServiceRoutine;
    } else {
      return InterruptDispatcher<Rest...>::dispatch(vectNum);
    }
  }
};

#endif /* INTERRUPTDISPATCHER_H_ */
