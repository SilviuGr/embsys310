#include "stack.h"
#define STACK_SIZE 4

// Backing store
int StackStore[STACK_SIZE];

// Pointers to  stack elements for adding and retrieving
int* stackPtr;

// LIFO Stack is Empty if pushPtr = popPtr
// LIFO Stack is Full if pushPtr+1 > Address of last element in the stack

// Initialize internals of the Stack
void stack_init(void)
{
    stackPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = 9;
    }
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int stack_push(int data)
{
    if (stackPtr == &StackStore[STACK_SIZE-1])
    {
        // stack is full return failure
        return 1;
    }
    
    if (stackPtr == 0 )
    {
      stackPtr = StackStore;
    }
    else
    {
        stackPtr++;
    }
    
    *stackPtr = data;
    // return success
    return 0;
}

// Get data from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* data)
{   
    if (stackPtr == 0)
    {
        // stack is empty
        return 1;
    }
    
    *data = *stackPtr;
    if (stackPtr = StackStore)
    {
      stackPtr = 0;
    }
    else
    {
      stackPtr--;
    }
    return 0;
}
