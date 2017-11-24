#include <stdio.h>
#include <stdlib.h>

/*
 * Example for simple queue data
 * structure implemented as doubly linked list.
 */

typedef struct d_list
{
    int node_data;
    struct d_list *next;
    struct d_list *prev;
} node_t;

typedef struct queue
{
    node_t *first;
    node_t *last;
} queue_t;

node_t *create_node(int n)
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
    printf("Create node data: %d \n", head->node_data);
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

void enqueue(queue_t *queue, int n)
{
    node_t *node = create_node(n);
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
    node_t *temp = NULL;
    temp = queue->first;
    if((queue->first == NULL) && (queue->last == NULL))
    {
        printf("Queue is empty!");
        temp = NULL;
        return;
    }

    else
    {
        queue->first = queue->first->next;
        queue->first->prev = NULL;
    }

    free(temp);

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
        printf("%d \n", temp->node_data);
        temp = temp->next;
    }
}

int main()
{
    queue_t *q = NULL;
    q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    //enqueue(q, 3);

    dequeue(q);
    //dequeue(q);
    //dequeue(q);

    //print_queue(q);
}
