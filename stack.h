#ifndef STACK
#define STACK
#include "node.h"

typedef struct Stack {
    node *top;
} stack;

void stack_push(stack*, void*);
void* stack_pop(stack*);
void* stack_peak(stack*);
int stack_isEmpty(stack*);

#endif