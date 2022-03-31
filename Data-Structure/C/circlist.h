#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node {
    uint32_t key;
    struct node *next;
} node_t;

typedef struct clist {
    struct node *head;
    struct node *tail;
} clist_t;

clist_t *create_list() {
    clist_t *circ_list = calloc(2, sizeof(clist_t));
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
