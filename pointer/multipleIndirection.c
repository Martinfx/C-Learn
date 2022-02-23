#include <stdio.h>

#define size_array(x) (int)( sizeof(x) / sizeof(x[0]) )

unsigned int data[3];			// some integers

int main(int argc, char **argv) {
    unsigned int *pi;			// a simple pointer to an integer
    unsigned int **ppi;			// a pointer to a pointer to an integer

    printf ("multiple indirection example\n");

    printf("size_array(data) %d : \n", size_array(data));

    // initialize our integer array
    for (unsigned int i = 0; i < size_array(data); i++)
    {
        data[i] = i;
    }
    for (unsigned int i = 0; i < size_array(data); i++)
    {
        printf("Position %d, %d\n", i, data[i]);
    }

    /*
    * A: simple pointer to a pointer to an integer
    *
    */
    pi = data;								// set the pointer to an integer  to the start of the data array
    ppi = &pi;								// and set the pointer to a pointer to pi itself

    for (unsigned int i = 0; i < size_array(data); i++) {
        printf("array address is %p\n", data);
        printf("item pointed to by pi is %d\n", *pi);
        printf("item pointed to by ppi is %p\n", *ppi);
        printf("item pointed to by double indirection of ppi is %d\n\n", **ppi);
        printf("The address of pi is %p and the value of ppi (what it points to) is %p\n\n", &pi, ppi);

        pi += 1;		// advance the pointer to point to the next element of the data array
    }

    return 0;
}
