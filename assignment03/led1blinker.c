
// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#if 1
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

// 0x48000000 is the  base of GPIO A which 
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

volatile int counter=0;
//int counter=0;
//this shifts a 1 to the 5th bit to set the 5th bit
#define ORD5 (1<<5)

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    RCC_AHB2ENR |= 0x1;
  
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable PA5 output
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIOA Base Address: 0x48000000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x4000; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF

    while(1)
    {
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA_ODR |= ORD5;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA_ODR &= ~ORD5;
    }
}
#endif

//The dot duration is the basic unit of time measurement in Mor
//se code transmission. The duration of a dash is three times the duration of a
//dot. Each dot or dash within a character is followed by period of signal absence, called a space, equal to the dot duration
