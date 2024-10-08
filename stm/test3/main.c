#include "stm32f1xx.h"

void delay(volatile uint32_t s);

int main(void) {
    // Habilita o clock para o GPIOC
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    // Configura o PC13 como saída
    GPIOC->CRH &= ~GPIO_CRH_MODE13;
    GPIOC->CRH |= GPIO_CRH_MODE13_0;

    while (1) {
        GPIOC->ODR ^= GPIO_ODR_ODR13;  // Alterna o LED
        delay(1000000);                // Espera
    }
}

void delay(volatile uint32_t s) {
    while (s--) {}
}
