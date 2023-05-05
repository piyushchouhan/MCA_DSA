#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
   int i, key, j;
   for (j = 1; j <n; j++) {
       key = arr[j];
       i = j - 1;
       
       // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
       while (i >= 0 && arr[i] > key) {
           arr[i+1] = arr[i];
           i = i-1;
       }
       arr[i+1] = key;
   }
}

int main() {
   int n;
   printf("Enter the size of the array: ");
   scanf("%d", &n);
   
   int *arr = (int *)malloc(n * sizeof(int));
   printf("Enter %d elements:\n", n);
   for (int i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
   }
   
   insertionSort(arr, n);
   
   printf("Sorted array: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");
  
    return 0;
}