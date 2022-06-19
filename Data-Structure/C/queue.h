#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_INTERNAL_LIST(T)                                                 \
  typedef struct T##list {                                                     \
    struct T##list *next;                                                      \
    T key;                                                                     \
  } T##_chunk_t;

#define QUEUE_GENERIC(T)                                                       \
  typedef struct T##queue_generic {                                            \
    T##_chunk_t *first;                                                        \
    T##_chunk_t *tail;                                                         \
    uint32_t capacity;                                                         \
    uint32_t size;                                                             \
    T *arr;                                                                    \
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
      T##_chunk_t *chunk = malloc(sizeof(T##_chunk_t));                        \
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

typedef struct list {
  struct list *next;
  uint32_t key;
} chunk_t;

typedef struct queue {
  chunk_t *first;
  chunk_t *tail;
  uint32_t capacity;
  uint32_t size;
  uint32_t *q;
} queue__t;

void queue_init(queue__t *queue) {
  queue->q = (uint32_t*)calloc(1, sizeof(uint32_t));
  if (!queue) {
    exit(0);
  }

  queue->size = 0;
  queue->capacity = 32;
  queue->first = NULL;
  queue->tail = NULL;
  printf("debug: queue->size: %u, queue->capacity: %u \n", queue->size,
         queue->capacity);
}

void queue_enqueue(queue__t *queue, uint32_t key) {
  if (queue->size == queue->capacity) {
    printf("debug: queue->size: %u, queue->capacity: %u \n", queue->size,
           queue->capacity);
    printf("Please wait,  queue is full.\n");
  } else {
    chunk_t *chunk = calloc(2, sizeof(chunk_t));
    if (!queue->first) {
      queue->first = chunk;
      queue->tail = chunk;
      chunk->key = key;
      printf("debug: chunk->key: %u \n", chunk->key);
    } else {
      chunk->key = key;
      queue->tail->next = chunk;
      queue->tail = chunk;
      queue->size += 1;
    }
    printf("debug: next chunk->key: %u, queue->size %u \n", chunk->key,
           queue->size);
  }
}

void queue_dequeue(queue__t *queue) {
  if (queue->size >= 0) {
    queue->size -= 1;
    printf("debug: queue->size: %u \n", queue->size);
    chunk_t *chunk = queue->first;
    queue->first = queue->first->next;
    printf("debug: remove chunk->key: %u \n", chunk->key);
    free(chunk);
  }
}

uint32_t queue_capacity(queue__t *queue) {
    return queue->capacity;
}

uint32_t queue_size(queue__t *queue) {
    return queue->size;
}

void queue_free(queue__t *queue) {
  if (queue->first) {
    free(queue->q);
    queue->q = NULL;
  }
}

//
// Implementation doubly linked queue
//
typedef struct dllist {
    uint32_t key;
    struct dllist *next;
    struct dllist *prev;
} dllchunk_t;

typedef struct dlqueue {
    uint32_t size;
    uint32_t capacity;
    dllchunk_t *first;
    dllchunk_t *last;
    uint32_t *dlqueue;
} dllqueue_t;

void dllqueue_init(dllqueue_t *queue__, uint32_t capacity) {
    queue__->dlqueue = (uint32_t*)malloc(sizeof(uint32_t));
    if(!queue__) { exit(0); }

    queue__->size = 0;
    queue__->capacity = capacity;
    queue__->first = NULL;
    queue__->last  = NULL;
}

void dllqueue_enqueue(dllqueue_t *queue__, uint32_t key){
    dllchunk_t *chunk = calloc(3, sizeof(dllchunk_t));
    chunk->key = key;

    if(!queue__){
        queue__->first = NULL;
        queue__->last  = NULL;
    }

    chunk->prev = queue__->last;
    queue__->first = chunk->next;
    queue__->last = chunk;
}


/*typedef struct llist {
  struct llist *next;
  int key;
} node_t;

typedef struct struc_queue {
  node_t *first;
  node_t *last;
  int count;
  int size;
} queue_t;

node_t *create_node() {
  node_t *node = (node_t *)calloc(2, sizeof(node_t));
  if (!node) {
    printf("Allocation memory failed!");
    return NULL;
  }
  return node;
}

queue_t *create_queue() {
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  if (!queue) {
    printf("Allocation memory failed!");
    return NULL;
  }

  queue->first = NULL;
  queue->last = NULL;
  queue->size = 20;
  queue->count = 0;
  return queue;
}

int lenght_queue(queue_t *queue) {
  node_t *temp = NULL;
  int lenght = 0;
  temp = queue->first;
  while (temp != NULL) {
    temp = temp->next;
    lenght++;
  }

  printf("Lenght of queue: %d \n", lenght);
  return lenght;
}

bool is_empty(queue_t *queue) {
  if (queue == NULL) {
    printf("Queue is NULL!");
    return true;
  }

  return ((queue->first == NULL) && (queue->last == NULL));
}

int count(queue_t *queue) {
  int count = queue->count;
  return count;
}

void free_queue(queue_t *queue) {
  if (queue->first == NULL) {
    free(queue);
  }
}

void enqueue(queue_t *queue, int x) {
  node_t *node = create_node();

  if (queue->first == NULL) {
    queue->first = node;
    queue->last = node;
  }

  node->key = x;

  printf("Added node to queue\n");

  queue->last->next = node;
  queue->last = node;
  queue->count++;
}

void dequeue(queue_t *queue) {
  node_t *temp = NULL;
  queue->count--;
  temp = queue->first;
  queue->first = queue->first->next;
  free(temp);

  printf("Delete node.\n");
}

typedef struct d_list {
  int key;
  struct d_list *next;
  struct d_list *prev;
} dnode_t;

typedef struct queue_dlist {
  dnode_t *first;
  dnode_t *last;
} queue_dlist_t;

dnode_t *create_dnode() {
  dnode_t *head = (dnode_t *)malloc(sizeof(dnode_t));

  if (!head) {
    printf("Allocation memory failed!");
    exit(0);
  }

  head->next = NULL;
  head->prev = NULL;
  head->key = 0;
  printf("Create node data: %d \n", head->key);
  return head;
}

queue_dlist_t *create_dqueue() {
  queue_dlist_t *temp = (queue_dlist_t *)malloc(sizeof(queue_dlist_t));
  if (!temp) {
    printf("Allocation memory failed!");
    exit(0);
  }

  temp->first = NULL;
  temp->last = NULL;

  printf("Create struct queue.\n");
  return temp;
}

bool is_empty_dlist(queue_dlist_t *queue) {
  return ((queue->first == NULL) && (queue->last == NULL));
}

void enqueue_dlist(queue_dlist_t *queue, int key) {
  dnode_t *node = create_dnode();
  node->key = key;

  if (queue == NULL) {
    queue->first = node;
    queue->last = node;
  }

  printf("Added node to queue \n");

  node->prev = queue->last;
  queue->first = node->next;
  queue->last = node;
}

void dequeue_dlist(queue_dlist_t *queue) {
  if (queue == NULL) {
    return;
  } else {
    dnode_t *temp = queue->last;
    queue->last = temp->prev;
    free(temp);
  }

  if (is_empty_dlist(queue)) {
    free(queue);
    queue = NULL;
  }
}

void print_dqueue(queue_dlist_t *queue) {
  dnode_t *temp = NULL;
  temp = queue->last;

  if ((queue->first == NULL) && (queue->last == NULL)) {
    printf("Queue is empty! \n");
    return;
  }

  while (temp->next != NULL) {
    printf("%d \n", temp->key);
    temp = temp->next;
  }
}
*/
