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
#include "config.h"
#include <avr/interrupt.h>

extern void reset(void) __attribute__((naked));

void vector0(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector0(void) {
  goto *&reset;
}

void vector1(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector1(void) {
  goto *MyDispatcher::dispatch(1);
}

void vector2(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector2(void) {
  goto *MyDispatcher::dispatch(2);
}

void vector3(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector3(void) {
  goto *MyDispatcher::dispatch(3);
}

void vector4(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector4(void) {
  goto *MyDispatcher::dispatch(4);
}

void vector5(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector5(void) {
  goto *MyDispatcher::dispatch(5);
}

void vector6(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector6(void) {
  goto *MyDispatcher::dispatch(6);
}

void vector7(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector7(void) {
  goto *MyDispatcher::dispatch(7);
}

void vector8(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector8(void) {
  goto *MyDispatcher::dispatch(8);
}

void vector9(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector9(void) {
  goto *MyDispatcher::dispatch(9);
}

void vector10(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector10(void) {
  goto *MyDispatcher::dispatch(10);
}

void vector11(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector11(void) {
  goto *MyDispatcher::dispatch(11);
}

void vector12(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector12(void) {
  goto *MyDispatcher::dispatch(12);
}

void vector13(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector13(void) {
  goto *MyDispatcher::dispatch(13);
}

void vector14(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector14(void) {
  goto *MyDispatcher::dispatch(14);
}

void vector15(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector15(void) {
  goto *MyDispatcher::dispatch(15);
}

void vector16(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector16(void) {
  goto *MyDispatcher::dispatch(16);
}

void vector17(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector17(void) {
  goto *MyDispatcher::dispatch(17);
}

void vector18(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector18(void) {
  goto *MyDispatcher::dispatch(18);
}

void vector19(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector19(void) {
  goto *MyDispatcher::dispatch(19);
}

void vector20(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector20(void) {
  goto *MyDispatcher::dispatch(20);
}

void vector21(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector21(void) {
  goto *MyDispatcher::dispatch(21);
}

void vector22(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector22(void) {
  goto *MyDispatcher::dispatch(22);
}

void vector23(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector23(void) {
  goto *MyDispatcher::dispatch(23);
}

void vector24(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector24(void) {
  goto *MyDispatcher::dispatch(24);
}

void vector25(void) __attribute__((naked));
__attribute__((section(".vectors")))
void vector25(void) {
  goto *MyDispatcher::dispatch(25);
}

ISR(BADISR_vect) {
  while(1);
}
