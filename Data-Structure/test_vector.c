#include "vector.h"

int main() {
    vector_t *v = create();

    for (uint32_t i = 0; i < 20; i++) {
        v = push_back(v, rand() % 100);
    }

    destroy(v);

    return 0;
}
