#include "systick_interface.h"
#include "systick_config.h"
#include "systick_private.h"

// Global Variables
static void (*SysTick_Callback)(void) = 0;

// Initialize SysTick Timer
void SysTick_Init(uint32_t reload_value, uint8_t clock_source, uint8_t interrupt) {
    // Validate the reload value (must be less than or equal to 0xFFFFFF)
    if (reload_value == 0 || reload_value > 0xFFFFFF) {
        reload_value = (SYSTEM_CLOCK_HZ / 1000);  // Default to 1 ms
    }

    // Stop the timer
    STK_CTRL = 0;

    // Load the reload value
    STK_LOAD = reload_value;

    // Clear the current value register
    STK_VAL = 0;

    // Configure clock source and interrupt
    STK_CTRL = (clock_source << 2) | (interrupt << 1);
}


// Delay in milliseconds (Polling)
void SysTick_DelayMs(uint32_t ms) {
    uint32_t reload_value = (SYSTEM_CLOCK_HZ / 1000) * ms;
    SysTick_Init(reload_value, SYSTICK_DEFAULT_CLOCK, 0);
    STK_CTRL |= CTRL_ENABLE;  // Start the timer

    // Wait until the COUNTFLAG is set
    while (!(STK_CTRL & CTRL_COUNTFLAG));

    SysTick_Stop();
}

// Delay in microseconds (Polling)
void SysTick_DelayUs(uint32_t us) {
    uint32_t reload_value = (SYSTEM_CLOCK_HZ / 1000000) * us;
    SysTick_Init(reload_value, SYSTICK_DEFAULT_CLOCK, 0);
    STK_CTRL |= CTRL_ENABLE;  // Start the timer

    // Wait until the COUNTFLAG is set
    while (!(STK_CTRL & CTRL_COUNTFLAG));

    SysTick_Stop();
}

// Set SysTick Callback for Interrupts
void SysTick_SetCallback(void (*callback)(void)) {
    SysTick_Callback = callback;
}

// Start SysTick Timer
void SysTick_Start(void) {
    STK_CTRL |= CTRL_ENABLE;
}

// Stop SysTick Timer
void SysTick_Stop(void) {
    STK_CTRL &= ~CTRL_ENABLE;
}

// Get Elapsed Time in Ticks
uint32_t SysTick_GetElapsedTime(void) {
    return STK_LOAD - STK_VAL;
}

// Get Remaining Time in Ticks
uint32_t SysTick_GetRemainingTime(void) {
    return STK_VAL;
}

// SysTick Interrupt Handler
void SysTick_Handler(void) {
    if (SysTick_Callback) {
        SysTick_Callback();
    }
}
