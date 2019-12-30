#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "debug.h"

/*
 * push_front(list_t *l, key)      add to front
 * pop_front(list_t *l)            remove front item
 * push_back(list_t *l, key)       add to back
 * pop_back(list_t *l)             remove last item from list
 * find(list_t *l, key)            is key in list ?
 * erase(list_t *l, pos)           remove key from list
 * remove_list(list_t *l)          remove all nodes from list
 * length_list(list_t *l)          length of list
 * print_forward_list(list_t *l)   forward prints
 * print_backward_list(list_t *l)  backward prints
 * sort(list_t *l)                 sort of keys in list
 * remove_duplicate(list_t *l)     remove duplicites from list
 */

typedef struct node {
    uint32_t key;
    struct node *next;
} node_t;

typedef struct list {
    struct node *head;
    struct node *tail;
} list_t;

list_t *create() {
    list_t *list = (list_t*)calloc(2, sizeof(list_t));
    if(!list) {
        debug("Allocation memory failed!\n");
        exit(0);
    }
    return list;
}

node_t *node() {
    node_t *node = (node_t*)calloc(2, sizeof(node_t));
    if(!node) {
        debug("Allocation memory failed!\n");
        exit(0);
    }
    return node;
}

list_t *is_list_null(list_t *list) {
    if(!list) {
        debug("List (list*) is NULL!");
        return list;
    } else {
        return list;
    }
}

list_t *is_head_null(list_t *list) {
    if(!list->head) {
        debug("List (list->head) is NULL!");
        return list;
    } else {
        return list;
    }
}

list_t *is_tail_null(list_t *list) {
    if(!list->tail) {
        debug("List (list->tail) is NULL!");
        return list;
    } else {
        return list;
    }
}

uint32_t length_list(list_t *list) {
    uint32_t len = 0;
    if(is_list_null(list)) {
        node_t *t = list->head;

        if(t != NULL) {
            node_t *curr = NULL;
            for (curr = t; curr != NULL; curr = curr->next) {
                len += 1;
            }
            return len;
        }
    }
    return len;
}

void find(list_t *list, uint32_t key) {
    if(is_list_null(list) && is_head_null(list)) {
        node_t *t = list->head;
        while (t != NULL) {
            if(t->key == key) {
                printf("Found key: %u\n", t->key);
            } else {
                debug("Not found key");
            }
            t = t->next;
        }
    }
}

list_t *push_front(list_t *list, uint32_t key) {
    if(is_list_null(list)) {
        node_t *n = node();
        n->next = NULL;
        n->key = key;

        if(!list->head && !list->tail) {
            list->tail = n;
            list->head = list->tail;
            return list;
        }
        else {
            list->tail->next = n;
            list->tail = n;
        }
    }

    return list;
}

list_t *pop_front(list_t *list) {
    if(is_list_null(list) && is_head_null(list)) {
        node_t *temp = NULL;
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }

    return list;
}

list_t *push_back(list_t *list, uint32_t key) {
    if(is_list_null(list)) {
        node_t *n = node();
        n->key = key;
        n->next = NULL;

        if(!list->head && !list->tail) {
            list->head = n;
            list->tail = list->head;
        } else {
            list->tail->next = n;
            list->tail = n;
        }
    }

    return list;
}

list_t *pop_back(list_t *list) {
    if(is_list_null(list) && is_head_null(list)) {
        node_t *t = list->head;
        while (t->next->next != NULL) {
            t = t->next;
        }

        list->tail = t;
        free(list->tail->next);
        list->tail->next = NULL;
    }
    return list;
}

list_t *erase(list_t *list, uint32_t pos) {
    if(is_list_null(list) && is_head_null(list)) {
        node_t *temp1 = list->head;
        node_t *temp2 = NULL;

        if (pos >= 1 && pos <= length_list(list)) {

            for (uint32_t i = 0; i < pos - 1; ++i) {
                printf("Pos: %u \n", i);
                printf("Pos: curr is %p; next is %p; data is %u\n",
                       (void*)temp1,
                       (void*)temp1->next,
                       temp1->key);

                temp1 = temp1->next;
            }

            temp2 = temp1->next;
            temp1->next = temp2->next;
            printf("Erase temp2->key: %u \n", temp2->key);
            free(temp2);
        } else {
            debug("Positon is out of range list");
        }
    }
    return list;
}

void print_forward_list(list_t *list) {
    if(is_list_null(list) && is_head_null(list)) {
        node_t *node = list->head;
        printf("------------------------------------------------\n");
        while(node != NULL) {
            printf("List item: current is %p; next is %p; data is %u\n",
                   (void *)node, (void *)node->next, node->key);

            node = node->next;
        }
    }
}

void print_backward_list(list_t *list) {
    if(is_list_null(list)) {
        node_t *curr = list->tail;
        node_t *last = NULL;

        if(is_head_null(list)) {
            printf("------------------------------------------------\n");
            while (last != list->head) {
                while (curr->next != last) {
                    curr = curr->next;
                }

                last = curr;
                printf("List item: current is %p; next is %p; data is %u\n", (void *)last,
                       (void *)last->next, last->key);

                curr = list->head;
            }
        }
    }
}

list_t *clear_list(list_t *list) {
    if(is_list_null(list)) {
        node_t *temp = list->head;
        node_t *next = NULL;

        while (temp != NULL) {
            next = temp->next;
            free(temp);
            temp = next;
        }

        free(list);
        list = NULL;
        return list;
    }

    return list;
}

void sort_list(list_t *list) {
    if(is_list_null(list)) {

        node_t *head = NULL;
        node_t *last = NULL;
        bool swap = false;

        do {
            swap = false;
            head = list->head;

            while (head->next != last) {
                if (head->key > head->next->key) {
                    uint32_t temp = head->key;
                    head->key = head->next->key;
                    head->next->key = temp;
                    swap = true;
                }
                head = head->next;
            }
            last = head;
        } while (swap);
    }
}

void remove_duplicate(list_t *list) {
    sort_list(list);

    if(is_head_null(list)) {
        node_t *t = list->head;

        while (t->next != NULL) {
            if (t->key == t->next->key) {
                node_t *n = t->next->next;
                free(t->next);
                t->next = n;
                debug("Found duplicate item in list.");
            } else {
                t = t->next;
                debug("Not found duplicate item.");
            }
        }
    }
}
