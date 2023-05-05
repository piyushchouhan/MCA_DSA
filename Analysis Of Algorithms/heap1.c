#include <stdio.h>

void maxHeapify(int A[], int n, int i)
{
    int largest;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && A[left] > A[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if (right <= n && A[right] > A[largest])
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

    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(A, n, i);
    }
}

void heapSort(int A[], int n)
{
    buildHeap(A, n);
    for (int i = n; i >= 1; i--)
    {
        int temp1 = A[1];
        A[1] = A[i];
        A[i] = temp1;
        n = n - 1;
        maxHeapify(A, n, 1);
    }
}
