#include "list.h"

int main()  {
     list_t *l = create();

    for(unsigned int i = 0; i < 10; i++) {
        l = push_front_list(l, 12);
    }

    for (unsigned int i = 0; i < 5; i++) {
        l = pop_front_list(l);
    }

    find(l, 10);
    print_backward_list(l);
    printf("Length of list is %u items.\n", length_list(l));
    print_forward_list(l);

    for (unsigned int i = 0; i < 10; i++) {
        l = push_back_list(l, rand() % 100);
    }

    print_forward_list(l);
    l = pop_back_list(l);
    l = pop_back_list(l);
    l = pop_back_list(l);
    l = pop_back_list(l);
    printf("Length of list is %u items.\n", length_list(l));

    remove_duplicate(l);
    print_backward_list(l);
    printf("Length of list is %u items.\n", length_list(l));
    l = erase(l, 1);

    print_forward_list(l);
    l = clear_list(l);
    print_forward_list(l);
}
