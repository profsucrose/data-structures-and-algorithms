#ifndef stack_h
#define stack_h

#include "list.h"

// a stack is just a linked-list wrapper

typedef List Stack;

void stack_push(Stack *stack, Elmt *elmt);
void stack_pop(Stack *stack);
Elmt *stack_peek(Stack *stack);
void stack_clear(Stack *stack);

#endif