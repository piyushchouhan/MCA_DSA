// Heap Sort in C

#include <stdio.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int arr[], int N, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && arr[left] > arr[largest])
		largest = left;

	if (right < N && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {

		swap(&arr[i], &arr[largest]);
		max_heapify(arr, N, largest);
	}
}


void heapSort(int arr[], int N)
{

	// Build max heap
	for (int i = N / 2 - 1; i >= 0; i--)
		max_heapify(arr, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		// Heapify root element to get highest element at
		max_heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver's code
int main()
{
	int arr[] = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
	int N = sizeof(arr) / sizeof(arr[0]);

	
	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);
}

