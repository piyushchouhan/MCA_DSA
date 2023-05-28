#include <stdio.h>
#include <stdlib.h>

int Find_K(int arr[], int n){
    int k = 0;
    for(int i=0; i< n; i++){
        if( arr[i] > k ){
            k = arr[i];
        }
    }
    return k;
}

int* Count_sort(int arr[], int n, int m){
    int* c = (int*)malloc(m * sizeof(int));
    if (c == NULL) {
        printf("Error: failed to allocate memory\n");
        exit(1);
    }

    for(int i= 0; i <= m; i++){
        c[i] = 0;
    }

    for( int j= 0 ; j<n; j++){
        c[arr[j]] = c[arr[j]] + 1;
    }
    
 // C[i] now contains the number of elements equal to i.
    for(int i = 1; i<= m; i++){
        c[i] = c[i] + c[i-1]; 
    }


    int* b = (int*)malloc(n * sizeof(int));
    if (b == NULL) {
        printf("Error: failed to allocate memory\n");
        exit(2);
    }

    for(int l = n-1 ; l >=0; l--){
        b[c[arr[l]]-1] = arr[l];
        c[arr[l]]--;
    }
    free(c);

    return b; 
}


int main(){
    int arr[] = {2,5,3,0,2,3,0,3,8,9};
    int n = 10;
    int m = Find_K(arr, n);
    int* sorted_arr = Count_sort(arr, n, m);

    // Print the elements of the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");
    free(sorted_arr);


    return 0;
}