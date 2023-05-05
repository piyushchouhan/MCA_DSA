#include <stdio.h>

int Binary_search(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = l + (r-l)/2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] > x){
            return Binary_search(arr, l, mid-1, x);
        }
        
        if(arr[mid] < x){
            return Binary_search(arr, mid+1, r, x);
        }
    }

    return -1;
}

int main(){
    int arr[] = { 2, 3, 4, 10, 41,40 ,41,41};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 41;

    int result = Binary_search(arr, 0, n - 1, x);

    if (result == -1) {
    printf("Element is not present in array");
    } 
    else{
    printf("Element is present at index %d", result);
    }
}