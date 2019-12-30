#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct vector {
    uint32_t item;
    uint32_t size;
    uint32_t capacity;
} vec_t;

vec_t *vec_create() {
    vec_t *v = (vec_t*)malloc(10 * sizeof (vec_t));
    if(!v) {
        printf("Allocation memory failed!");
        exit(0);
    }

    v->capacity = 10;
    v->size = 0;
    v->item = 0;
    return v;
}

vec_t *is_vector_null(vec_t *vec) {
    if(!vec) {
        printf("Vector (vec*) is NULL!");
        return vec;
    }
    return vec;
}

uint32_t vec_capacity(vec_t *vec) {
    if(is_vector_null(vec)) {
        printf("vector is null!");
        exit(0);
    }
    return vec->capacity;
}

uint32_t vec_size(vec_t *vec) {
    if(!vec) {
        printf("vector is null!");
        exit(0);
    }
    return vec->size;
}

uint32_t vec_get_index(vec_t *vec, uint32_t index) {
    uint32_t out = 0;
    if(is_vector_null(vec)) {
        if(index < 0 || index >= vec->size) {
            printf("Index is out of range! \n");
            return out;
        }
        return vec[vec->size].item;
    }
    return out;
}

vec_t *vec_push_back(vec_t *vec, uint32_t item) {
    if(is_vector_null(vec)) {
        if(vec->size == vec->capacity) {

            void *ptr = realloc(vec, sizeof (vec_t) * vec->capacity * 2);
            if(!ptr) {
                printf("debug: Cannot reallocate memory! \n");
                exit(0);
            }

            vec = ptr;
            vec->capacity = vec->capacity * 2;

            printf("debug: %zu bytes allocated, are: \n", sizeof(vec) * vec->capacity);
            vec[vec->size].item = item;
            printf("debug: vec[%u].item \n", vec->size);
            vec->size = vec->size + 1;
            return vec;
        }

        vec[vec->size].item = item;
        printf("debug: v[%u].item, \n", vec->size);
        vec->size = vec->size + 1;
        return vec;
    }

    return vec;
}

void vec_destroy(vec_t *vec) {
    if(vec) {
        free(vec);
    }
}

//////////////////////////////////////////////

#define VEC_GENERIC(T)                                            \
  typedef struct T##_vec {                                        \
    T *arr;                                                       \
    size_t capacity;                                              \
    size_t size;                                                  \
  } T##_vec;

#define VEC_INIT(T)                                               \
  void T##_vector_init(T##_vector *vec) {                         \
    const size_t capacity = 10;                                   \
    vec->arr = calloc(capacity, sizeof(T) * vec->capacity);       \
    vec->capacity = capacity;                                     \
    vec->size = 0;                                                \
  }

#define VEC_PRINT(T)                                              \
  void T##_vector_print(T##_vector *vec) {                        \
    for(size_t i = 0; i < vec->size; i++) {                       \
        printf("%u \n", vec->arr[i]);                             \
    }                                                             \
  }

//#define VEC_GENERIC(T)                                            \
//  vector_vec(T);                                                  \
//  vector_init(T) vector_print(T)

typedef struct vec {
    uint32_t size;
    uint32_t capacity;
    uint32_t *arr;
} vec2_t;

vec2_t *vec_is_null(vec2_t *vec) {
    if(!vec) {
        printf("poiter to vec_t is null. \n");
        return vec;
    }
    return vec;
}

void vec_init(vec2_t *vec) {
    if(!vec_is_null(vec)) {
        exit(0);
    }

    const size_t capacity = 10;
    vec->arr = calloc(capacity, sizeof(uint32_t) * capacity);
    vec->capacity = capacity;
    vec->size = 0;
}

void vec_set(vec2_t *vec, uint32_t index, uint32_t key) {
    if(index < 0 || index >= vec->size) {
        printf("Index is out of range! \n");
    }
    else {
        vec->arr[index] = key;
    }
}

void vec_pushback(vec2_t *vec, uint32_t key) {
    vec->arr[vec->size] = key;
    vec->size = vec->size + 1;
}

void vec_print(vec2_t *vec) {
    for (uint32_t i = 0; i < vec->size; i++) {
        printf("%u \n", vec->arr[i]);
    }
}
