/*
 * systick_private.h
 *
 *  Created on: Jan 15, 2025
 *      Author: omar
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

// SysTick Registers (Base Address: 0xE000E010)
#define STK_CTRL     (*(volatile uint32_t *)(0xE000E010))
#define STK_LOAD     (*(volatile uint32_t *)(0xE000E014))
#define STK_VAL      (*(volatile uint32_t *)(0xE000E018))
#define STK_CALIB    (*(volatile uint32_t *)(0xE000E01C))

// SysTick Control and Status Register Bits
#define CTRL_ENABLE      (1U << 0)
#define CTRL_TICKINT     (1U << 1)
#define CTRL_CLKSOURCE   (1U << 2)
#define CTRL_COUNTFLAG   (1U << 16)

#endif /* SYSTICK_PRIVATE_H_ */
