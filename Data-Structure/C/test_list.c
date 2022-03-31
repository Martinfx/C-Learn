#include "list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

void linked_list() {
    list_t *list = list_init();
    for (uint32_t i = 0; i < 10; i++){
        list = push_front(list, 12);
    }
    for (uint32_t i = 0; i < 5; i++) {
        list = pop_front(list);
    }
    find(list, 10);
    print_backward_list(list);
    printf("Length of list is %u items.\n", length_list(list));
    print_forward_list(list);
    for (uint32_t i = 0; i < 10; i++) {
        list = push_back(list, rand() % 100);
    }
    print_forward_list(list);
    list = pop_back(list);
    list = pop_back(list);
    list = pop_back(list);
    list = pop_back(list);
    printf("Length of list is %u items.\n", length_list(list));
    remove_duplicate(list);
    print_backward_list(list);
    printf("Length of list is %u items.\n", length_list(list));
    list = erase(list, 1);
    print_forward_list(list);
    list = clear_list(list);
    list = pop_back(list);
    list = pop_back(list);
    print_forward_list(list);
}

int main() {
    linked_list();
    return 0;
}
