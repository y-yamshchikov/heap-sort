#include <iostream>

size_t iParent(size_t iChild);
size_t iLeftChild(size_t iRoot);
size_t iRightChild(size_t iRoot);
void heapify(int *A, size_t size);
void siftDown(int *A, size_t iRoot, size_t size);
void swap(int &A, int &B);
void print_array(int *A, size_t size);
void heap_sort(int *A, size_t size);

int main(int argc, char *argv[])
{

	int A[] = {324,6,234,2,7365,45,35,6368467,8345623,546375,345,6,3,634,768,45,64};
	size_t size = sizeof(A)/sizeof(A[0]);

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

void heapify(int *A, size_t size)
{
	size_t iNode = iParent(size-1);

	while(iNode >= 0)
	{
		siftDown(A, iNode, size);
		if (iNode == 0)
		{
			return;
		}
		iNode--;
	}
}

void siftDown(int *A, size_t iRoot, size_t size)
{
	while(iLeftChild(iRoot) <= size-1)
	{
		size_t iSwap = iRoot;
		size_t iLeft = iLeftChild(iRoot);
		size_t iRight = iRightChild(iRoot);

		if (A[iLeft] > A[iSwap])
		{
			iSwap = iLeft;
		}

		if ((iRight <= size-1) && (A[iRight] > A[iSwap]))
		{
			iSwap = iRight;
		}

		if (iRoot != iSwap)
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
	heapify(A, size);
	for (size_t i = size-1; i > 0; --i)
	{
		swap(A[0], A[i]);
		siftDown(A, 0, i);
	}
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
