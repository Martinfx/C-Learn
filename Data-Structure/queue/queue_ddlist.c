#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Example for simple queue data
 * structure implemented as doubly linked list.
 */

typedef struct d_list
{
    int key;
    struct d_list *next;
    struct d_list *prev;
} node_t;

typedef struct queue
{
    node_t *first;
    node_t *last;
} queue_t;

node_t *create_node()
{
    node_t *head = (node_t*)malloc(sizeof(node_t));
    if(head == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    head->next = NULL;
    head->prev = NULL;
    head->key = 0;
    printf("Create node data: %d \n", head->key);
    return head;
}

queue_t* create_queue()
{
    queue_t *temp = (queue_t*)malloc(sizeof(queue_t));
    if(temp == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    temp->first = NULL;
    temp->last  = NULL;

    printf("Create struct queue.\n");
    return temp;
}

bool is_empty(queue_t *queue)
{
    return ((queue->first == NULL) && (queue->last == NULL));
}

void enqueue(queue_t *queue, int key)
{
    node_t *node = create_node();
    node->key = key;

    if(queue == NULL)
    {
        queue->first = node;
        queue->last  = node;
    }

    printf("Added node to queue \n");

    node->prev = queue->last;
    queue->first = node->next;
    queue->last = node;
}

void dequeue(queue_t *queue)
{
    if(queue == NULL)
    {
        return;
    }
    else
    {
        node_t *temp = queue->last;
        queue->last = temp->prev;
        free(temp);
    }

    if(is_empty(queue))
    {
        free(queue);
        queue = NULL;
    }
}

void print_queue(queue_t *queue)
{
    node_t *temp = NULL;
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

int main()
{
    queue_t *queue = NULL;
    queue = create_queue();

    enqueue(queue, 1);
    enqueue(queue, 2);

    //print_queue(queue);

    dequeue(queue);
    dequeue(queue);
}
