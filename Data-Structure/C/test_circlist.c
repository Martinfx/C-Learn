#include "circlist.h"

int main() {
    // TODO: Fix me
    clist_t *list = create_list();
    for(uint32_t i = 0; i < 10; i++) {
        list = push_front(list, rand() % 100);
    }
    print_list(list);
    return 0;
}
