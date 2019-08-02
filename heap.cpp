#include <iostream>

void print_array(int *A, size_t size);
void swap(int &A, int &B);
size_t iLeftChild(size_t iRoot);
size_t iRightChild(size_t iRoot);
size_t iParent(size_t iChild);
void heapify(int *A, size_t size);
void siftDown(int *A, size_t iRoot, size_t size);

int main (int argc, char *argv[])
{
	int A[] = {2342,3746,5,46745,578,6,45,6968967,5634,535,646,7567,43,645,75,674363,45,42,34,2,87358,3,76,57,65,65,3465,686563,56,456,345};

	size_t size = sizeof(A)/sizeof(A[0]);
	print_array(A, size);
	heapify(A, size);
	print_array(A, size);

	return 0;
}

void heapify(int *A, size_t size)
{
	size_t node = iParent(size-1);

	while (node >=0)
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
	while (iLeftChild(iRoot) < size-1)
	{
		size_t iSwap = iRoot;
		size_t iLeft = iLeftChild(iRoot);
		size_t iRight = iRightChild(iRoot);

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
			swap(A[iSwap], A[iRoot]);
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

void print_array(int *A, size_t size)
{
	for (size_t i = 0; i < size; ++i)
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
