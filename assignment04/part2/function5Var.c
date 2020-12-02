
void func1(int a, int b, int c, int d, int e);
void func2(void);


#if 1


void func2(void)
{
        func1(1,2,3,4,5);            
}

void func1(int a, int b, int c, int d, int e)
{
  int l = a + b + c + d + e;
}



      
void main(void)
{
    func2();
}
#endif