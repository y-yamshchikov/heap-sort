#include <iostream>

void print_array(int *A, size_t size);
void swap(int &A, int &B);
size_t iLeftChild(size_t iRoot);
size_t iRightChild(size_t iRoot);
size_t iParent(size_t iChild);
void siftDown(int *A, size_t iRoot, size_t size);
void heapify(int *A, size_t size);

int main(int argc, char *argv[])
{
	int A[] = {32452,34234,123,24,43648756,346856,96,4536,634,567,576,7,59,576,5,35,675,7,4,64};
	size_t size = sizeof(A)/sizeof(A[0]);
	
	print_array(A, size);
	heapify(A, size);
	print_array(A, size);

	return 0;
}

void print_array(int *A, size_t size)
{
	for(size_t i = 0; i < size; i++)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}

void swap(int &A, int &B)
{
	int C = B;
	B = A;
	A = C;
}

void heapify(int *A, size_t size)
{
	size_t iNode = iParent(size-1);

	while (iNode >= 0)
	{
		siftDown(A, iNode, size);
		if(iNode == 0)
		{
			return;
		}
		iNode--;
	}
}

void siftDown(int *A, size_t iRoot, size_t size)
{
	while (iLeftChild(iRoot) < size)
	{
		size_t iLeft = iLeftChild(iRoot);
		size_t iRight = iRightChild(iRoot);
		size_t iSwap = iRoot;

		if (A[iLeft] > A[iSwap])
		{
			iSwap = iLeft;
		}

		if (iRight < size && A[iRight] > A[iSwap])
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
