#include<stdio.h>
#include<stdlib.h>

int Linear_search(int A[], int n, int key){
    for(int i=0; i<n; i++){
        if (A[i] == key){
            return 1;
        }
        }
        return 0;
    }


int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    if (Linear_search(A, n, key) == 1)
    {
        printf("The element %d was found in the array.\n", key);
    }
    else
    {
        printf("The element %d was not found in the array.\n", key);
    }
    return 0;
}