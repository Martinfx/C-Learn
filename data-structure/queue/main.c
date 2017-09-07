#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structure queue.
 * Allows operations
 */

typedef struct d_list
{
    size_t node_data;
    struct d_list *next;
    struct d_list *prev;
} node_t;

typedef struct queue
{
    node_t *first;
    node_t *last;
    int size;
} queue_t;

node_t *create_node(n)
{
    node_t *head = (node_t*)malloc(sizeof(node_t));
    if(head == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    head->next = NULL;
    head->prev = NULL;
    head->node_data = n;
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
    temp->size++;
    return temp;
}

void enqueue(queue_t *queue, int n)
{
    node_t *node = create_node(n);
    if(queue == NULL)
    {
        queue->first = node;
        queue->last  = node;
    }

    queue->last->next = node;
    queue->last->prev = queue->last->next;
    queue->last = node;
}

int main()
{
    queue_t *q = NULL;
    q = create_queue();

    enqueue(q, 1);
}
