#include <iostream>
#include <cstdlib>

void foo (int *& p) {
    std::cout << "&p: " << &p << std::endl;
    std::cout << "p: " << *p << std::endl;
}

void foo_(int &y, const int &x) {
    int xx = x;
    xx++;
    y = xx;
}

int main(int argc, char *argv[]) {
    int i = 100000;
    int *q = &i;

    std::cout << "&q: " << &q << std::endl;
    foo(q);

    int x = 0, xx = 0;
    foo_(xx, x);

    std::cout << "return by reference: " << xx << std::endl;

    return EXIT_SUCCESS;
}

