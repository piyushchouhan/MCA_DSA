#include <stdio.h>

void min_heapify(int arr[], int n, int i){
    int smallest = i;
    int left = 2*i +1 ;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest] ){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if( smallest != i){
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        min_heapify(arr,n,smallest);
    }
}

int main() {
    int arr[] = {30,20,6,19,16,13,4,8,10,15,7,11,12,3};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    min_heapify(arr, n, 2);
 
    printf("Heapified array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    return 0;
}