#include <iostream>


size_t iParent(size_t iChild);
size_t iLeftChild(size_t iRoot);
size_t iRightChild(size_t iRoot);
void swap(int &A, int &B);
void print_array(int *A, size_t size);
void siftDown(int *A, size_t iRoot, size_t size);
void heapify(int *A, size_t size);
void heap_sort(int *A, size_t size);

int main(int argc, char *argv[])
{
	int A[] = {23,42345,2356,343,128,656,3456,746,74,5,632,674,8684,5679,5876,46,423,6345,73,67};
	size_t size = sizeof(A)/sizeof(A[0]);

	print_array(A, size);
	heapify(A, size);
	print_array(A, size);
	heap_sort(A, size);
	print_array(A, size);

	return 0;
}

size_t iParent(size_t iChild)
{
	return (iChild-1)/2;
}

size_t iLeftChild(size_t iRoot)
{
	return iRoot*2 + 1;
}

size_t iRightChild(size_t iRoot)
{
	return iRoot*2 + 2;
}

void swap(int &A, int &B)
{
	int C = B;
	B = A;
	A = C;
}

void print_array(int *A, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}

void siftDown(int *A, size_t iRoot, size_t size)
{
	while (iLeftChild(iRoot) <= size-1)
	{
		size_t iLeft = iLeftChild(iRoot);
		size_t iRight = iRightChild(iRoot);
		size_t iSwap = iRoot;

		if (A[iLeft] > A[iSwap])
		{
			iSwap = iLeft;
		}

		if ((iRight <= size-1) && (A[iRight]>A[iSwap]))
		{
			iSwap = iRight;
		}

		if (iSwap != iRoot)
		{
			swap(A[iSwap], A[iRoot]);
			iRoot = iSwap;
		}
		else
		{
			return;
		}
	}
}

void heapify(int *A, size_t size)
{
	size_t node = iParent(size-1);

	while(node >= 0)
	{
		siftDown(A, node, size);
		if (node == 0)
		{
			return;
		}
		node--;
	}
}

void heap_sort(int *A, size_t size)
{
	for (size_t i = size-1; i > 0; --i)
	{
		swap(A[0], A[i]);
		siftDown(A, 0, i);
	}
}
