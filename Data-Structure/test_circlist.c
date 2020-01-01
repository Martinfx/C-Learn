#include "circlist.h"

int main() {
    c_list_t *list = create_clist();
    list = push_front(list, 1);
    list = push_front(list, 2);
    list = push_front(list, 3);
    list = push_front(list, 4);
    list = push_front(list, 5);
    list = push_front(list, 6);

    print_list(list);
    printf("--------------------------------------");


    list = push_front(list, 7);
    list = push_front(list, 8);
    list = push_front(list, 9);

    print_list(list);
    printf("--------------------------------------");

    return 0;
}
