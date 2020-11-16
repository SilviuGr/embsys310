
// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class
void characterMorse(char cr);
void morseDash(void);
void morseDot(void);

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

void morseDot(void)
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
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
             
}

void morseDash(void)
{
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA_ODR |= ORD5;
            
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }

        GPIOA_ODR &= ~ORD5; 
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
         
}


void characterMorse(char lop)
{
  char cr = lop;
  
  if( (cr == 'a')||(cr == 'A'))
  {
    morseDot();
    morseDash();
  }else if ((cr == 'b')||(cr == 'B'))
  {
    morseDash();
    morseDot();
    morseDot();
    morseDot();
  }else if ((cr == 'c')||(cr == 'C'))
  {
    morseDash();
    morseDot();
    morseDash();
    morseDot();
  }else if ((cr == 'd')||(cr == 'D'))
  {
    morseDash();
    morseDot();
    morseDot();
  }else if ((cr == 'e')||(cr == 'E'))
  {
    morseDot();
  }else if ((cr == 'f')||(cr == 'F'))
  {
    morseDot();
    morseDot();
    morseDash();
    morseDot();
  }else if ((cr == 'g')||(cr == 'G'))
  {
    morseDash();
    morseDash();
    morseDot();
  }else if((cr == 'h')||(cr == 'H'))
  {
    morseDot();
    morseDot();
    morseDot();
    morseDot();
  }else if ((cr == 'i')||(cr == 'I'))
  {
    morseDot();
    morseDot();
  }else if ((cr == 'j')||(cr == 'J'))
  {
    morseDot();
    morseDash();
    morseDash();
    morseDash();
  }else if ((cr == 'k')||(cr == 'K'))
  {
    morseDash();
    morseDot();
    morseDash();
  }else if ((cr == 'l')||(cr == 'L'))
  {
    morseDot();
    morseDash();
    morseDot();
    morseDot();
  }else if ((cr == 'm')||(cr == 'M'))
  {
    morseDash();
    morseDash();
  }else if ((cr == 'n')||(cr == 'N'))
  {
    morseDash();
    morseDot();
  }else if ((cr == 'o')||(cr == 'O'))
  {
    morseDash();
    morseDash();
    morseDash();
  }else if ((cr == 'p')||(cr == 'P'))
  {
    morseDot();
    morseDash();
    morseDash();
    morseDot();
  }else if ((cr == 'q')||(cr == 'Q'))
  {
    morseDash();
    morseDash();
    morseDot();
    morseDash();
  }else if ((cr == 'r')||(cr == 'R'))
  {
    morseDot();
    morseDash();
    morseDot();
  }else if ((cr == 's')||(cr == 'S'))
  {
    morseDot();
    morseDot();
    morseDot();
  }else if ((cr == 't')||(cr == 'T'))
  {
    morseDash();
  }else if ((cr == 'u')||(cr == 'U'))
  {
    morseDot();
    morseDot();
    morseDash();
  }else if ((cr == 'v')||(cr == 'V'))
  {
    morseDot();
    morseDot();
    morseDot();
    morseDash();
  }else if ((cr == 'w')||(cr == 'W'))
  {
    morseDot();
    morseDash();
    morseDash();
  }else if( (cr == 'x')||(cr == 'X'))
  {
    morseDash();
    morseDot();
    morseDot();
    morseDash();
  }else if ((cr == 'y')||(cr == 'Y'))
  {
    morseDash();
    morseDot();
    morseDash();
    morseDash();
  }else if((cr == 'z')||(cr == 'Z'))
  {
    morseDash();
    morseDash();
    morseDot();
    morseDot();
    }
}      
      
      
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

    characterMorse('S');
    characterMorse('i');
    characterMorse('l');
    characterMorse('v');
    characterMorse('i');
    characterMorse('u');
}
#endif

//The dot duration is the basic unit of time measurement in Mor
//se code transmission. The duration of a dash is three times the duration of a
//dot. Each dot or dash within a character is followed by period of signal absence, called a space, equal to the dot duration


