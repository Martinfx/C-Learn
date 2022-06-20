#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <sys/select.h>

#include "threads.h"

typedef struct ring_buffer {
    uint32_t *buffer;
    uint32_t *read;
    uint32_t *write;
    _Atomic size_t size;
    mtx_t mutex_lock;
} ring_buffer_t;


void ring_buffer_init(ring_buffer_t *buffer, size_t size)
{
    assert(buffer && size);
    buffer->buffer = malloc(size * sizeof (uint32_t));
    buffer->read = NULL;
    buffer->write = NULL;
    buffer->size = size;
    buffer->read = buffer->write = buffer->buffer;
}

void ring_buffer_push(ring_buffer_t *buffer, size_t element) {
    uint32_t *next = buffer->buffer + ((buffer->write - buffer->buffer) + 1) % (buffer->size);
    *buffer->write = element;
    printf("write: %d\n", *buffer->write);
    buffer->write = next;
}

uint32_t ring_buffer_pop(ring_buffer_t *buffer, uint32_t *element) {
    uint32_t *next = buffer->buffer + ((buffer->read - buffer->buffer) + 1)%(buffer->size);
    if (buffer->read  == buffer->write) {
        printf("is full!\n");
    }
    *element = *buffer->read;
    buffer->read = next;
}

void ring_buffer_free(ring_buffer_t *buffer){
    if(buffer) {
        free(buffer->buffer);
    }
}

static ring_buffer_t ring_buffer;
struct timespec ts1 = {
    .tv_sec = 0,
    .tv_nsec = 500*1000*10
};

void writer(void *args) {
     while (true){
        nanosleep(&ts1, NULL);
        mtx_lock(&ring_buffer.mutex_lock);
        ring_buffer_push(&ring_buffer, rand() % 10);
        printf("writer\n");
        mtx_unlock(&ring_buffer.mutex_lock);
     }
}

void reader(void *args) {
    while(true) {
      nanosleep(&ts1, NULL);
      mtx_lock(&ring_buffer.mutex_lock);
      uint32_t element;
      ring_buffer_pop(&ring_buffer, &element);
      printf("pop: %d\n", element);
      printf("reader\n");
      mtx_unlock(&ring_buffer.mutex_lock);
    }
}

int main() {
    srand( time(0) );
    ring_buffer_init(&ring_buffer, 10);
    mtx_init(&ring_buffer.mutex_lock, mtx_plain);
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

    ring_buffer_free(&ring_buffer);

    return 0;
}
