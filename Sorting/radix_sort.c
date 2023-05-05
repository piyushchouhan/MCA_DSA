#include <stdio.h>
#include <stdlib.h>

int get_max(int arr[], int n){
    int max = arr[0];
    for( int i = 1; i < n; i++ ){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int arr[], int n, int exp){
    int* output = (int*)malloc(n * sizeof(int));
    int i, count[10] = {0};

    for(i = 0; i < n ; i++){
        count[(arr[i]/exp) % 10]++;
    }

    for(i = 1; i < 10; i++){
         count[i] = count[i] + count[i-1]; 
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i]/exp) % 10] - 1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

}

// Radix sort function
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int m = get_max(arr, n);
 
    // Do counting sort for every digit
    for (int exp = 1; m/exp > 0; exp *= 10) {
        count_sort(arr, n, exp);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
