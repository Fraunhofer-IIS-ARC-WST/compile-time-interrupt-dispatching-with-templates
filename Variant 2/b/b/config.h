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

#ifndef CONFIG_H_
#define CONFIG_H_

#include "InterruptDispatcher.h"
#include "AVRseries_millis.h"

typedef AVRseries_millis<F_CPU, TCB0_ADDR> millisB;
typedef InterruptDispatcher<millisB> MyDispatcher;

#endif /* CONFIG_H_ */