#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Example for data structure stack
 * Allows operations create_stack(), remove_stack(), push(), pop()
 */

typedef struct stack_chunk
{
    size_t number;
} stack_chunk_t;

typedef struct stack
{
    stack_chunk_t *base;
    stack_chunk_t *end;
    stack_chunk_t *top;
} stack_t;

static size_t STACK_MAX_SIZE = 5;

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

    stack->base = (stack_chunk_t*)malloc(STACK_MAX_SIZE * sizeof (stack_chunk_t));
    if(stack == NULL)
    {
        printf("Allocation memory failed for stack_chunk_t !");
        return NULL;
    }

    stack->end  = stack->base + STACK_MAX_SIZE;
    stack->top  = stack->base;

    printf("Create stack.\n");

    return stack;
}

void remove_stack(stack_t *stack)
{
    if(stack->base != NULL)
    {
        free(stack->base);
    }

    if(stack != NULL)
    {
        free(stack);
    }
}

void push(stack_t *stack, size_t data)
{
    if(stack->top == stack->end)
    {
        printf("Stack is full!");
    }
    else
    {
        stack->top->number = data;
        printf("Added item to stack: %zu \n", stack->top->number);
        stack->top = stack->top + 1;
    }
}

void pop(stack_t *stack)
{
    if(stack->top == stack->base)
    {
        printf("Pop Stack is empty!");
    }
    else
    {
        stack->top = stack->top - 1;
    }
}

int main()
{
    stack_t *stack = NULL;
    stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    //pop(stack);
    //pop(stack);

    remove_stack(stack);

    return 0;
}
