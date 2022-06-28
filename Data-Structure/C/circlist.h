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
      temp = next;
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
