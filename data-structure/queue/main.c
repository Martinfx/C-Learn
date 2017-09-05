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
} d_list_t;

typedef struct queue_header
{
    struct queue_header *first;
    struct queue_header *last;
} queue_header_t;


d_list_t* create_queue(int n)
{
    d_list_t *temp = NULL;

    for(int i = 0; i < n; i++)
    {
        temp = (d_list_t)malloc(sizeof(d_list_t));
        temp->node_data = i;
    }
}

/*
void enqueue(d_list_t *item)
{

}

void dequeue()
{

}
*/
int main()
{
//    queue_header_t *queue = NULL;
}
