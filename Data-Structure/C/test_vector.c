#include "vector.h"

VECTOR_ENTRY(int);
int main() {

  int_vector v;
  int_vector_init(&v);
  for (int i = 0; i < 20; i++) {
      int_vector_pushback(&v, rand() % 100);
  }

  int_vector_print(&v);
  int_vec_free(&v);

  vec_t vv;
  vec_init(&vv);
  for (int i = 0; i < 20; i++) {
    vec_pushback(&vv, rand() % 100);
  }

  vec_print(&vv);
  vec_free(&vv);

  return 0;
}
