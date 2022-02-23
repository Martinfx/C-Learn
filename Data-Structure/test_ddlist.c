#include "ddlist.h"

int main() {
    d_list_t *dl = create_list();

    for(unsigned int i = 0; i < 10; i++) {
        push_back_dllist(dl, rand() % 100);
    }

    print_forward_dllist(dl);
    print_backward_dllist(dl);

    push_back_dllist(dl, 2000);
    printf("Count of node in list : %d \n",
           print_length_list(dl));

    push_to_begin(&dl);
    printf("Count of node in list : %d \n",
           print_length_list(dl));

    pop_dllist(&dl);
    printf("Count of node in list : %d \n",
           print_length_list(dl));

    remove_dllist(dl);
}

