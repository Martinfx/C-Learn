#include "stack.h"

int main() {
    stack_t stack;
    stack_init(&stack, 3);
    for(int i  = 0; i < 4; i++){
        stack_push(&stack, i);
    }
    //stack_push(&stack, 24);
    //stack_push(&stack, 25);
    //stack_push(&stack, 26);
    //stack_push(&stack, 27);

    stack_pop(&stack);
    stack_pop(&stack);
    stack_pop(&stack);
    stack_pop(&stack);
    stack_pop(&stack);
    stack_pop(&stack);
    //stack_pop(&stack);

    stack_free(&stack);

    return 0;
}
