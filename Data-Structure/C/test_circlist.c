#include "circlist.h"

int main() {
    // TODO: Fix me
    clist_t *list = create_list();
    push_front(list, 10);
    push_front(list, 11);
    push_front(list, 12);
    push_front(list, 13);
    push_front(list, 14);
    print_list(list);

    return 0;
}
