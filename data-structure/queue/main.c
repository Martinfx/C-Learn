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
    struct queue *first;
    struct queue *last;
    int size;
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
    head->node_data++;
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
    //temp->size  = n;
    return temp;
}

int main()
{


}
