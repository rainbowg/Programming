/*
http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Sorting/heapSort.htm
Four basic procedures on max heap are

Heapify, which runs in O(lg n) time.
Build-Heap, which runs in linear time.
Heap Sort, which runs in O(n lg n) time.
Extract-Max, which runs in O(lg n) time.
*/

void Heapify(int arr[], int pos)
{
	int left = pos * 2;
	int right = pos * 2 + 1;
	int largest = pos, tmp;
	int length = arr[0];// arr[0] is for storing length
	
	if (left <= length && arr[left] > arr[largest])
		largest = left;
	if (right <= length && arr[right] > arr[largest])
		largest = right;
	if (largest != pos)
	{
		tmp = arr[largest];
		arr[largest] = arr[pos];
		arr[pos] = tmp;
		Heapify(arr, largest);
	}
}

void BuildHeap(int arr[], int length)
{
	for (int i = length / 2; i >= 1; i--)
		Heapify(arr, i);
}

void HeapSort(int arr[], int length)
{
	int tmp;
	for (int i=length; i >=2; i--)
	{
		tmp = arr[1];
		arr[1] = arr[length];
		arr[length] = tmp;
		Heapify(arr, 1);
	}
}

int ExtractMax(int arr[])
{
	return arr[1];
}