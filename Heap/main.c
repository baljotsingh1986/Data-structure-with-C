/*File name: main.c
 * Author: Baljot Singh
 * Description:Use of heap data structure
 *             */

#include "Heap.h"

#define SIZE 13

int main()
{
	int i;
	TYPE arr[SIZE] = {-1,2,5,3,1,7,11,8,0,4,6,9,10};
	TYPE val = 11;

	struct Heap* heap = NULL;
	heap = initHeap();
	insert(val, heap);
	insert(10, heap);
	insert(9, heap);
	insert(8, heap);
	insert(7, heap);
	insert(6, heap);
	insert(5, heap);
	insert(4, heap);
	insert(3, heap);
	insert(2, heap);
	insert(1, heap);
	insert(0, heap);
	insert(-1, heap);

	printf("\nPrinting heap.\n");
	printHeap(heap);

	printf("\nCalling remove min in loop.\n");
	while(!isEmpty(heap))
	{
		printf("Val: %d\n", removeMin(heap));
	}
	
	freeHeap(heap);

	/*Use heapSort to sort array in descending order*/
	heapSort(arr, SIZE);

	/*reverse the array*/
	reverseArray(arr, SIZE);

	printf("\nPrinting array after sorting.\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("arr: %d\n", arr[i]);
	}
	return 0;
}
