#include <stdbool.h>
#include <stdio.h>

#define size_array(x) (int)(sizeof(x) / sizeof(x[0]))

void print_array(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("Sorted element: %d, value: %d \n", i, arr[i]);
  }

  printf("------------------------------------------------\n");
}

void bubblesort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void insertsort(int arr[], int size) {
    int j = 0, item = 0;
    for (int i = 1; i < size; i++) {
        item = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > item) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = item;
    }
}

void binary_search(int arr[], int size)  {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if(arr[mid] == size){
        }
        else if (size < arr[mid]){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

int main() {
  int arr[] = {99, 44, 23, 12, 78, 102, 252, 669, 22, 223, -55, -150, 0, 1};
  bubblesort(arr, size_array(arr));
  print_array(arr, size_array(arr));

  int arr2[] = {99, 44, 23, 12, 78, 102, 252, 669, 22, 223, -55, -150, 0, 1};
  insertsort(arr2, size_array(arr2));
  print_array(arr2, size_array(arr2));

  int arr3[] = {99, 44, 23, 12, 78, 102, 252, 669, 22, 22, -55, -150, 0, 1};
  binary_search(arr3, size_array(arr3));
  print_array(arr3, size_array(arr3));


  return 0;
}
