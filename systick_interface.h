/*
 * systick_interface.h
 *
 *  Created on: Jan 15, 2025
 *      Author: omar
 */
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#include <stdint.h>

// SysTick Control Macros
#define SYSTICK_CLOCK_HCLK        (1U)       // Use processor clock
#define SYSTICK_CLOCK_HCLK_DIV8   (0U)       // Use processor clock / 8

// Function Prototypes
void SysTick_Init(uint32_t reload_value, uint8_t clock_source, uint8_t interrupt);
void SysTick_DelayMs(uint32_t ms);
void SysTick_DelayUs(uint32_t us);
void SysTick_SetCallback(void (*callback)(void));
void SysTick_Start(void);
void SysTick_Stop(void);
uint32_t SysTick_GetElapsedTime(void);
uint32_t SysTick_GetRemainingTime(void);

#endif /* SYSTICK_INTERFACE_H_ */
