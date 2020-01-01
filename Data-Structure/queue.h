#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_INTERNAL_LIST(T)                                                 \
  typedef struct T##list {                                                     \
    struct T##list *next;                                                      \
    T key;                                                                     \
  } chunk_t;

#define QUEUE_GENERIC(T)                                                       \
  typedef struct T##queue {                                                    \
    chunk_t *first;                                                            \
    chunk_t *tail;                                                             \
    uint32_t capacity;                                                         \
    uint32_t size;                                                             \
    T *q;                                                                      \
  } T##queue__t;

#define QUEUE_INIT(T)                                                          \
  void T##queue_init(T##queue__t *queue__) {                                   \
    queue__->q = (uint32_t *)calloc(4, sizeof(uint32_t));                      \
    if (!queue__) {                                                            \
      exit(0);                                                                 \
    }                                                                          \
                                                                               \
    queue__->size = 0;                                                         \
    queue__->capacity = 64;                                                    \
    queue__->first = NULL;                                                     \
    queue__->tail = NULL;                                                      \
    printf("debug: queue->size: %u, queue__->capacity: %u \n", queue__->size,  \
           queue__->capacity);                                                 \
  }

#define QUEUE_ENQUEUE(T)                                                       \
  void T##queue_enqueue(T##queue__t *queue__, T key) {                         \
    if (queue__->size == queue__->capacity) {                                  \
      printf("debug: queue->size: %u, queue__->capacity: %u \n",               \
             queue__->size, queue__->capacity);                                \
      printf("Please wait,  queue is full.\n");                                \
    } else {                                                                   \
      chunk_t *chunk = calloc(2, sizeof(chunk_t));                             \
      if (!queue__->first) {                                                   \
        queue__->first = chunk;                                                \
        queue__->tail = chunk;                                                 \
        chunk->key = key;                                                      \
        printf("debug: chunk->key: %u \n", chunk->key);                        \
      }                                                                        \
                                                                               \
      chunk->key = key;                                                        \
      queue__->tail->next = chunk;                                             \
      queue__->tail = chunk;                                                   \
      queue__->size += 1;                                                      \
      printf("debug: next chunk->key: %u, queue__->size %u \n", chunk->key,    \
             queue__->size);                                                   \
    }                                                                          \
  }

#define QUEUE_DEQUEUE(T)                                                       \
  void T##queue_dequeue(T##queue__t *queue__) {                                \
    if (queue__->size > 0) {                                                   \
      queue__->size -= 1;                                                      \
      printf("debug: queue__->size: %u \n", queue__->size);                    \
      chunk_t *chunk = queue__->first;                                         \
      queue__->first = queue__->first->next;                                   \
      printf("debug: remove chunk->key: %u \n", chunk->key);                   \
      free(chunk);                                                             \
    }                                                                          \
  }

#define QUEUE_FREE(T)                                                          \
  void T##queue_free(T##queue__t *queue__) {                                   \
    if (queue__->first) {                                                      \
      free(queue__->q);                                                        \
      queue__->q = NULL;                                                       \
    }                                                                          \
  }

#define QUEUE_ENTRY(T)                                                         \
  QUEUE_INTERNAL_LIST(T);                                                      \
  QUEUE_GENERIC(T)                                                             \
  QUEUE_INIT(T)                                                                \
  QUEUE_ENQUEUE(T)                                                             \
  QUEUE_DEQUEUE(T)                                                             \
  QUEUE_FREE(T)

typedef struct list {
  struct list *next;
  uint32_t key;
} chunk_t;

typedef struct queue2 {
  chunk_t *first;
  chunk_t *tail;
  uint32_t capacity;
  uint32_t size;
  uint32_t *q;
} queue__t;

void queue_init(queue__t *queue__) {
  queue__->q = (uint32_t *)calloc(4, sizeof(uint32_t));
  if (!queue__) {
    exit(0);
  }

  queue__->size = 0;
  queue__->capacity = 64;
  queue__->first = NULL;
  queue__->tail = NULL;
  printf("debug: queue->size: %u, queue__->capacity: %u \n", queue__->size,
         queue__->capacity);
}

void queue_enqueue(queue__t *queue__, uint32_t key) {
  if (queue__->size == queue__->capacity) {
    printf("debug: queue->size: %u, queue__->capacity: %u \n", queue__->size,
           queue__->capacity);
    printf("Please wait,  queue is full.\n");
  } else {
    chunk_t *chunk = calloc(2, sizeof(chunk_t));

    if (!queue__->first) {
      queue__->first = chunk;
      queue__->tail = chunk;
      chunk->key = key;
      printf("debug: chunk->key: %u \n", chunk->key);
    }

    chunk->key = key;
    queue__->tail->next = chunk;
    queue__->tail = chunk;
    queue__->size += 1;

    printf("debug: next chunk->key: %u, queue__->size %u \n", chunk->key,
           queue__->size);
  }
}

void queue_dequeue(queue__t *queue__) {
  if (queue__->size > 0) {
    queue__->size -= 1;
    printf("debug: queue__->size: %u \n", queue__->size);
    chunk_t *chunk = queue__->first;
    queue__->first = queue__->first->next;
    printf("debug: remove chunk->key: %u \n", chunk->key);
    free(chunk);
  }
}

void queue_free(queue__t *queue__) {
  if (queue__->first) {
    free(queue__->q);
    queue__->q = NULL;
  }
}

typedef struct llist {
  struct llist *next;
  int key;
} node_t;

typedef struct queue {
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
    // if is pointer queue->first == NULL
    // free dealocated memory
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

/*
 * Simple implementation queue
 * as doubly linked list
 */

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
