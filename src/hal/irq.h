/*
  automatically created hal/irq.h
*/

#include <hal/hw/PPB.h>



typedef struct {
    volatile uint32_t ISER;               //  Interrupt Set Enable
    volatile uint32_t RESERVED0[31];
    volatile uint32_t ICER;               // Interrupt Clear Enable
    volatile uint32_t RESERVED1[31U];
    volatile uint32_t ISPR;               // Interrupt Set Pending
    volatile uint32_t RESERVED2[31U];
    volatile uint32_t ICPR;               // Interrupt Clear Pending
    volatile uint32_t RESERVED3[31U];
    volatile uint32_t RESERVED4[64U];
    volatile uint32_t IP[8U];             // Interrupt Priority
} NVIC_Type;

#define NVIC    ((volatile NVIC_Type*) 0xE000E100)

typedef void (*VECTOR_FUNCTION_Type)(void);

static inline void NVIC_EnableIRQ(const uint32_t IRQ_Number, const uint32_t priority)
{
    // set Priority
    NVIC->IP[(IRQ_Number >> 2)] = ((uint32_t)(
    NVIC->IP[(IRQ_Number >> 2)] & ~(0xFFUL << (IRQ_Number & 0x03UL) * 8UL))
            | (((priority << (8U - 2)) & (uint32_t) 0xFFUL)
                    << (IRQ_Number & 0x03UL) * 8UL));
    // enable Interrupt
    __asm volatile("":::"memory");
    NVIC->ISER = (uint32_t)(1UL << (((uint32_t) IRQ_Number) & 0x1FUL));
    __asm volatile("":::"memory");
}

/**
  \brief   Disable Interrupt
  \details Disables a device specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
static inline void NVIC_DisableIRQ(const int32_t IRQn)
{
    if(IRQn >= 0)
    {
        NVIC->ICER = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
        __asm volatile ("dsb 0xF":::"memory");
        __asm volatile ("isb 0xF":::"memory");
    }
}

