#include "circlist.h"

int main() {
    clist_t clist;
    clist_init(&clist);
    //clist_push_front(&clist,1);
    //clist_push_front(&clist,2);
//    clist_push_front(&clist,3);
//    clist_push_front(&clist,4);

    // TODO: Fix me
/*    clist_t *list = create_list();
    for(uint32_t i = 0; i < 10; i++) {
        list = push_front(list, rand() % 100);
    }
    print_list(list);*/
    return 0;
}

//AddressSanitizer:DEADLYSIGNAL
//=================================================================
//==70485==ERROR: AddressSanitizer: BUS on unknown address (pc 0x0000002b7c0c bp 0x7fffffffd840 sp 0x7fffffffd800 T0)
//==70485==The signal is caused by a READ memory access.
//==70485==Hint: this fault was caused by a dereference of a high value address (see register values below).  Disassemble the provided pc to learn which register was used.
//    #0 0x2b7c0c in push_front /usr/home/maxfx/Documents/C-Learn/Data-Structure/C/circlist.h:33:22
//    #1 0x2b7c0c in main /usr/home/maxfx/Documents/C-Learn/Data-Structure/C/test_circlist.c:7:16
//    #2 0x23529f in _start /usr/src/lib/csu/amd64/crt1_c.c:75:7
//    #3 0x8002dd007  (<unknown module>)

//AddressSanitizer can not provide additional info.
//SUMMARY: AddressSanitizer: BUS /usr/home/maxfx/Documents/C-Learn/Data-Structure/C/circlist.h:33:22 in push_front
//==70485==ABORTING
