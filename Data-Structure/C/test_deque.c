#include "deque.h"

int main() {

    deque_t *deque = create_deque();

    for (uint32_t i = 0; i < 10; i++) {
        push_front(deque, rand() % 10);
        push_back(deque, rand() % 10);
    }

    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);
    pop_back(deque);
    pop_front(deque);

    print_deque(deque);

    return 0;
}
