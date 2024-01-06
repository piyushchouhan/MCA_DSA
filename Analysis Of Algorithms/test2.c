#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

int Select(int arr[], int p, int r, int i ){
    int q, k;
    if(p == r){
        return arr[p];
    }
    q = partition(arr, p, r);
    k = q - p +1;
    if(k == i){
        return arr[q];
    }else if(i < k){
        Select(arr, p, q -1, i);
    }else{
        Select(arr, q +1, r, i -k);
    }
}

int main(){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	int *arr = (int *)malloc(n * sizeof(int));
	printf("Enter %d elements: \n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
    int i;
    printf("Enter the i in ith minimum element: ");
    scanf("%d", &i);

    int ith_min = Select(arr,0,n-1,i);
    printf("The %dth smallest element is: %d\n",i, ith_min);
    
} 