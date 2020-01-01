#include "queue.h"

int main() {
    queue__t q;
    queue_init(&q);

    for (size_t i = 0; i < 10; i++) {
        queue_enqueue(&q, rand() % 100);
    }

    for (size_t i = 0; i < 8; i++) {
        queue_dequeue(&q);
    }

    queue_dequeue(&q);
    queue_dequeue(&q);
    queue_free(&q);

    return 0;
}
