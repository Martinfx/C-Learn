#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    uint32_t *base;
    uint32_t *top;
    uint32_t capacity;
} stack_t;

void stack_init(stack_t *s, uint32_t capacity) {
    s->base = malloc(capacity * sizeof (uint32_t));
    s->top = s->base;
    s->capacity = capacity;
}

void stack_push(stack_t *s, uint32_t val) {
    if(s->base + s->capacity == s->top) {
       printf("Stack is full\n");
    }
    else {
        *s->top = val;
        printf("Added item to stack: %d \n", *s->top);
        s->top += 1;
    }
}

uint32_t stack_pop(stack_t *s) {
    if(s->base == s->top) {
        printf("Stack is empty!\n");
        return 0;
    } else {
       s->top -= 1;
       printf("Pop this value: %d\n",*s->top);
       return *s->top;
    }
}

uint32_t stack_capacity(stack_t* s) {
    return s->capacity;
}

void stack_free(stack_t *s) {
  if (s->base) {
    free(s->base);
    s->base = NULL;
  }
}

//typedef struct stack {
//    struct stack *base;
//    struct stack *end;
//    struct stack *top;
//    uint32_t capacity;
//    uint32_t args;
//} stack_t;

//void stack_init(stack_t *s, uint32_t capacity) {
//    s->base = (stack_t *)calloc(5, capacity * sizeof(stack_t));
//    if (!s->base) {
//        exit(0);
//    }

//    s->top = NULL;
//    s->end = NULL;
//    s->capacity = capacity;
//    s->end = s->base + s->capacity;
//    s->top = s->base;
//}

//void stack_push(stack_t *s, uint32_t args) {
//    if (s->top == s->end) {
//        printf("Stack is full!");
//    } else {
//        s->top->args = args;
//        printf("Added item to stack: %u \n", s->top->args);
//        s->top += sizeof(uint32_t);
//    }
//}

//void stack_pop(stack_t *s) {
//    if (s->top == s->base) {
//        printf("Stack is empty! \n");
//    }

//    s->top -= sizeof(uint32_t);
//    printf("Pop item: %u \n", s->top->args);
//}

//void stack_free(stack_t *s) {
//    if (s->base) {
//        free(s->base);
//        s->base = NULL;
//    }
//}

