#include "stack.h"

int main() {
    /*stack_t *stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    pop(stack);
    pop(stack);
    pop(stack);
    remove_stack(stack);*/

    stack_t stack;
    stack_init(&stack, 5);
    stack_push(&stack, 20);
    stack_push(&stack, 21);
    stack_push(&stack, 22);
    stack_push(&stack, 23);
    stack_push(&stack, 24);
    //stack_push(&stack, 25);
    //stack_push(&stack, 26);
    //stack_push(&stack, 27);

    stack_pop(&stack);
    stack_pop(&stack);
    stack_pop(&stack);
    stack_pop(&stack);
    stack_pop(&stack);
    //stack_pop(&stack);

    stack_free(&stack);

    return 0;
}
