#include <iostream>

void heap_sort(int *A, size_t n);

size_t iParent(size_t i);
size_t iLeftChild(size_t i);
size_t iRightChild(size_t i);

void print_array(int *A, size_t size);

void swap(int &A, int &B);

void heapify(int *A, size_t n);
void siftDown(int *A, size_t start, size_t end); //end is an index of a last element

int main(int argc, char* argv[])
{
	int arr[] = {8,9};
	size_t size = sizeof(arr)/sizeof(arr[0]);

	print_array(arr, size);
	heap_sort(arr, size);
	print_array(arr, size);

	return 0;
}

void heap_sort(int *A, size_t n)
{
	heapify(A, n);

	size_t end = n-1;
	while (end > 0)
	{
		swap(A[end--], A[0]);
		siftDown(A, 0, end);
	}
}

size_t iParent(size_t i)
{
	return (i-1)/2;
}

size_t iLeftChild(size_t i)
{
	return 2*i + 1;
}

size_t iRightChild(size_t i)
{
	return 2*i + 2;
}

void heapify(int *A, size_t n)
{
	size_t start = iParent(n-1); //n-1 because of number->index conversion

	while (start >= 0)
	{
		siftDown(A, start, n-1);
		if (start == 0) break;
		start--;
	}
}

void siftDown(int *A, size_t start, size_t end)
{
	size_t iRoot = start;

	while (iLeftChild(iRoot) <= end)
	{
		size_t iChild = iLeftChild(iRoot);
		size_t iSwap = iRoot;

		if (A[iSwap] < A[iChild])
		{
			iSwap = iChild;

		}
		if ((iChild+1 <= end/*there is a right child*/) && (A[iSwap] < A[iChild+1]/*and it is greater*/))
		{
			iSwap = iChild+1/*right child*/;
		}

		if (iSwap == iRoot)
		{
			return;
		}
		else
		{
			swap(A[iRoot], A[iSwap]);
			iRoot = iSwap;
		}
	}
}

void swap(int &A, int &B)
{
	int C = A;
	A = B;
	B = C;
}

void print_array(int *A, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}
