/*File name: Heap.c
 * Author: Baljot Singh
 * Description:Implementation of Header file Heap.h
 *             */

#include "Heap.h"
#include "func.h"

/*struct for heap*/
struct Heap
{
	TYPE* arr; /*pointer to TYPE for dynamic array*/
	int len; /*To count the enteries in arr*/
	int size; /*To keep track of size of arr*/
};

/*Helper function to resize dynamic arr*/
void _resize(struct Heap* heap)
{
	TYPE* newArr = (TYPE*)realloc(heap->arr, sizeof(TYPE)*(heap->size *= 2));
	if(newArr)
	{
		heap->arr = newArr;
	}
	else
	{
		free(heap->arr);
		exit(1);
	}
}

/*Function to initialize Heap*/
struct Heap* initHeap()
{
	struct Heap* heap = NULL;
	heap = (struct Heap*)malloc(sizeof(struct Heap));
	heap->arr = (TYPE*)malloc(sizeof(TYPE)*2);
	if(!heap->arr)
	{
		printf("Not enough memory.\n");
		exit(1);
	}
	heap->size = 2;
	heap->len = 0;
	return heap;
}

/*Helper Function to percolate up*/
void _percolateUp(TYPE *arr, TYPE val, int pos)
{
	for(; pos > 0 && comparator(val, arr[(pos-1)/2]) == 1; pos = (pos -1)/2)
	{
		arr[pos] = arr[(pos-1)/2];
	} 

	arr[pos] = val;
}

/*Helper Function to percolate down*/
void _percolateDown(TYPE *arr, int size, int pos)
{
	TYPE temp;
	int i = pos;
	for(;i < size; )
	{
		/*No more Children*/
		if ((i*2 + 1) >= size) 
		{
			i = i*2 + 1;
		}
		
		/*Both children are there*/
		else if((i*2 + 2) < size)
		{
			/*If Both children are greater or equal break*/
			if (comparator(arr[(i*2 + 2)], arr[i]) == -1 && comparator(arr[(i*2 + 1)], arr[i]) == -1)
			{
				break;
			}

			/*Else of second child is smaller than first swap second child with parent*/
			else if(comparator(arr[(i*2 + 2)], arr[(i*2 + 1)]) == 1)
			{
				temp = arr[(i*2 + 2)];
				arr[(i*2 + 2)] = arr[i];
				arr[i] = temp;
				i = i*2 + 2;
			}

			/*Else swap first child with parent*/
			else
			{
				temp = arr[(i*2 + 1)];
				arr[(i*2 + 1)] = arr[i];
				arr[i] = temp;
				i = i*2 + 1;
			}
		}

		/*Only 1 child is there*/
		else if((i*2 + 1) < size)
		{
			/*If child is greater or equal break*/
			if (comparator(arr[(i*2 + 1)], arr[i]) == -1)
			{
				break;
			}

			/*Else swap first child with parent*/
			else
			{
				temp = arr[(i*2 + 1)];
				arr[(i*2 + 1)] = arr[i];
				arr[i] = temp;
				i = i*2 + 1;
			}
		}

		else
		{
			break;
		}
	} 
}

/*Function to insert value to heap*/
void insert(TYPE val, struct Heap* minHeap)
{
	int pos;

	if(minHeap->len >= minHeap->size)
	{
		_resize(minHeap);
	}
	pos = minHeap->len;
	minHeap->len++;
	_percolateUp(minHeap->arr, val, pos);
}

int isEmpty(struct Heap* minHeap)
{
	if(minHeap->len < 1)
	{
		return 1;
	}

	return 0;
}

/*Function to delete min*/
TYPE removeMin(struct Heap* minHeap)
{
	if (minHeap->len < 1)
	{
		printf("Error:Heap is empty. Exiting\n");
		free(minHeap->arr);
		minHeap->arr = NULL;
		free(minHeap);
		minHeap = NULL;
		exit(1);
	}
	
	else
	{
		int pos, min;
		minHeap->len--;
		pos = minHeap->len;
		min = minHeap->arr[0];
		minHeap->arr[0] = minHeap->arr[pos];
		_percolateDown(minHeap->arr, minHeap->len, 0);
		return min;
	}
}

/*Function to sort a given array using heap sort*/
void heapSort(TYPE* arr, int size)
{
	int i, len, temp;
	
	/*Build heap of given array*/
	for (i = size/2 - 1; i >= 0; i--)
	{
		_percolateDown(arr, size, i);
	}
	
	len = size;
	/*Sort array in descending order*/
	for (i = 0; i < size; i++) 
	{
		temp = arr[0];
		arr[0] = arr[len - 1];
		arr[len - 1] = temp;
		len--;
		_percolateDown(arr, len, 0);
	}
}

/*Function to reverse given array*/
void reverseArray(TYPE* arr, int size)
{
	int len = size - 1, i, temp;
	for (i = 0; i < size/2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len];
		arr[len] = temp;
		len--;
	}
}

/*Function to print heap*/
void printHeap(struct Heap* heap)
{
	int i =0;
	for(; i < heap->len; i++)
	{
		printType(heap->arr[i]);
	}
}

void freeHeap(struct Heap* heap)
{
	free(heap->arr);
	heap->arr = NULL;
	free(heap);
	heap = NULL;
}
