#include "ring_buffer.h"

int main() {

    ring_buffer_t ring_buffer;
    ring_buffer_init(&ring_buffer, 5);
    ring_buffer_push(&ring_buffer, 1);
    ring_buffer_push(&ring_buffer, 2);
    ring_buffer_push(&ring_buffer, 3);
    ring_buffer_push(&ring_buffer, 4);
    ring_buffer_push(&ring_buffer, 5);
    /*ring_buffer_push(&ring_buffer, 6);*/

    uint32_t element = 0;
    ring_buffer_pop(&ring_buffer, &element);
    //printf("%d", element);
    ring_buffer_pop(&ring_buffer, &element);
    //printf("%d", element);
    ring_buffer_pop(&ring_buffer, &element);
 //   printf("%d", element);
    ring_buffer_pop(&ring_buffer, &element);
 //   printf("%d", element);

    ring_buffer_free(&ring_buffer);

   /* for (int i = 0; i < 11; i++) {
        printf("%d\n", i % 10);
    }*/

    return 0;
}
