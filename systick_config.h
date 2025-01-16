/*
 * systick_config.h
 *
 *  Created on: Jan 15, 2025
 *      Author: omar
 */


#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

// Define the system clock frequency (in Hz)
#define SYSTEM_CLOCK_HZ  48000000U  // Example: 48 MHz for STM32H7

// SysTick default configuration
#define SYSTICK_DEFAULT_CLOCK    SYSTICK_CLOCK_HCLK
#define SYSTICK_DEFAULT_INTERRUPT 1  // 1: Enable interrupt, 0: Disable interrupt

#endif /* SYSTICK_CONFIG_H_ */
