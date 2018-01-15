#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int a, int b)
{
    return (a) < (b) ? (a) : (b);
}

int max(int a, int b)
{
    return (a) > (b) ? (a) : (b);
}

typedef struct node
{
    int key;
    int height;
    struct node *left;
    struct node *right;
} tree_t;

typedef struct llist
{
    struct llist *next;
    tree_t *key;
} node_t;

typedef struct queue
{
    node_t *first;
    node_t *last;
    int QUEUE_MAX_SIZE;
} queue_t;

node_t *create_node_queue()
{
    node_t *node = (node_t*)malloc(sizeof(node_t));
    if(node == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    node->next = NULL;
    return node;
}

queue_t *create_queue()
{
    queue_t *queue = (queue_t*)malloc(sizeof(queue_t));
    if(queue == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    queue->first = NULL;
    queue->last  = NULL;
    queue->QUEUE_MAX_SIZE = 20;
    return queue;
}

void lenght_queue(queue_t *queue)
{
    node_t *temp = NULL;
    int lenght = 0;

    temp = queue->first;

    while(temp != NULL)
    {
        temp = temp->next;
        lenght++;
    }

    printf("Lenght of queue: %d \n", lenght);
}

bool is_empty_queue(queue_t *queue)
{
    if(queue == NULL)
    {
        printf("Queue is NULL!");
        return true;
    }

    return ((queue->first == NULL) &&
            (queue->last == NULL));
}

void free_queue(queue_t *queue)
{
    if(queue->first == NULL)
    {
        // if is pointer queue->first == NULL
        // free dealocated memory
        free(queue);
        queue = NULL;
    }
}

void enqueue(queue_t *queue, tree_t *key)
{
    node_t *node = create_node_queue();
    node->key = key;

    if(queue->first == NULL)
    {
        queue->first = node;
        queue->last  = node;
    }

    printf("Added node to queue.\n");

    queue->last->next = node;
    queue->last = node;
}

void dequeue(queue_t *queue)
{
    /// Remove nodes from front
    node_t *temp = NULL;
    temp = queue->first;
    queue->first = queue->first->next;
    free(temp);
    temp = NULL;

    printf("Delete node.\n");
}

#endif
