/*File name: DoublyLinkedList.c
 * Author Name: Baljot Singh
 * Description: Implementation of file DoublyLinkedList.h
 *               */

#include "DoublyLinkedList.h"

/*A struct to define a node of doubly linked list*/
struct node
{
	char val [50];
	struct node* next;
	struct node* prev;
};


/*Struct to make a list of nodes and count it*/
struct DoublyLinkedList
{
	struct node* head;
	struct node* tail;
	int count;
};

/*Struct Iterator to iterate over list*/
struct Iterator
{
	struct node* cur;
};

/*Helper function to Build a new Node*/
struct node* _newNode()
{
	struct node* newNode  = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

/*Function to Initialize doubly linked list*/
struct DoublyLinkedList* initLinkedList()
{
	struct DoublyLinkedList* list = NULL;
	list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
	list->head = _newNode();
	list->tail = _newNode();
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->count = 0;
	return list;
}

/*Function to initialize Iterator*/
struct Iterator* initIterator(struct DoublyLinkedList* list)
{
	struct Iterator* iter = (struct Iterator*)malloc(sizeof(struct Iterator));
	iter->cur = list->head;
	return iter; 
}

/*Function to Add new node at front*/
void addFront(const char* val, struct DoublyLinkedList* list)
{
	struct node* newNode = _newNode();
	strcpy(newNode->val, val);
	newNode->next = list->head->next;
	list->head->next->prev = newNode;
	list->head->next = newNode;
	newNode->prev = list->head;
	list->count++;
}

/*Function to a Add new node at end*/
void addLast(const char* val, struct DoublyLinkedList* list)
{
	struct node* newNode = _newNode();
	strcpy(newNode->val, val);
	newNode->next = list->tail;
	newNode->prev = list->tail->prev;
	list->tail->prev->next = newNode;
	list->tail->prev = newNode;
	list->count++;
}

/*Function to a Add new node before a given value*/
int addBefore(const char* newVal, const char* existingVal, struct DoublyLinkedList* list)
{
	struct node* newNode = _newNode();
	strcpy(newNode->val, newVal);
	struct node* nextNode = list->head;
       	while(nextNode->next)
       	{
	       if(strcmp(nextNode->next->val, existingVal) == 0)
	       {
			struct node* temp = nextNode->next;
			nextNode->next = newNode;
			newNode->next = temp;
			newNode->prev = temp->prev;
			temp->prev = newNode;
			list->count++;
			return 1;
	       }
	       nextNode = nextNode->next;
       	}	
        return 0; 
}

/*Function to Add new node after a given value*/
int addAfter(const char* newVal, const char* existingVal, struct DoublyLinkedList* list)
{
	struct node* newNode = _newNode();
	strcpy(newNode->val, newVal);
	struct node* nextNode = list->head->next;
       	while(nextNode->next)
       	{
	       if(strcmp(nextNode->val, existingVal) == 0)
	       {
			struct node* temp = nextNode->next;
			nextNode->next = newNode;
			newNode->next = temp;
			newNode->prev = nextNode;
			temp->prev = newNode;
			list->count++;
			return 1;
	       }
	       nextNode = nextNode->next;
       	}	
       	return 0; 
}

/*Function to Remove node for given value*/ 
int removeNode(const char* val, struct DoublyLinkedList* list)
{
	struct node* nextNode = list->head->next;
       	while(nextNode->next)
       	{
	       if(strcmp(nextNode->val, val) == 0)
	       {
			struct node* temp = nextNode;
			nextNode->prev->next = nextNode->next;
			nextNode->next->prev = nextNode->prev;
			free(temp);
			list->count--;
			return 1;
	       }
	       nextNode = nextNode->next;
       	}	
       	return 0;
}

/*Function to get value at front of list*/
char* getFront(struct DoublyLinkedList* list)
{
	if (list->count > 0)
	{
		return list->head->next->val;
	}

	return NULL;
}

/*Function to get value at last of list*/
char* getLast(struct DoublyLinkedList* list)
{
	if (list->count > 0)
	{
		return list->tail->prev->val;
	}

	return NULL;
}

/*Function to remove value at front of list*/
int removeFront(struct DoublyLinkedList* list)
{
	if (list->count > 0)
	{
		struct node* temp = list->head->next;
		temp->next->prev = list->head;
		list->head->next = temp->next;
		free(temp);
		list->count--;
		return 1;
	}

	return 0;
}

/*Function to remove value at last of list*/
int removeLast(struct DoublyLinkedList* list)
{
	if (list->count > 0)
	{
		struct node* temp = list->tail->prev;
		list->tail->prev = temp->prev;
		temp->prev->next = list->tail;
		free(temp);
		list->count--;
		return 1;
	}

	return 0;
}

/*Function to get length of list*/
int getLength(struct DoublyLinkedList* list)
{
	return list->count;
}

/*Function to Iterate over linked list*/
int hasNext(struct Iterator* iter)
{
	if(iter->cur->next->next == NULL)
	{
		free(iter);
		return 0;
	}
	return 1;
}

/*Function to Return the value and move iterator to next*/
char* next(struct Iterator* iter)
{
	iter->cur = iter->cur->next;
	return iter->cur->val;
}

/*Function to Print List*/
void printList(struct DoublyLinkedList* list)
{
	struct node* nextNode = list->head->next;
	while(nextNode->next)
	{
		printf("Val: %s\n", nextNode->val);
		nextNode = nextNode->next;
	}

}

/*Function to Print List in reverse order*/
void printListReverse(struct DoublyLinkedList* list)
{
	struct node* prevNode = list->tail->prev;
	while(prevNode->prev)
	{
		printf("Val: %s\n", prevNode->val);
		prevNode = prevNode->prev;
	}

}

/*Function to free List*/
void freeList(struct DoublyLinkedList* list)
{
	struct node* nextNode = list->head->next;
	while(nextNode)
	{
		struct node* temp = nextNode;
		nextNode = nextNode->next;
		free(temp);
	}
	free(list->head);
	free(list);
}
