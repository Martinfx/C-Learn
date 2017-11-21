#include <stdio.h>

#define size_array(x) (int)(sizeof(x) / sizeof(x[0]))

void bubblesort(int arr[], int size)
{
    for(int x = 0; x < size - 1; x++)
    {
        for(int i = 0; i < size - x -  1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[] = { 102,252,669,22,223,33,93,36,3,0,222,99, 1100, 121122,2,6, -10, -20, -52};

    bubblesort(arr, size_array(arr));

    for(int z = 0; z < size_array(arr); z++)
    {
        printf("Sorted element: %d, value: %d \n", z, arr[z]);
    }

    return 0;
}
