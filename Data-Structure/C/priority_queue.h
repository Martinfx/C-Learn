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

void init_priority_queue(priority_queue_t *pq) { pq->head = NULL;}
void push_priority_queue(priority_queue_t *pq, uint32_t item, int32_t priority){
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->item = 0;
    node->next = NULL;
    node->priority = 0;

    if(pq->head == NULL) {
        pq->head = node;
    }

    node_t *temp = pq->head;
    //node_t *prev = NULL;

    if(pq->head->priority > priority) {
        temp->next = pq->head;
        pq->head = temp;
    }
   /* else {
        while(temp->next !=NULL && temp->next->priority < priority)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
    }*/
}

void print(priority_queue_t *pq) {
    node_t *temp = pq->head;

    while (temp != NULL) {
        printf("%d %d\n", temp->item, temp->priority);
        temp = temp->next;
    }
}

void pop_priority_queue(priority_queue_t* pq) {
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

