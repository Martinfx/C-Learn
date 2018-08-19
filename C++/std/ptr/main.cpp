#include <iostream>

bool parameters_with_ptr(int *x, int *y)
{
    std::cout << "*x: " << *x << " *y: " << *y << std::endl;
    return *x < *y;
}

bool parameters_with_ab(int *a, int *b)
{
    std::cout << "*a: " << *a << " *b: " << *b << std::endl;
    return *a < *b;
}

int main()
{
    int x = 0;
    int y = 5;

    int *ptr_x = &x;
    int *ptr_y = &y;

    if(parameters_with_ptr(ptr_x, ptr_y)) {
        std::cout << "ptr_x is less than ptr_y"  << std::endl;
    }

    int a = 4;
    int b = 1;
    if(parameters_with_ab(&a, &b)) {
        std::cout << "a is less than b"  << std::endl;
    }else {
        std::cout << "a is greater than b"  << std::endl;
    }

    return 0;
}

