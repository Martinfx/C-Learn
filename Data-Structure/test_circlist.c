#include "circlist.h"

int main() {
    clist_t *clist = create_list();

    for(uint32_t i = 0; i < 10; i++) {
        clist = push_front(clist, rand() % 100);
    }
    print_list(clist);
    return 0;
}
