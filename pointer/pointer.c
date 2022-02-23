#include <stdio.h>

/// Basic pointer sample
int main(int argc, char **argv)
{
    /// int variables
    int number = 0;
    int number_two = 0;
    int number_tree = 0;
    /// Pointer variables
    int* pointer = NULL;
    int* pointer_two = NULL;

    int* pointer_tree = NULL;

    number = 100;
    pointer = &number;
    pointer_two = pointer;
    number_two = *pointer;
    pointer_tree = pointer;

    number_tree = *pointer_tree;

    printf("num=%d, numPtr=%p, address of num=%d, num2=%d, numPtr2=%p\n, num3=%d", number, pointer, &number, number_two, pointer_two, number_tree);

    return 0;
}

