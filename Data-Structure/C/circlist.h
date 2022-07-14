#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <memory.h>

typedef struct node {
    uint32_t value;
    struct node *next;
} node_t;

typedef struct clist {
    node_t *head;
    node_t *tail;
} clist_t;

void clist_init(clist_t *clist) {
    clist->tail = NULL;
    clist->head = NULL;
}

void clist_push_front(clist_t *clist, uint32_t value) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    if (!node) {
        printf("Allocation memory failed!\n");
        exit(0);
    }

    node->value = value;

    if(clist->head == NULL && clist->tail == NULL){
        clist->head = clist->tail = node;
        node->next = clist->head;
        printf("1xxx\n");
    } else {
        printf("2xxx\n");
        clist->tail->next = node;
        clist->tail = node;
        node->next = clist->head;
    }
}

void clist_free(clist_t *clist) {
    node_t *temp = clist->head;
    node_t *next = NULL;
    while (temp != NULL) {
        next = temp->next;
        free(temp);

        if(temp == clist->tail)
            break;

        temp = nexat;
    }
}

void print_forward_list(clist_t *list) {
    node_t *node = list->head;
    printf("----------------------------------------------------------------------\n");
    while (node != NULL) {
        printf("List item: current is %p; next is %p; data is %u\n", (void *)node,
               (void *)node->next, node->value);

        if(node == list->tail)
            break;

        node = node->next;
    }
}
