#include <stdio.h>

/// Basic pointer sample
int main(int argc, char **argv)
{
    /// int variables
    int number = 0;
    int number_two = 0;

    /// Pointer variables
    int* pointer = NULL;
    int* pointer_two = NULL;

    number = 100;
    pointer = &number;
    pointer_two = pointer;
    number_two = *pointer;

    printf("num=%d, numPtr=%d, address of num=%d, num2=%d, numPtr2=%d\n", number, pointer, &number, number_two, pointer);

    return 0;
}

