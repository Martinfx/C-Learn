#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

typedef struct ring_buffer {
    uint32_t *buffer;
    uint32_t *read;
    uint32_t *write;
    size_t size;
} ring_buffer_t;


void ring_buffer_init(ring_buffer_t *buffer, size_t size)
{
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

void ring_buffer_pop(ring_buffer_t *buffer, size_t *element) {
    ///access_lock.lock();
    uint32_t *next  = buffer->buffer + ((buffer->read - buffer->buffer) + 1)%(buffer->size);
    if (buffer->read  == buffer->write)
    {
        //access_lock.unlock();
        //return false;
        printf("is empty!\n");
    }
    element = *buffer->read;
    printf("pop: %d\n", *buffer->read);
    buffer->read = next;
}

void ring_buffer_free(ring_buffer_t *buffer){
    if(buffer) {
        free(buffer->buffer);
    }
}
