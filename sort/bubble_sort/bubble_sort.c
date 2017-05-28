#include <stdio.h>

#define size_array(x) (int)( sizeof(x) / sizeof(x[0]) )

void bubblesort(int arr[], int size)
{
    int helper = 0;
    for(int x = 0; x < size - 1; x++)
    {
        for(int i = 0; i < size - 1 ; i++)
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
    int arr[] = { 102,252,669,22,223,33,93,36,3,0,222,99};

    bubblesort(arr, size_array(arr));

    for(int z = 0; z < size_array(arr); z++)
    {
        printf("Sorted element: %d, value: %d \n", z, arr[z]);
    }

    return 0;
}
