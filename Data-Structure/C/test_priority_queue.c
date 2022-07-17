#include "priority_queue.h"

int main(int argc, char *argv[])
{
    priority_queue_t pq;
    init_priority_queue(&pq);
    push_priority_queue(&pq, 1, 5);
    push_priority_queue(&pq, 1, 6);
    push_priority_queue(&pq, 1, 10);
    print(&pq);
    pop_priority_queue(&pq);
    pop_priority_queue(&pq);
    pop_priority_queue(&pq);
    pop_priority_queue(&pq);
    return 0;
}
