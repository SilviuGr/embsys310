void swap(char* x, char* y);

void swap(char* x, char* y)
{

 /* if(*x == *y){
    return 0;
  }
  else{
char temp = *x;
*x = *y;
*y = temp;
return 1;
}*/
  

asm("LDR R2, [R1] \n" // load value  char x into R2
    "LDR R3, [R0] \n" // load value char y into R3
    "CMP R3, R2 \n"// compare the two values
    "BNE p1 \n" // if above compare is  notequal goes to step p1

    "MOVS R0,#0 \n"
    "BX LR \n"

    "p1: \n"
    "STR R2,[R0} \n"
    "STR R3,[R1] \n"
    "MOVS R0,#1 \n"
    "BX LR \n");
/*asm("st      -Y,  R20\n  \n"
    "spmloop:            \n"
    "lN      R20, 0x37   \n"
    "SBRC    R20, 0      \n"
    "RJMP    spmloop     \n"
    "OUT     0x37,R25    \n"
    "SPM                 \n"
    "LD      R20,Y+      \n");
*/
}

void main(void)
{
char x = 'a';
char y = 'b';
swap(&x, &y);
}


//swapCharsAsm(&c, &d); 

