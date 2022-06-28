#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_GENERIC(T)                                                      \
  typedef struct T##_vector {                                                  \
    T *arr;                                                                    \
    size_t capacity;                                                           \
    size_t size;                                                               \
  } T##_vector;

#define VEC_INIT(T)                                                            \
  void T##_vector_init(T##_vector *vec) {                                      \
    const size_t capacity = 16;                                                \
    vec->arr = calloc(capacity, sizeof(T) * capacity);                         \
    vec->capacity = capacity;                                                  \
    vec->size = 0;                                                             \
  }

#define VEC_PRINT(T)                                                           \
  void T##_vector_print(T##_vector *vec) {                                     \
    for (size_t i = 0; i < vec->size; i++) {                                   \
      printf("vec->arr[%zu] \n", vec->arr[i]);                                 \
    }                                                                          \
  }

#define VEC_PUSH_BACK(T)                                                       \
  void T##_vector_pushback(T##_vector *vec, T key) {                           \
    if (vec->size == vec->capacity) {                                          \
      void *ptr = realloc(vec->arr, sizeof(T) * vec->capacity * 2);            \
      vec->arr = ptr;                                                          \
      vec->capacity = vec->capacity * 2;                                       \
      vec->arr[vec->size] = key;                                               \
      vec->size = vec->size + 1;                                               \
      printf("vec->size: %zu, vec->capacity: %zu \n", vec->size,               \
             vec->capacity);                                                   \
    }                                                                          \
    vec->arr[vec->size] = key;                                                 \
    vec->size = vec->size + 1;                                                 \
  }

#define VEC_FREE(T)                                                            \
  void T##_vec_free(T##_vector *vec) {                                             \
    if (vec->arr) {                                                            \
      free(vec->arr);                                                          \
      vec->arr = NULL;                                                         \
    }                                                                          \
  }

#define VECTOR_ENTRY(T)                                                        \
  VECTOR_GENERIC(T);                                                           \
  VEC_INIT(T);                                                                 \
  VEC_PRINT(T);                                                                \
  VEC_PUSH_BACK(T);                                                            \
  VEC_FREE(T);                                                                 \

typedef struct vec {
  uint32_t *arr;
  uint32_t size;
  uint32_t capacity;
} vec_t;

vec_t *vec_is_null(vec_t *vec) {
  if (!vec) {
    printf("poiter to vec_t is null. \n");
    return vec;
  }
  return vec;
}

void vec_init(vec_t *vec) {
  if (!vec_is_null(vec)) {
    exit(0);
  }

  const size_t capacity = 16;
  vec->arr = calloc(capacity, sizeof(uint32_t) * capacity);
  vec->capacity = capacity;
  vec->size = 0;
}

void vec_set(vec_t *vec, uint32_t index, uint32_t key) {
  if (index < 0 || index >= vec->size) {
    printf("Index is out of range! \n");
  } else {
    vec->arr[index] = key;
    vec->size += 1;
  }
}

void vec_pushback(vec_t *vec, uint32_t key) {
  if (vec->size == vec->capacity) {
    vec->arr = realloc(vec->arr, sizeof(uint32_t) * vec->capacity * 2);
    vec->capacity *= 2;
    vec->arr[vec->size] = key;
    vec->size += 1;
  } else {
    vec->arr[vec->size] = key;
    vec->size += 1;
  }
}

void vec_print(vec_t *vec) {
  printf("debug: vec->size : %u \n", vec->size);
  for (uint32_t i = 0; i < vec->size; i++) {
    printf("%u \n", vec->arr[i]);
  }
}

void vec_free(vec_t *vec) {
  if (vec->arr) {
    free(vec->arr);
    vec->arr = NULL;
  }
}
