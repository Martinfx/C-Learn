#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

typedef struct node {
    uint32_t value;
    struct node *next;
} node_t;

typedef struct clist {
    node_t *head;
    node_t *tail;
} clist_t;

void clist_init(clist_t *clist) {
    clist->tail = clist->head;
}

void clist_push_front(clist_t *clist, uint32_t value) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->value = value;

    if(clist->head == clist->tail){
        clist->head = clist->tail = node;
        node->next = clist->head;
    } else {
        clist->tail->next = node;
        clist->tail = node;
        node->next = clist->head;
    }
}


/*
typedef struct node {
    uint32_t key;
    struct node *next;
} node_t;

typedef struct clist {
    struct node *head;
    struct node *tail;
} clist_t;

clist_t *create_list() {
    clist_t *circ_list = malloc(sizeof(clist_t));
    return circ_list;
}

clist_t *push_front(clist_t *list, uint32_t key) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->next = NULL;
    node->key = key;

    if(list->head == NULL) {
        list->head = node;
        list->tail = node;
    }

    node->next = list->head;
    list->tail->next = node;
    list->head = node;

    return list;
}

void print_list(clist_t *list) {
    if(list->head) {
        node_t *curr = list->head;
        do {
            printf("curr->key %d \n", curr->key);
            curr = curr->next;
        }   while(curr != list->head);
    }
}
*/
