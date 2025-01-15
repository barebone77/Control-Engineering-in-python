#include "stm32f10x.h"

void ADC_Config(void);
uint16_t Read_ADC(void);
void Delay_ms(uint32_t ms);
void LED_Config(void);

int main(void) {
    // Configure ADC and LED
    ADC_Config();
    LED_Config();
    
    uint16_t adc_value;
    float temperature;

    while (1) {
        // Read ADC value from PA0
        adc_value = Read_ADC();
        
        // Convert ADC value to temperature
        // Assuming Vref = 3.3V and 12-bit ADC
        temperature = ((adc_value * 3.3) / 4095.0) / 0.01;
        
        // Check if temperature exceeds 15°C
        if (temperature > 15.0) {
            // Turn ON the LED (active low)
            GPIOC->ODR &= ~GPIO_ODR_ODR13;
        } else {
            // Turn OFF the LED
            GPIOC->ODR |= GPIO_ODR_ODR13;
        }
        
        // Add a delay for stability
        Delay_ms(100);
    }
}

void ADC_Config(void) {
    // Enable clock for GPIOA and ADC1
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_ADC1EN;
    
    // Configure PA0 as analog input
    GPIOA->CRL &= ~GPIO_CRL_MODE0;
    GPIOA->CRL &= ~GPIO_CRL_CNF0;
    
    // Configure ADC1
    ADC1->CR2 |= ADC_CR2_ADON;        // Enable ADC
    ADC1->SMPR2 |= ADC_SMPR2_SMP0;   // Set sampling time for channel 0
    ADC1->SQR1 &= ~ADC_SQR1_L;       // Single conversion
    ADC1->SQR3 |= 0;                 // Channel 0 in the sequence
}

uint16_t Read_ADC(void) {
    ADC1->CR2 |= ADC_CR2_ADON;       // Start ADC conversion
    while (!(ADC1->SR & ADC_SR_EOC)); // Wait for conversion to complete
    return ADC1->DR;                 // Return ADC value
}

void LED_Config(void) {
    // Enable clock for GPIOC
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    
    // Configure PC13 as output push-pull
    GPIOC->CRH &= ~GPIO_CRH_MODE13;  // Clear MODE bits
    GPIOC->CRH &= ~GPIO_CRH_CNF13;  // Clear CNF bits
    GPIOC->CRH |= GPIO_CRH_MODE13_0; // Output mode, max 10 MHz
    GPIOC->ODR |= GPIO_ODR_ODR13;    // Ensure LED is initially OFF (active low)
}

void Delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 8000; i++) {
        __NOP(); // No operation (just waste time)
    }
}
