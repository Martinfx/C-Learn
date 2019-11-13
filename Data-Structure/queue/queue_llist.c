#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Example for simple queue data
 * structure implemented as linked list.
 */

typedef struct llist
{
    struct llist *next;
    int key;
} node_t;

typedef struct queue
{
    node_t *first;
    node_t *last;
    int QUEUE_MAX_SIZE;
    int count;
} queue_t;

node_t *create_node()
{
    node_t *node = (node_t*)malloc(sizeof(node_t));
    if(node == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    node->next = NULL;
    node->key = 0;

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
    queue->QUEUE_MAX_SIZE = 5;
    queue->count = 0;
    return queue;
}

int lenght_queue(queue_t *queue)
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

    return lenght;
}

bool is_empty(queue_t *queue)
{
    if(queue == NULL)
    {
        printf("Queue is NULL!");
        return true;
    }

    return ((queue->first == NULL) &&
            (queue->last == NULL));
}

int count(queue_t *queue)
{
    int count = queue->count;
    return count;
}

void free_queue(queue_t *queue)
{
    if(queue->first == NULL)
    {
        // if is pointer queue->first == NULL
        // free dealocated memory
        free(queue);
    }
}

void enqueue(queue_t *queue, int x)
{
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

void dequeue(queue_t *queue)
{
    if(queue == NULL)
    {
        return;
    }

    /// Remove nodes from front
    node_t *temp = NULL;
    queue->count--;
    temp = queue->first;
    queue->first = queue->first->next;
    free(temp);

    printf("Delete node.\n");
}

int main()
{
    queue_t *queue = create_queue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("first item = %d\n", queue->first->key);
    printf("Count of nodes: %d \n", count(queue));
    //printf("Lenght of queue: %d \n", lenght_queue(queue));

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    free_queue(queue);

    return 0;
}
