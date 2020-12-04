
/* a. The following is the list of requirements:
i. The stack should have a predefined size
ii. The stack supports “int” data types.
iii. Provide a function to initialize the stack internals.
iv. Provide a function to push an element onto the stack
v. Provide a function to pop an element off the stack.
vi. Provide a function that returns 1 if stack is empty.
vii. Provide a function that returns 1 if stack is full.
b. Provide a list of the test cases and their implementation inside of main.c
c. Separate the stack code from the rest of the test code (create stack.h & stack.c)
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STACK_H__
#define __STACK_H__

void stack_init(void);
int stack_push(int data);
int stack_pop(int* data);

#endif
