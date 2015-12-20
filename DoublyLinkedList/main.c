/*File name: main.c
 * Author Name: Baljot Singh
 * Description: Use of DoublyLinkedList list
 *               */

#include "DoublyLinkedList.h"

int main()
{
	struct DoublyLinkedList* linkedList = NULL;  /*Linked List*/
	struct Iterator* iter = NULL; /*Will be used as iterator*/
	linkedList = initLinkedList(); /*Initialize linked list*/

	addLast("This is just before end", linkedList);
	addFront("Hi List", linkedList);
	addFront("Add this before hi", linkedList);
	addFront("This is front of all", linkedList);
	addLast("Add this at end", linkedList);
	addBefore("Add this before front of all", "This is front of all", linkedList);
	addBefore("This is before Hi List", "Hi List", linkedList);
	addAfter("Add this after Hi List", "Hi List", linkedList);
	addAfter("Add this End of all", "Add this at end", linkedList);
	
	/*Printing front*/
	printf("\nFront of list: %s\n", getFront(linkedList));
	
	/*Printing last*/
	printf("\nLast of list: %s\n\n", getLast(linkedList));

	printf("Printing all List.\n\n");
	printList(linkedList);

	printf("\nLength of list: %d\n", getLength(linkedList));

	if(removeNode("Add this End of all", linkedList))
	{
		printf("\nEnd of all is removed\n\n");
	}

	if(removeNode("Hi List", linkedList))
	{
		printf("Hi List is removed\n\n");
	}

	printf("Printing all List after removing nodes.\n\n");
	printList(linkedList);

	if(removeFront(linkedList))
	{
		printf("Front is removed\n\n");
	}

	if(removeLast(linkedList))
	{
		printf("Back is removed\n\n");
	}

	printf("Printing all List after removing nodes.\n\n");
	printList(linkedList);

	printf("\nLength of list after removing nodes: %d\n", getLength(linkedList));

	iter = initIterator(linkedList);
	printf("\nPrinting list by iterator\n\n");
	while(hasNext(iter))
	{
		printf("val: %s\n", next(iter));
	}

	printf("\nPrinting list in reverse order\n\n");
	printListReverse(linkedList);

	freeList(linkedList);

	return 0;
}
