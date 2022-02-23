#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
  int32_t val;
  struct node *next;
  struct node *prev;
} node_t;

typedef struct deque {
  node_t *head;
  node_t *tail;
} deque_t;

node_t *create_deque_node() {
  node_t *node = (node_t *)malloc(sizeof(node_t));

  if (!node) {
    printf("Allocation memory failed!");
    exit(0);
  }

  node->next = NULL;
  node->prev = NULL;
  node->val = 0;
  //printf("Create node data: %d \n", node->val);
  return node;
}

deque_t *create_deque() {
  deque_t *temp = (deque_t *)malloc(sizeof(deque_t));
  if (!temp) {
    printf("Allocation memory failed!");
    exit(0);
  }

  temp->head = temp->tail = NULL;

  printf("Create struct queue.\n");
  return temp;
}

bool is_empty_deque(deque_t *deque) {
  return ((deque->head == NULL) && (deque->tail == NULL));
}

void push_front(deque_t *d, int32_t v) {
    node_t *n = create_deque_node();
    assert(n != NULL);
    n->val = v;
    n->next = d->head;
    n->prev = NULL;
    if (d->tail == NULL) {
        d->head = d->tail = n;
        printf("Push front: %d \n", n->val);
    } else {
        d->head->prev = n;
        d->head = n;
        printf("Push front: %d \n", n->val);
    }
}

void push_back(deque_t *d, int32_t v) {
    node_t *n = create_deque_node();
    assert(n != NULL);
    n->val = v;
    n->prev = d->tail;
    n->next = NULL;
    if (d->head == NULL) {
        d->head = d->tail = n;
        printf("Push back: %d \n", n->val);
    } else {
        d->tail->next = n;
        d->tail = n;
        printf("Push back: %d \n", n->val);
    }
}

int32_t pop_front(deque_t *d) {
    int32_t v = d->head->val;
    node_t *n = d->head;
    if (d->head == d->tail)
        d->head = d->tail = NULL;
    else
        d->head = n->next;
    free(n);
    return v;
}

int32_t pop_back(deque_t *d) {
    int32_t v = d->tail->val;
    node_t *n = d->tail;
    if (d->head == d->tail)
        d->head = d->tail = NULL;
    else
        d->tail = n->prev;
    free(n);
    return v;
}


void print_forward_deque(deque_t *d)
{
    deque_t *temp = d;

    if(temp == NULL)
    {
        printf("List is empty!\n");
    }

    printf("------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("Forward list item: "
               "current is %p; "
               "next is %p; "
               "prev is %p; "
               "key is %d\n",
               (void*)temp,
               (void*)temp->head,
               (void*)temp->tail,
               temp->head->val);

        temp = temp->head;
    }
}


/*void print_deque(deque_t *queue) {
  node_t *temp = NULL;
  temp = queue->tail;

  if ((queue->head == NULL) && (queue->tail == NULL)) {
    printf("Queue is empty! \n");
    return;
  }

  while (temp->next != NULL) {
    printf("%d \n", temp->val);
    temp = temp->next;
  }
}*/
