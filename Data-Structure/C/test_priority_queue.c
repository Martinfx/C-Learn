#include "priority_queue.h"

int main(int argc, char *argv[])
{
    priority_queue_t pq;
    priority_queue_init(&pq);
    priority_queue_push(&pq, 1, 5);
    priority_queue_push(&pq, 2, 22);
    priority_queue_push(&pq, 3, 10);
    priority_queue_print(&pq);
    printf("top: %d \n", priority_queue_top(&pq));
    priority_queue_pop(&pq);
    priority_queue_pop(&pq);
    priority_queue_pop(&pq);
    priority_queue_pop(&pq);
    return 0;
}
