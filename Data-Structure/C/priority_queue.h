#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    uint32_t item;
    int32_t priority;
} node_t;

typedef struct priority_queue {
    node_t *head;
} priority_queue_t;

void priority_queue_init(priority_queue_t *pq) {
    pq->head = NULL;
}

uint32_t priority_queue_top(priority_queue_t *pq) {
    return pq->head->item;
}

void priority_queue_push(priority_queue_t *pq, uint32_t item, int32_t priority){
    node_t *node = (node_t*)malloc(sizeof(node_t));
    if (!node) {
        printf("Allocation memory failed!\n");
        exit(0);
    }
    node->item = item;
    node->next = NULL;
    node->priority = priority;

    if(pq->head == NULL || node->priority <= pq->head->priority) {
        node->next = pq->head;
        pq->head = node;
    }
    else {
        node_t *temp = pq->head;
        while(temp->next !=NULL && temp->next->priority <= node->priority)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
    }
}

void priority_queue_print(priority_queue_t *pq) {
    node_t *temp = pq->head;

    while (temp != NULL) {
        printf("%d %d\n", temp->item, temp->priority);
        temp = temp->next;
    }

    /*while (temp != NULL) {
        printf("%p -> %p, %d, %d\n", (void*)temp, (void*)temp->next,temp->item, temp->priority);
        temp = temp->next;
    }*/
}

void priority_queue_pop(priority_queue_t* pq) {
    if(pq->head != NULL && pq != NULL) {
        node_t *temp = NULL;
        temp = pq->head;
        pq->head = pq->head->next;
        free(temp);
        printf("remove item from front\n");
    } else {
        printf("is empty\n");
    }
}
