#include <stdio.h>


int main(int argc, char **argv)
{
    int num, num2 = 0;
    int* numPtr;
    int* numPtr2;

    num = 100;
    numPtr = &num;
    numPtr2 = numPtr;
    num2 = *numPtr;
    printf("num=%d, numPtr=%d, address of num=%d, num2=%d, numPtr2=%d\n", num, numPtr, &num, num2, numPtr);
    return 0;
}

