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

#ifndef INTERRUPTHANDLER_H_
#define INTERRUPTHANDLER_H_

template <typename Derived>
class InterruptHandler {

  static constexpr bool check(uint8_t vectNum) {
    return Derived::check(vectNum);
  }
  
  static void interruptServiceRoutine() {
    Derived::interruptServiceRoutine();
  }

};

#endif /* INTERRUPTHANDLER_H_ */