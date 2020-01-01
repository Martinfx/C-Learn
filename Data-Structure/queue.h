#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Example for simple queue data
 * structure implemented as linked list.
 */

typedef struct llist {
    struct llist *next;
    int key;
} node_t;

typedef struct queue {
    node_t *first;
    node_t *last;
    int count;
    int size;
} queue_t;

node_t *create_node() {
    node_t *node = (node_t*)calloc(2, sizeof(node_t));
    if(!node) {
        printf("Allocation memory failed!");
        return NULL;
    }
    return node;
}

queue_t *create_queue() {
    queue_t *queue = (queue_t*)malloc(sizeof(queue_t));
    if(!queue) {
        printf("Allocation memory failed!");
        return NULL;
    }

    queue->first = NULL;
    queue->last  = NULL;
    queue->size = 20;
    queue->count = 0;
    return queue;
}

int lenght_queue(queue_t *queue) {
    node_t *temp = NULL;
    int lenght = 0;
    temp = queue->first;
    while(temp != NULL) {
        temp = temp->next;
        lenght++;
    }

    printf("Lenght of queue: %d \n", lenght);
    return lenght;
}

bool is_empty(queue_t *queue) {
    if(queue == NULL) {
        printf("Queue is NULL!");
        return true;
    }

    return ((queue->first == NULL) &&
            (queue->last == NULL));
}

int count(queue_t *queue) {
    int count = queue->count;
    return count;
}

void free_queue(queue_t *queue) {
    if(queue->first == NULL) {
        // if is pointer queue->first == NULL
        // free dealocated memory
        free(queue);
    }
}

void enqueue(queue_t *queue, int x) {
    node_t *node = create_node();

    if(queue->first == NULL)
    {
        queue->first = node;
        queue->last  = node;
    }

    node->key = x;

    printf("Added node to queue\n");

    queue->last->next = node;
    queue->last = node;
    queue->count++;
}

void dequeue(queue_t *queue) {
    node_t *temp = NULL;
    queue->count--;
    temp = queue->first;
    queue->first = queue->first->next;
    free(temp);

    printf("Delete node.\n");
}

/*
 * Simple implementation queue
 * as doubly linked list
 */

typedef struct d_list {
    int key;
    struct d_list *next;
    struct d_list *prev;
} node_dlist_t;

typedef struct queue_dlist {
    node_dlist_t *first;
    node_dlist_t *last;
} queue_dlist_t;

node_dlist_t *create_dnode() {
    node_dlist_t *head = (node_dlist_t*)malloc(
                sizeof(node_dlist_t));

    if(!head) {
        printf("Allocation memory failed!");
        exit(0);
    }

    head->next = NULL;
    head->prev = NULL;
    head->key = 0;
    printf("Create node data: %d \n", head->key);
    return head;
}

queue_dlist_t* create_dqueue() {
    queue_dlist_t *temp = (queue_dlist_t*)
            malloc(sizeof(queue_dlist_t));
    if(!temp) {
        printf("Allocation memory failed!");
        exit(0);
    }

    temp->first = NULL;
    temp->last  = NULL;

    printf("Create struct queue.\n");
    return temp;
}

bool is_empty_dlist(queue_dlist_t *queue) {
    return ((queue->first == NULL) && (queue->last == NULL));
}

void enqueue_dlist(queue_dlist_t *queue, int key) {
    node_dlist_t *node = create_dnode();
    node->key = key;

    if(queue == NULL) {
        queue->first = node;
        queue->last  = node;
    }

    printf("Added node to queue \n");

    node->prev = queue->last;
    queue->first = node->next;
    queue->last = node;
}

void dequeue_dlist(queue_dlist_t *queue) {
    if(queue == NULL)
    {
        return;
    }
    else
    {
        node_dlist_t *temp = queue->last;
        queue->last = temp->prev;
        free(temp);
    }

    if(is_empty_dlist(queue))
    {
        free(queue);
        queue = NULL;
    }
}

void print_dqueue(queue_dlist_t *queue) {
    node_dlist_t *temp = NULL;
    temp = queue->last;

    if((queue->first == NULL) && (queue->last == NULL))
    {
        printf("Queue is empty! \n");
        return;
    }

    while(temp->next != NULL)
    {
        printf("%d \n", temp->key);
        temp = temp->next;
    }
}