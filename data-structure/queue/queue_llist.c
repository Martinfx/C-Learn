#include <stdio.h>
#include <stdlib.h>

/*
 * Example for simple queue data
 * structure implemented as linked list.
 */

typedef struct llist
{
    struct llist *next;
    int node_data;
} node_t;

typedef struct queue
{
    node_t *first;
    node_t *last;
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
    node->node_data++;
    printf("Create node data: %d \n", node->node_data);
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
    return queue;
}

void enqueue(queue_t *queue)
{
    node_t *node = create_node();

    if(queue->first == NULL)
    {
        queue->first = node;
        queue->last  = node;
    }

    queue->last->next = node;
    queue->last = node;
    printf("Added node to queue. \n");

}

void dequeue(queue_t *queue)
{
    /// Remove nodes from front
    node_t *temp = NULL;
    temp = queue->first;
    queue->first = queue->first->next;
    free(temp);

    printf("Delete node.\n");

    if(queue->first == NULL)
    {
        // if is pointer queue->first == NULL
        // free alocated memory
        free(queue);
    }
}

int main()
{
    queue_t *queue = NULL;
    queue = create_queue();

    enqueue(queue);
    enqueue(queue);
    enqueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    ///printf("first item = %d\n", queue->first->node_data );
    ///printf("last item = %d\n\n", queue->last->node_data );

    return 0;
}
