#include <stdio.h>
#include <stdlib.h>

//Insertion Sort
void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j +1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void bucketSort(int Arr[], int n){
    int max = Arr[0];
    for(int i =0 ; i < n; i++){
        if(Arr[i] > max){
            max = Arr[i];
        }
    }

    int num_buckets = max+1;
    int** B = (int**)malloc(num_buckets * sizeof(int*));
    for (int i = 0; i < num_buckets; i++) 
        B[i] = (int*)malloc(n * sizeof(int));
    
    int* B_count = (int *)malloc(num_buckets * sizeof(int));
    for (int i = 0; i < num_buckets; i++) {
        B_count[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int index = Arr[i];
        B[index][B_count[index]] = Arr[i];
        B_count[index]++;
    }

    int idx = 0;
    for(int i =0; i < num_buckets; i++){
        if(B_count[i] > 0){
            insertionSort(B[i], B_count[i]);
            for(int j = 0; j < B_count[i]; j++){
                Arr[idx++] = B[i][j];
            }
        }
    }
}

int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    bucketSort(A, n);

    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}