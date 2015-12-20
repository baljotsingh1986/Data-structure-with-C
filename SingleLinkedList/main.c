/*File name: main.c
 * Author Name: Baljot Singh
 * Description: Use of linked list
 *               */

#include "LinkedList.h"

int main()
{
	struct LinkedList* linkedList = NULL;  /*Linked List*/
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
	
	printf("\nPrinting list after adding values\n\n");
	printList(linkedList);

	printf("\nLength of initial list: %d\n", getLength(linkedList));

	if(removeNode("Add this End of all", linkedList))
	{
		printf("\nEnd of all is removed\n");
	}

	if(removeNode("Hi List", linkedList))
	{
		printf("\nHi List is removed\n");
	}

	printf("\nPrinting list after removing nodes\n\n");
	printList(linkedList);

	printf("\nLength of list after removing nodes: %d\n", getLength(linkedList));

	iter = initIterator(linkedList);
	printf("\nPrinting list by iterator\n\n");
	while(hasNext(iter))
	{
		printf("val: %s\n", next(iter));
	}

	printf("\nPrinting after reversing the list.\n\n");
	reverseList(linkedList);
	printList(linkedList);

	freeList(linkedList);

	return 0;
}
