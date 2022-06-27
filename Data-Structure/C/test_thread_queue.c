#include <threads.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define QUEUE_INTERNAL_LIST(T)                                                 \
  typedef struct T##list {                                                     \
    struct T##list *next;                                                      \
    T key;                                                             \
  } T##_chunk_t;

#define QUEUE_GENERIC(T)                                                       \
  typedef struct T##queue_generic {                                            \
    T##_chunk_t *first;                                                        \
    T##_chunk_t *tail;                                                         \
    uint32_t capacity;                                                 \
    uint32_t size;                                                     \
    T *arr;                                                                    \
    mtx_t mutex_lock;                                                          \
  } T##_queue_t;

#define QUEUE_INIT(T)                                                          \
  void T##_queue_init(T##_queue_t *queue) {                                    \
    queue->arr = (T *)malloc(sizeof(T));                                       \
    if (!queue) {                                                              \
      exit(0);                                                                 \
    }                                                                          \
                                                                               \
    queue->size = 0;                                                           \
    queue->capacity = 32;                                                      \
    queue->first = NULL;                                                       \
    queue->tail = NULL;                                                        \
    printf("debug: queue->size: %u, queue->capacity: %u \n", queue->size,      \
           queue->capacity);                                                   \
  }

#define QUEUE_ENQUEUE(T)                                                       \
  void T##_queue_enqueue(T##_queue_t *queue, T key) {                          \
    if (queue->size == queue->capacity) {                                      \
      printf("debug: queue->size: %u, queue->capacity: %u \n", queue->size,    \
             queue->capacity);                                                 \
      printf("Please wait,  queue is full.\n");                                \
    } else {                                                                   \
         T##_chunk_t *chunk = malloc(sizeof(T##_chunk_t));                     \
      if (!queue->first) {                                                     \
        queue->first = chunk;                                                  \
        queue->tail = chunk;                                                   \
        chunk->key = key;                                                      \
      } else {                                                                 \
        chunk->key = key;                                                      \
        queue->tail->next = chunk;                                             \
        queue->tail = chunk;                                                   \
        queue->size += 1;                                                      \
        printf("debug: enqueue chunk->key: %u, queue->size %u \n", chunk->key, \
               queue->size);                                                   \
      }                                                                        \
    }                                                                          \
  }

#define QUEUE_DEQUEUE(T)                                                       \
  void T##_queue_dequeue(T##_queue_t *queue) {                                 \
    if (queue->size > 0) {                                                     \
      queue->size -= 1;                                                        \
      T##_chunk_t *chunk = queue->first;                                       \
      queue->first = queue->first->next;                                       \
      printf("debug: denqueue chunk->key: %u, queue->size: %u \n", chunk->key, \
             queue->size);                                                     \
      free(chunk);                                                             \
    }                                                                          \
  }

#define QUEUE_CAPACITY(T)                                                      \
  uint32_t T##_queue_capacity(T##_queue_t *queue) { return queue->capacity; }

#define QUEUE_SIZE(T)                                                          \
  uint32_t T##_queue_size(T##_queue_t *queue) { return queue->size; }

#define QUEUE_FREE(T)                                                          \
  void T##_queue_free(T##_queue_t *queue) {                                    \
    if (queue->first) {                                                        \
      free(queue->arr);                                                        \
      queue->arr = NULL;                                                       \
    }                                                                          \
  }

#define QUEUE_ENTRY(T)                                                         \
  QUEUE_INTERNAL_LIST(T);                                                      \
  QUEUE_GENERIC(T);                                                            \
  QUEUE_INIT(T);                                                               \
  QUEUE_ENQUEUE(T);                                                            \
  QUEUE_DEQUEUE(T);                                                            \
  QUEUE_CAPACITY(T);                                                           \
  QUEUE_SIZE(T);                                                               \
  QUEUE_FREE(T);

QUEUE_ENTRY(int);
static int_queue_t queue;

void writer(void *arg)
{
    while (true){
        mtx_lock(&queue.mutex_lock);
        int_queue_enqueue(&queue, 10);
        mtx_unlock(&queue.mutex_lock);
        printf("writer\n");

    }
}
void reader(void *arg)
{
    while (true){
        mtx_lock(&queue.mutex_lock);
        int_queue_dequeue(&queue);
        mtx_unlock(&queue.mutex_lock);
        printf("reader\n");
    }
}

void test_thread_generic_queue() {
    int_queue_init(&queue);

    const int PROD_NUM_THREADS = 2;
    const int CONS_NUM_THREADS = 4;

    thrd_t producer_threads[PROD_NUM_THREADS];
    thrd_t consumer_threads[CONS_NUM_THREADS];


    for (uint32_t i = 0; i < PROD_NUM_THREADS; i++) {
        if (thrd_create(&producer_threads[i], (thrd_start_t)writer, (void*)(long)i) != thrd_success) {
            printf("Thread error : %u", i);
        }
    }


    for (uint32_t i = 0; i < CONS_NUM_THREADS; i++) {
        if (thrd_create(&consumer_threads[i], (thrd_start_t)reader, (void*)(long)i) != thrd_success) {
            printf("Thread error : %u", i);
        }
    }


    int result = 0;
    for (uint32_t i = 0; i < PROD_NUM_THREADS; i++) {
        if(thrd_join(producer_threads[i], &result) == thrd_error) {
            printf("Thread error : %d", result);
        }
    }

    int result1 = 0;
    for (uint32_t i = 0; i < CONS_NUM_THREADS; i++) {
        if(thrd_join(consumer_threads[i], &result1) == thrd_error) {
            printf("Thread error : %d", result);
        }
    }

    int_queue_free(&queue);
    mtx_destroy(&queue.mutex_lock);
}

int main(void) {
    test_thread_generic_queue();
    return 0;
}
