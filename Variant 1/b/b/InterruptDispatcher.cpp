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
#include "avr/interrupt.h"

typedef InterruptDispatcher<> MyDispatcher;

ISR(CRCSCAN_NMI_vect) __attribute__((naked));
ISR(CRCSCAN_NMI_vect) {
  goto *MyDispatcher::dispatch(CRCSCAN_NMI_vect_num);
}

ISR(BOD_VLM_vect) __attribute__((naked));
ISR(BOD_VLM_vect) {
  goto *MyDispatcher::dispatch(BOD_VLM_vect_num);
}

ISR(PORTA_PORT_vect) __attribute__((naked));
ISR(PORTA_PORT_vect) {
  goto *MyDispatcher::dispatch(PORTA_PORT_vect_num);
}

ISR(PORTB_PORT_vect) __attribute__((naked));
ISR(PORTB_PORT_vect) {
  goto *MyDispatcher::dispatch(PORTB_PORT_vect_num);
}

ISR(PORTC_PORT_vect) __attribute__((naked));
ISR(PORTC_PORT_vect) {
  goto *MyDispatcher::dispatch(PORTC_PORT_vect_num);
}

ISR(RTC_CNT_vect) __attribute__((naked));
ISR(RTC_CNT_vect) {
  goto *MyDispatcher::dispatch(RTC_CNT_vect_num);
}

ISR(RTC_PIT_vect) __attribute__((naked));
ISR(RTC_PIT_vect) {
  goto *MyDispatcher::dispatch(RTC_PIT_vect_num);
}

ISR(TCA0_OVF_vect) __attribute__((naked));
ISR(TCA0_OVF_vect) {
  goto *MyDispatcher::dispatch(TCA0_OVF_vect_num);
}

ISR(TCA0_HUNF_vect) __attribute__((naked));
ISR(TCA0_HUNF_vect) {
  goto *MyDispatcher::dispatch(TCA0_HUNF_vect_num);
}

ISR(TCA0_CMP0_vect) __attribute__((naked));
ISR(TCA0_CMP0_vect) {
  goto *MyDispatcher::dispatch(TCA0_CMP0_vect_num);
}

ISR(TCA0_CMP1_vect) __attribute__((naked));
ISR(TCA0_CMP1_vect) {
  goto *MyDispatcher::dispatch(TCA0_CMP1_vect_num);
}

ISR(TCA0_CMP2_vect) __attribute__((naked));
ISR(TCA0_CMP2_vect) {
  goto *MyDispatcher::dispatch(TCA0_CMP2_vect_num);
}

ISR(TCB0_INT_vect) __attribute__((naked));
ISR(TCB0_INT_vect) {
  goto *MyDispatcher::dispatch(TCB0_INT_vect_num);
}

ISR(TCD0_OVF_vect) __attribute__((naked));
ISR(TCD0_OVF_vect) {
  goto *MyDispatcher::dispatch(TCD0_OVF_vect_num);
}

ISR(TCD0_TRIG_vect) __attribute__((naked));
ISR(TCD0_TRIG_vect) {
  goto *MyDispatcher::dispatch(TCD0_TRIG_vect_num);
}

ISR(AC0_AC_vect) __attribute__((naked));
ISR(AC0_AC_vect) {
  goto *MyDispatcher::dispatch(AC0_AC_vect_num);
}

ISR(ADC0_RESRDY_vect) __attribute__((naked));
ISR(ADC0_RESRDY_vect) {
  goto *MyDispatcher::dispatch(ADC0_RESRDY_vect_num);
}

ISR(ADC0_WCOMP_vect) __attribute__((naked));
ISR(ADC0_WCOMP_vect) {
  goto *MyDispatcher::dispatch(ADC0_WCOMP_vect_num);
}

ISR(TWI0_TWIS_vect) __attribute__((naked));
ISR(TWI0_TWIS_vect) {
  goto *MyDispatcher::dispatch(TWI0_TWIS_vect_num);
}

ISR(TWI0_TWIM_vect) __attribute__((naked));
ISR(TWI0_TWIM_vect) {
  goto *MyDispatcher::dispatch(TWI0_TWIM_vect_num);
}

ISR(SPI0_INT_vect) __attribute__((naked));
ISR(SPI0_INT_vect) {
  goto *MyDispatcher::dispatch(SPI0_INT_vect_num);
}

ISR(USART0_RXC_vect) __attribute__((naked));
ISR(USART0_RXC_vect) {
  goto *MyDispatcher::dispatch(USART0_RXC_vect_num);
}

ISR(USART0_DRE_vect) __attribute__((naked));
ISR(USART0_DRE_vect) {
  goto *MyDispatcher::dispatch(USART0_DRE_vect_num);
}

ISR(USART0_TXC_vect) __attribute__((naked));
ISR(USART0_TXC_vect) {
  goto *MyDispatcher::dispatch(USART0_TXC_vect_num);
}

ISR(NVMCTRL_EE_vect) __attribute__((naked));
ISR(NVMCTRL_EE_vect) {
  goto *MyDispatcher::dispatch(NVMCTRL_EE_vect_num);
}

ISR(BADISR_vect) {
  while(1);     
}
