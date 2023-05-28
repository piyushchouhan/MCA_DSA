#include <stdio.h>

void maxHeapify(int A[], int n, int i)
{
    int largest;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && A[left] > A[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if (right < n && A[right] > A[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, n, largest);
    }
}

void buildHeap(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(A, n, i);
    }
}

void heapSort(int A[], int n)
{
    buildHeap(A, n);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp1 = A[0];
        A[0] = A[i];
        A[i] = temp1;
        maxHeapify(A, i, 0);
    }
}

int main() {
    int A[] = {4, 10, 3, 5, 1};
    int n = sizeof(A) / sizeof(A[0]);

    heapSort(A, n);

    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
