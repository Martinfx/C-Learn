#include <stdio.h>

/// Basic pointer sample
int main(int argc, char **argv)
{
    /// int variables
    int val, val2, val3 = 0;
    int sum, mul = 0;
    /// Pointer variables
    int *p, *p2, *p3 = NULL;

    val = 100;
    // adress to p
    p = &val;
    // p2 point to p
    p2 = p;
    // give me value from p
    val2 = *p;
    // p3 point to p
    p3 = p;
    // give me value from p3
    val3 = *p3;
    // sumary two pointer
    sum = *p + *p2;
    // multiple value plus value pointer
    mul = sum * (*p);

    printf("num=%d, p->%p, address of num=%p\n", val, p, &val);
    printf("num2=%d, p2->%p, num3=%d\n", val2, p2, val3);
    printf("sum=%d\n", sum);
    printf("mul=%d\n", mul);
    printf("sum=%d", *p += 1);
    return 0;
}

