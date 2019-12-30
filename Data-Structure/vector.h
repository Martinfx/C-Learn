#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct vector {
    uint32_t item;
    uint32_t size;
    uint32_t capacity;
} vector_t;

vector_t *create() {
    vector_t *v = (vector_t*)malloc(10 * sizeof (vector_t));
    if(!v) {
        printf("Allocation memory failed!");
        exit(0);
    }

    v->capacity = 10;
    v->size = 0;
    v->item = 0;

    return v;
}

vector_t *is_vector_null(vector_t *vec) {
    if(!vec) {
        printf("Vector (vec*) is NULL!");
        return vec;
    }
    return vec;
}

uint32_t get_index(vector_t *vec, uint32_t index) {
    uint32_t out = 0;
    if(is_vector_null(vec)) {
        if(index < 0 || index >= vec->size) {
            printf("index is out of range! \n");
            return out;
        }
        return vec[vec->size].item;
    }
    return out;
}

vector_t *push_back(vector_t *vec, uint32_t item) {
    if(is_vector_null(vec)) {
        if(vec->size == vec->capacity) {

            void *ptr = realloc(vec, sizeof (vector_t) * vec->capacity * 2);
            if(!ptr) {
                printf("debug: Cannot reallocate memory! \n");
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
        printf("debug: v[%i].item \n", vec->size);
        vec->size = vec->size + 1;
        return vec;
    }

    return vec;
}

uint32_t capacity(vector_t *v) {
    if(!v) {
        printf("vector is null!");
        exit(0);
    }
    return v->capacity;
}

uint32_t size(vector_t *v) {
    if(!v) {
        printf("vector is null!");
        exit(0);
    }
    return v->size;
}

void destroy(vector_t *v) {
    if(v) {
        free(v);
    }
}
