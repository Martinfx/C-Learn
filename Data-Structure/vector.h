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
            printf("debug: vec[%i].item \n", vec->size);
            vec->size = vec->size + 1;
            return vec;
        }

        vec[vec->size].item = item;
        printf("debug: v[%i].item, \n", vec->size);
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
