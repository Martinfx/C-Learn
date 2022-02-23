#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x, y;
    double z;
    long long int big_number;

} test_t;

int main()
{
    const int size_alloc = 4;

    test_t *test = NULL, *pointer = NULL;

    printf("Size of test_struct: %lu\n", sizeof(test_t));

    test = (test_t*)calloc(size_alloc, sizeof (test_t));

    if(test == NULL)
    {
        printf("Allocation failed, pointer is NULL!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size_alloc; i++)
    {
        test[i].x = i;
        test[i].y = i * 20;
        test[i].z = 100000.0 + i;;
        test[i].big_number = 4294967296 + i;

        printf("[%d] values:\n x is %d\n y is %d\n z is %f\n big is %lld\n",
               i, test[i].x, test[i].y, test[i].z, test[i].big_number);
    }

    pointer = test;

    printf("[0] values:\n x is %d\n y is %d\n z is %f\n big is %lld\n",
           pointer->x, pointer->y, pointer->z, pointer->big_number);

    pointer = pointer + 2;

    printf("[2] values:\n x is %d\n y is %d\n z is %f\n big is %lld\n",
           pointer->x, pointer->y, pointer->z, pointer->big_number);

    free(test);

    return 0;
}
