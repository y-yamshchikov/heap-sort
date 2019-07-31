#include <iostream>

size_t iLeftChild(size_t iRoot);
size_t iRightChild(size_t iRoot);
size_t iParent(size_t iChild);
void swap(int &A, int &B);
void heapify(int *A, size_t size);
void siftDown(int *A, size_t iRoot, size_t size);
void heap_sort(int *A, size_t size);
void print_array(int *A, size_t size);

int main(int argc, char *argv[])
{

	int A[] = {3456,456,367,478,67,7,6634,2,7,434,23,4235,4,75,86,75,6453,45,457,234,24,3,5234,234,23,42341,324534,563,8,67};
	size_t size = sizeof(A)/sizeof(A[0]);

	print_array(A, size);
	heapify(A, size);
	print_array(A, size);
	heap_sort(A, size);
	print_array(A, size);


	return 0;
}


size_t iLeftChild(size_t iRoot)
{
	return iRoot*2 + 1;
}

size_t iRightChild(size_t iRoot)
{
	return iRoot*2 + 2;
}

size_t iParent(size_t iChild)
{
	return (iChild-1)/2;
}

void swap(int &A, int &B)
{
	int C = B;
	B = A;
	A = C;
}

void heapify(int *A, size_t size)
{
	size_t node = iParent(size-1);

	while (node >= 0)
	{
		siftDown(A, node, size);
		if (node == 0)
		{
			return;
		}
		node--;
	}

}

void siftDown(int *A, size_t iRoot, size_t size)
{
	while (iLeftChild(iRoot) < size)
	{
		size_t iSwap = iRoot;

		size_t iLeft = iLeftChild(iRoot);
		size_t iRight = iRightChild(iRoot);

		if (A[iLeft] > A[iSwap])
		{
			iSwap = iLeft;
		}

		if ((iRight < size) && (A[iRight] > A[iSwap]))
		{
			iSwap = iRight;
		}

		if (iSwap != iRoot)
		{
			swap(A[iRoot], A[iSwap]);
			iRoot = iSwap;
		}
		else
		{
			return;
		}
	}
}

void heap_sort(int *A, size_t size)
{
	for (size_t i = size-1; i > 0; --i)
	{
		swap(A[i], A[0]);
		siftDown(A, 0, i/*index->size conversion*/);
	}
}

void print_array(int *A, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}
