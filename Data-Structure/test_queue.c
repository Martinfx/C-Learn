#include "queue.h"

void test_queue_list() {
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
}

void test_queue_dlist() {

}

int main() {
    test_queue_list();
    test_queue_dlist();
    return 0;
}
