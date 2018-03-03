#include <stdio.h>
#include <stdbool.h>

#define size_array(x) (int)(sizeof(x) / sizeof(x[0]))

void bubblesort(int arr[], int size)
{
    bool swap = false;
    do {
        swap = false;
        for(int i = 0; i < size - 1; ++i) {
            if(arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);
}

int main()
{
    int arr[] = {102,252,669,22,223, -55, -150, 0, 1};

    bubblesort(arr, size_array(arr));

    for(int i = 0; i < size_array(arr); ++i)
    {
        printf("Sorted element: %d, value: %d \n", i, arr[i]);
    }

    return 0;
}
