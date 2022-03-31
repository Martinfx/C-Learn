#include "queue.h"

void test_queue() {
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
}

QUEUE_ENTRY(int);
void test_generic_queue() {
  int_queue_t queue;
  int_queue_init(&queue);

  for (size_t i = 0; i < 33; i++) {
    int_queue_enqueue(&queue, rand() % 100);
  }

  for (size_t i = 0; i < 344; i++) {
    int_queue_dequeue(&queue);
  }

  int_queue_free(&queue);
}

void test_priority_queue() {
}

int main() {
  // test_queue();
  test_generic_queue();
  // test_priority_queue();

  return 0;
}
