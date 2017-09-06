#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x, y;
    double z;
    long long int big;

} test_struct;


int main()
{
    const int size_alloc = 4;

    test_struct *p = NULL, *q = NULL;

    printf("Size of test_struct: %lu\n", sizeof(test_struct));

    p = (test_struct*)calloc(size_alloc, sizeof (test_struct));

    if(p == NULL)
    {
        printf("Allocation failed, pointer is NULL!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size_alloc; i++)
    {
        p[i].x = i;
        p[i].y = i * 20;
        p[i].z = 100000.0 + i;;
        p[i].big = 4294967296 + i;

        printf("[%d] values:\n x is %d\n y is %d\n z is %f\n big is %lld\n",
               i, p[i].x, p[i].y, p[i].z, p[i].big);
    }
    //q = p;

    //printf("[0] values:\n x is %d\n y is %d\n z is %d\n big is %lld\n",
    //       q->x, q->y, q->z, q->big);

    //q = q + 2;

    //printf("[2] values:\n x is %d\n y is %d\n z is %d\n big is %lld\n",
    //       q->x, q->y, q->z, q->big);

    free(p);

    return 0;
}
