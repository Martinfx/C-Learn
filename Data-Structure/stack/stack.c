#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Example for data structure stack
 * Allows operations create_stack(), remove_stack(), push(), pop()
 */

typedef struct stack
{
    size_t number;
    struct stack *base;
    struct stack *end;
    struct stack *top;
    size_t STACK_MAX_SIZE;
} stack_t;

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
    stack->STACK_MAX_SIZE = 10;

    stack->base = (stack_t*)malloc(stack->STACK_MAX_SIZE * sizeof(stack_t));
    if(stack == NULL)
    {
        printf("Allocation memory failed for stack_chunk_t !");
        return NULL;
    }

    stack->end  = stack->base + stack->STACK_MAX_SIZE;
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
        printf("Pop Stack is empty! \n");
        return;
    }

    stack->top = stack->top - 1;
    printf("Pop item: %zu \n", stack->top->number);
}

void pop_items(stack_t *stack)
{
    stack_t *temp = NULL;
    temp = stack->top;

    while(temp != NULL)
    {
        if(stack->top == stack->base)
        {
            break;
        }

        pop(stack);
    }
}

int main()
{
    stack_t *stack = NULL;
    stack = create_stack();
    push(stack, 10);
    push(stack, 20);

    pop(stack);
    pop(stack);
    pop(stack);

    remove_stack(stack);

    return 0;
}
