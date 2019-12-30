#include "vector.h"

int main() {
    vec_t *vec = vec_create();
    for (uint32_t i = 0; i < 20; i++) {
        vec = vec_push_back(vec, rand() % 100/);
    }
    vec_destroy(vec);

    /*vec2_t v;
    vec_init(&v);
    vec_pushback(&v, 20);
    vec_pushback(&v, 30);
    vec_pushback(&v, 40);
    vec_print(&v);*/

    return 0;
}
