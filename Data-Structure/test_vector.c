#include "vector.h"

int main() {
    vec_t *vec = vec_create();

    for (uint32_t i = 0; i < 20; i++) {
        vec = vec_push_back(vec, rand() % 100);
    }

    vec_destroy(vec);

    return 0;
}
