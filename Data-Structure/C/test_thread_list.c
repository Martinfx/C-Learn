#include "thread_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#include <threads.h>

// Show error code from thread return value
void debug_thread_error_code(int code) {
    switch (code) {
    case thrd_success:
        printf("Thread state Initialize successful\n");
        assert(true);
        break;
    case thrd_nomem:
        printf("Due to out of memory condition\n");
        assert(false);
        break;
    case thrd_timedout:
        printf("Indicates timed out\n");
        assert(false);
        break;
    case thrd_busy:
        printf("Due to resource temporary unavailable\n");
        assert(false);
        break;
    case thrd_error:
        printf("Indicates unsuccessful\n");
        assert(false);
        break;
    default:
        assert(false);
        break;
    }
}

typedef struct threadsafe_node {
    _Atomic uint32_t key;
    struct threadsafe_node *pNext;
} threadsafe_node_t;

typedef struct threadsafe_list {
    _Atomic uint32_t count;
    threadsafe_node_t *pHead;
    threadsafe_node_t *pTail;
    mtx_t mutex;
    cnd_t cnd;
} threadsafe_list_t;

threadsafe_list_t *is_list_null(threadsafe_list_t *list) {
    if (!list) {
        debug("List (list*) is NULL!");
        return list;
    } else {
        return list;
    }
}

threadsafe_list_t *is_head_null(threadsafe_list_t *list) {
    if (!list->pHead) {
        debug("List (list->head) is NULL!");
        return list;
    } else {
        return list;
    }
}

threadsafe_list_t *threadsafe_list_init() {
    threadsafe_list_t *list = (threadsafe_list_t*)malloc(sizeof(threadsafe_list_t));
    if(!list) {
        printf("Allocation memory failed!\n");
        assert(list);
    }

    list->count = 0U;
    list->pHead = list->pTail = NULL;

    debug_thread_error_code(mtx_init(&list->mutex, mtx_plain));
    debug_thread_error_code(cnd_init(&list->cnd));

    return list;
}

threadsafe_node_t* new_node(uint32_t key) {
    threadsafe_node_t *node = (threadsafe_node_t*)calloc(2, sizeof(threadsafe_node_t));
    if(!node) {
        printf("Allocation memory failed!\n");
        assert(node);
    }
    node->pNext =NULL;
    node->key = key;
    return node;
}

threadsafe_list_t *threadsafe_list_push_back(threadsafe_list_t *list, int key) {
    mtx_lock(&list->mutex);

    if(list && list->count < 5) {
        threadsafe_node_t *node = new_node(key);

        if(!list->pTail) {
            list->pHead = list->pTail = node;
        }
        else {
            list->pTail->pNext = node;
            list->pTail = node;
        }

        list->count++;

        printf("Count of nodes in list %u \n", list->count);

    } else {
        printf("List is full! %u \n", list->count);
    }

    mtx_unlock(&list->mutex);
    return list;
}

threadsafe_list_t *threadsafe_list_pop_back(threadsafe_list_t *list) {
    // lock
    mtx_lock(&list->mutex);

    //if (list) {
        if (is_list_null(list) && is_head_null(list)) {
        threadsafe_node_t *node = list->pHead;
        //if(node) {
            while (node->pNext != NULL) {
                node = node->pNext;
            }

            list->pTail = node;
            free(list->pTail->pNext);
            list->pTail->pNext = NULL;
            list->count--;
        }
      //}
   // }

    // unlock
    mtx_unlock(&list->mutex);
    return list;
}

uint32_t list_thread_length(threadsafe_list_t *list) {
    if(list) {
        return list->count;
    }
    return 0;
}

bool list_threadsafe_is_empty(threadsafe_list_t *list) {
    printf("list_threadsafe_is_empty %u: \n", list->count);
    return (list->count == 0) ? true : false;
}

threadsafe_list_t *clear_list(threadsafe_list_t *list) {
    if (list) {

        // lock
        mtx_lock(&list->mutex);

        threadsafe_node_t *temp = list->pHead;
        threadsafe_node_t *next = NULL;

        while (temp != NULL) {
            list->count--;
            //printf("list->count-- %d\n", list->count);
            next = temp->pNext;
            free(temp);
            temp = next;

        }

        // unlock
        mtx_unlock(&list->mutex);
        mtx_destroy(&list->mutex);

        printf("Count of nodes in list %u \n", list->count);
        free(list);
        list = NULL;
        return list;
    }

    return list;
}

static threadsafe_list_t *list_thread;
static uint32_t SIZE_MAX_ITEMS = 5;

void consumer(void *arg)
{
    while (true) {

        //mtx_lock(&list_thread->mutex);

        if(!list_threadsafe_is_empty(list_thread)) {
            printf("Test list is empty: %d \n", list_threadsafe_is_empty(list_thread));
            printf("Consumer thread number %li \n", (long)arg);
            threadsafe_list_pop_back(list_thread);
            cnd_broadcast(&list_thread->cnd);
        }
        else {
            printf("Consumer waiting : %ld \n", (long)arg);

            cnd_wait(&list_thread->cnd, &list_thread->mutex);
        }

        //mtx_unlock(&list_thread->mutex);

        //thrd_sleep(&(const struct timespec){.tv_sec=10L}, NULL); // sleep 1 sec
    }
}

void producer(void *arg)
{
    while (true) {
        //mtx_lock(&list_thread->mutex);

        if(list_thread_length(list_thread) < SIZE_MAX_ITEMS) {
            printf("Producer thread number %li \n", (long)arg);
            threadsafe_list_push_back(list_thread, rand() % 10);
            cnd_broadcast(&list_thread->cnd);
        }
        else {
            printf("Producer waiting: %ld \n", (long)arg);
            cnd_wait(&list_thread->cnd, &list_thread->mutex);
        }

        //mtx_unlock(&list_thread->mutex);

        //thrd_sleep(&(const struct timespec){.tv_sec=10L}, NULL); // sleep 1 sec
    }
}

void test_thread_linked_list()
{
    const int PROD_NUM_THREADS = 2;
    const int CONS_NUM_THREADS = 2;

    thrd_t producer_threads[PROD_NUM_THREADS];
    thrd_t consumer_threads[CONS_NUM_THREADS];

    list_thread = threadsafe_list_init();
    printf("------start thread test--------\n");

    for (uint32_t i = 0; i < PROD_NUM_THREADS; i++) {
        if (thrd_create(&producer_threads[i], (thrd_start_t)producer, (void*)(long)i) != thrd_success) {
            printf("Thread error : %u", i);
        }
    }


    for (uint32_t i = 0; i < CONS_NUM_THREADS; i++) {
        if (thrd_create(&consumer_threads[i], (thrd_start_t)consumer, (void*)(long)i) != thrd_success) {
            printf("Thread error : %u", i);
        }
    }

    int result = 0;
    for (uint32_t i = 0; i < PROD_NUM_THREADS; i++) {
        if(thrd_join(producer_threads[i], &result) == thrd_error) {
            printf("Thread error : %d", result);
        }
    }

    int result1 = 0;
    for (uint32_t i = 0; i < CONS_NUM_THREADS; i++) {
        if(thrd_join(consumer_threads[i], &result1) == thrd_error) {
            printf("Thread error : %d", result);
        }
    }

    printf("end thread test\n\n");
    // printf("Thread return %d at the end\n", result);
    list_thread = clear_list(list_thread);
    list_thread = NULL;
}


int main() {
    test_thread_linked_list();
    return 0;
}
