#include <stdlib.h>
#include <stdint.h>
#include <threads.h>
#include "debug.h"

typedef struct node_thread {
    uint32_t key;
    struct node_thread *next;
} node_thread_t;

typedef struct list_thread {
    struct node_thread *head;
    struct node_thread *tail;
    mtx_t mutex;
} list_thread_t;

node_thread_t *node_thread() {
    node_thread_t *node = (node_thread_t *)
        calloc(2, sizeof(node_thread_t));
    if (!node) {
        debug("Allocation memory failed!\n");
        exit(0);
    }
    return node;
}

list_thread_t *list_init() {
    list_thread_t *list =
        (list_thread_t*)calloc(3, sizeof(list_thread_t));
    if(!list) {
        debug("Allocation memory failed!\n");
        exit(0);
    }

    int err = mtx_init(&list->mutex, mtx_plain);
    if(err) {
        debug("Initilialize mutex failed!");
    }
    return list;
}

/*
list_thread_t *is_list_null(list_thread_t *list) {
    if (!list) {
        debug("List (list*) is NULL!");
        return list;
    } else {
        return list;
    }
}

list_thread_t *is_head_null(list_thread_t *list) {
    if (!list->head) {
        debug("List (list->head) is NULL!");
        return list;
    } else {
        return list;
    }
}
*/
list_thread_t *push_front_t(list_thread_t *list, uint32_t key) {
    /*if (list<) {
    node_thread_t *n = node_thread();
    n->next = NULL;
    n->key = key;

    if (!list->head && !list->tail) {
        list->tail = n;
        list->head = list->tail;
        return list;
    } else {
        list->tail->next = n;
        list->tail = n;
    }
}
return list;*/
}
