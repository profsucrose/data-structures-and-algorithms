#include "stack.h"

void stack_push(Stack *stack, Elmt *elmt) {
    list_push(stack, elmt);
}

void stack_pop(Stack *stack) {
    list_remove_tail(stack);
}

Elmt *stack_peek(Stack *stack) {
    return stack->tail;
}

void stack_clear(Stack *stack) {
    list_clear(stack);
}