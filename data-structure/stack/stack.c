#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structure stack
 * Allows operations
 */

typedef struct stack_chunk
{
    int number;
} stack_chunk_t;


typedef struct stack
{
stack_chunk_t *base;
stack_chunk_t *end;
stack_chunk_t *top;
} stack_t;

static size_t STACK_SIZE = 10;


stack_t *create_stack()
{
    stack_t *stack = (stack_t*)malloc(sizeof(stack_t));
    if(stack == NULL)
    {
        printf("Allocation memory failed stack_t !");
        return NULL;
    }
    stack->base = NULL;
    stack->top  = NULL;
    stack->end  = NULL;

    stack->base = (stack_chunk_t*)malloc(STACK_SIZE * sizeof (stack_chunk_t));
    if(stack == NULL)
    {
        printf("Allocation memory failed stack_chunk_t !");
        return NULL;
    }

    stack->end  = stack->base + STACK_SIZE;
    stack->top  = stack->base;

    printf("Create stack.\n");

    return stack;
}

int main()
{
    stack_t *stack = NULL;
    stack = create_stack();



    return 0;
}
