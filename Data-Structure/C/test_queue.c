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

QUEUE_DEFINE(int);
void test_generic_queue() {
  int_queue_t queue;
  int_queue_init(&queue);

  for (size_t i = 0; i < 100; i++) {
    int_queue_enqueue(&queue, arc4random() % 100);
  }

  printf("capacity: %d \n", int_queue_capacity(&queue));
  printf("size: %d \n", int_queue_size(&queue));

  for (size_t i = 0; i < 120; i++) {
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
