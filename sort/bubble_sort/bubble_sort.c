#include <stdio.h>


void bubblesort(int *arr)
{
    int helper = 0;
    for(int x = 0; x < 12 - 1; x++)
    {
        for(int i = 0; i < 12 - 1 ; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                helper = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = helper;
            }
        }
    }
}

/// This is simple sort algoritm bubble sort
int main(int argc, char *argv[])
{
    int arr[12] = { 102,252,669,22,223,33,93,36,3,0,222,99};

    bubblesort(arr);

    for(int z = 0; z < 12; z++)
    {
        printf("Sorted: %d \n", arr[z]);
    }

    return 0;
}
