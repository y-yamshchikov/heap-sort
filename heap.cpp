#include <iostream>

void print_array(int *A, size_t size);
void swap(int &A, int &B);
size_t iParent(size_t iChild);
size_t iLeftChild(size_t iRoot);
size_t iRightChild(size_t iRoot);
void heapify(int *A, size_t size);
void siftDown(int *A, size_t iRoot, size_t size);

int main(int argc, char *argv[])
{
	int A[] = {342,3461,543,23,4234,626,35463,7523,6469,7536,384756,2357838,563,45,4,74568,354,534,65,73,68764};
	size_t size = sizeof(A)/sizeof(A[0]);

	print_array(A, size);
	heapify(A, size);
	print_array(A, size);



	return 0;
}

void print_array(int *A, size_t size)
{
	for(size_t i = 0; i < size; ++i)
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

	while (iNode >= 0)
	{
		siftDown(A, iNode, size);
		if(iNode == 0)
		{
			return;
		}
		--iNode;
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

		if ((iRight< size-1) && (A[iRight] > A[iSwap]))
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
