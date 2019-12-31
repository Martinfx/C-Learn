#include "vector.h"

// VECTOR_ENTRY(int)

int main() {
  vec_t v;
  vec_init(&v);
  for (int i = 0; i < 20; i++) {
    vec_pushback(&v, rand() % 100);
  }

  vec_print(&v);
  vec_free(&v);

  return 0;
}
