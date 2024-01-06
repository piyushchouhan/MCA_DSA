//bucket_sort
#include <stdio.h>
#include <stdlib.h>

//Insertion Sort
void insertionSort(float arr[], int size){
    for(int i = 1; i < size; i++){
        float key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j +1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void bucketSort(float Arr[], int n){
    float max = Arr[0];
    for(int i =0 ; i < n; i++){
        if(Arr[i] > max){
            max = Arr[i];
        }
    }

    int num_buckets = (int)max+1;
    float** B = (float**)malloc(num_buckets * sizeof(float*));
    for (int i = 0; i < num_buckets; i++) 
        B[i] = (float*)malloc(n * sizeof(float));
    
    int* B_count = (int *)malloc(num_buckets * sizeof(int));
    for (int i = 0; i < num_buckets; i++) {
        B_count[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int index = (int)Arr[i];
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
    float A[] = {4.20, 2.35, 2.56, 8.45, 3.98, 3.02, 1.56};
    int n = sizeof(A) / sizeof(A[0]);

    bucketSort(A, n);

    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");

    return 0;
}
