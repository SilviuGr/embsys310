void swap(int** x, int** y);

void swap(int** x, int** y)
{
    int* temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int x = 100000;
    int y = 50000;
    //pointer to a pointer
    int* a = &x;
    int* b = &y;
    while(1)
    {
        swap(&a, &b);
    }
}