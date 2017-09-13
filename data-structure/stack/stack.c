#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Allocation memory failed for stack_t !");
        return NULL;
    }
    stack->base = NULL;
    stack->top  = NULL;
    stack->end  = NULL;

    stack->base = (stack_chunk_t*)malloc(STACK_SIZE * sizeof (stack_chunk_t));
    if(stack == NULL)
    {
        printf("Allocation memory failed for stack_chunk_t !");
        return NULL;
    }

    stack->end  = stack->base + STACK_SIZE;
    stack->top  = stack->base;

    printf("Create stack.\n");

    return stack;
}
/*
void remove_stack(stack_t *stack)
{

}*/

void push(stack_t *stack)
{
    if(stack->top == stack->end)
    {
        printf("Stack is empty!");
    }
    else
    {
        memcpy(stack->top, stack, sizeof(stack_t));
        stack->top = stack->top + 1;
        stack->top->number++;
        printf("Added item to stack: %d \n", stack->top->number);
    }
}
/*
int pop(stack_t *stack)
{

}*/

int main()
{
    stack_t *stack = NULL;
    stack = create_stack();
    push(stack);

    return 0;
}
