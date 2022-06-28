#include "circlist.h"

int main() {
    clist_t clist;
    clist_init(&clist);
    for(uint32_t i = 0; i < 10; i++) {
      clist_push_front(&clist,i);
    }

    print_forward_list(&clist);
    //print_list(&clist);
    return 0;
}

