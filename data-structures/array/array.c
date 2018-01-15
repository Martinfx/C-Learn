#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size_array(x) (int)( sizeof(x) / sizeof(x[0]) )
#define MAX_SIZE_ARRAY 4

static int array[MAX_SIZE_ARRAY];

void push(int *array, int position, int key)
{
    int i;
    for(i = MAX_SIZE_ARRAY - 1; i >= position; i--)
    {
        array[i] = array[i - 1];

        //printf("i: %d \n: ", i);
        //printf("array[i]: %d \n", array[i]);
        //printf("array[i - 1]: %d; \n", array[i - 1]);
    }

    array[i] = key;
}

void pop(int *array, int position)
{
    int i;
    for(i = position; i <= MAX_SIZE_ARRAY; i++)
    {
        array[i - 1] = array[i];
        //printf("\n array[i - 1] = array[i] %d : \n", array[i - 1] = array[i]);
        array[i - 1] = 0;
    }
}

void print_array(int *array)
{
    //printf("-----------------------------------------\n");
    printf("\n");
    int i;
    for(i = 0; i < MAX_SIZE_ARRAY; i++)
    {
        printf("%d\t", array[i]);
        //printf("Print item of array position: %d; %d \n", i, array[i]);
    }
}

int main()
{
    push(array, 1, 30);
    push(array, 2, 40);
    push(array, 3, 50);
    push(array, 4, 60);

    print_array(array);

    pop(array, 1);
    pop(array, 2);
    pop(array, 3);
    pop(array, 4);

    print_array(array);

    /*int arr[2];

    for(int i = 0; i < size_array(arr); i++)
    {
        printf("Enter the %d number \n", i + 1);
        {
            scanf("%d", &arr[i]);
        }
    }

    for(int i = 0; i < size_array(arr); i++)
    {
        printf("Enter : %d the number : %d  \n", i + 1, arr[i]);
    }*/

    return 0;
}
