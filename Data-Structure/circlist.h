#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *head;
    struct node *tail;
    struct node *next;
    int key;
} c_list_t;

c_list_t *create_clist() {
    c_list_t *list = (c_list_t*)malloc(sizeof(c_list_t));
    // NULL pointer is always false
    if(!list) {
        printf("Cannot allocate list!\n");
        exit(1);
    }

    list->head = NULL;
    list->tail = NULL;
    list->next = NULL;
    list->key = 0;

    return list;
}

c_list_t *create_node() {
    c_list_t *node = (c_list_t*)malloc(sizeof(c_list_t));
    if(!node) {
        printf("Cannot allocate node!\n");
        exit(1);
    }

    node->key = 0;
    node->next = NULL;
    return node;
}

c_list_t *push_front(c_list_t *list, int key) {
    c_list_t *node = create_node();
    // if is list->head == NULL then add node
    if(!list->head) {
        node->key = key;
        list->head = node;
        list->tail = node;
        node->next = list->head;
        return list;
    }

    c_list_t *temp = list->head;
    node->key = key;
    node->next = temp;
    list->head = node;
    list->tail->next = list->head;
    return list;
}

/*c_list_t *push_front__(c_list_t *list, int key) {
    c_list_t *node = create_node();
    if(!list->head){
        node->key = key;
        list->head = node;
        list->tail = node;
        node->next = list->head;
        return list;
    }

    c_list_t *temp = list->head;
    node->key = key;
    node->next = temp;
    list->head = node;
    list->tail->next = list->head;
    return list;
}*/

void print_list(c_list_t *list) {
    if(list->head) {
        c_list_t *temp = list->head;
        do {
            printf("List node: current is %p; \n"
                   "temp->next is %p; \n"
                   "temp->data is %d \n",
                   //"lenght is %d\n",
                   (void*)temp,
                   (void*)temp->next,
                   temp->key);
            temp = temp->next;
        } while (temp != list->head);
    }

    /*while(temp != list->head) {
            printf("List node: current is %p; \n"
                   "temp->next is %p; \n"
                   "temp->data is %d \n",
                   //"lenght is %d\n",
                   (void*)temp,
                   (void*)temp->next,
                   temp->key);

            temp = temp->next;
        }*/
}

/*
void remove_whole_list(circual_list_t *list) {
    circual_list_t *temp = list->head;
    circual_list_t *next = list->head;

    while(temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
    list = NULL;
}
*/
