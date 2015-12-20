/*File name: LinkedList.c
 * Author Name: Baljot Singh
 * Description: Implementation of file LinkedList.h
 *               */

#include "LinkedList.h"

/*A strcut to define a node of linked list*/
struct node
{
	char val [50];
	struct node* next;
};


/*Struct to make a list of nodes and count it*/
struct LinkedList
{
	struct node* head;
	int count;
};

/*Struct for iterator to linkedlist*/
struct Iterator
{
	struct node* cur;
};

/*Helper function to Build a new Node*/
struct node* _newNode()
{
	struct node* newNode  = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	return newNode;
}

/*Function to Initialize linked list*/
struct LinkedList* initLinkedList()
{
	struct LinkedList* list = NULL;
	list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	list->head = _newNode();
	list->count = 0;
	return list;
}

/*Function to Initialize Iterator*/
struct Iterator* initIterator(struct LinkedList* list)
{
	struct Iterator* iter = (struct Iterator*)malloc(sizeof(struct Iterator));
	iter->cur = list->head;
	return iter; 
}

/*Function to Add new node at front*/
void addFront(const char* val, struct LinkedList* list)
{
	struct node* newNode = _newNode();
	strcpy(newNode->val, val);
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->count++;
}

/*Function to Add new node at end*/
void addLast(const char* val, struct LinkedList* list)
{
	struct node* newNode = _newNode();
	strcpy(newNode->val, val);
	struct node* nextNode = list->head;
       	while(nextNode->next)
       	{
	       nextNode = nextNode->next;
       	}	
       	nextNode->next = newNode;
       	list->count++;
}

/*Function to Add new node before a given value*/
int addBefore(const char* newVal, const char* existingVal, struct LinkedList* list)
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
			list->count++;
			return 1;
	       }
	       nextNode = nextNode->next;
       }	
       return 0; 
}

/*Function to Add new node ater a given value*/
int addAfter(const char* newVal, const char* existingVal, struct LinkedList* list)
{
	struct node* newNode = _newNode();
	strcpy(newNode->val, newVal);
	struct node* nextNode = list->head->next;
       	while(nextNode)
       	{
	       if(strcmp(nextNode->val, existingVal) == 0)
	       {
			struct node* temp = nextNode->next;
			nextNode->next = newNode;
			newNode->next = temp;
			list->count++;
			return 1;
	       }
	       nextNode = nextNode->next;
       	}	
       	return 0; 
}

/*Function to Remove node for a given value*/ 
int removeNode(const char* val, struct LinkedList* list)
{
	struct node* nextNode = list->head->next;
	struct node* prevNode = list->head;
       	while(nextNode)
       	{
	       if(strcmp(nextNode->val, val) == 0)
	       {
			struct node* temp = nextNode;
			prevNode->next = nextNode->next;
			free(temp);
			list->count--;
			return 1;
	       }
	       prevNode = nextNode;
	       nextNode = nextNode->next;
       	}	
       	return 0;
}

/*Function to get length of list*/
int getLength(struct LinkedList* list)
{
	return list->count;
}

/*Function for Iteration over linked list*/
int hasNext(struct Iterator* iter)
{
	if(iter->cur->next == NULL)
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

/*Function to reverse List*/
void reverseList(struct LinkedList* list)
{
	struct node* nextNode = list->head->next;
	struct node* reversedList = NULL;
	struct node* temp = NULL;
	while(nextNode)
	{
		temp = nextNode->next;
		nextNode->next = reversedList;
		reversedList = nextNode;
		nextNode = temp;
	}
	list->head->next = reversedList;

}

/*Function to Print List*/
void printList(struct LinkedList* list)
{
	struct node* nextNode = list->head->next;
	while(nextNode)
	{
		printf("Val: %s\n", nextNode->val);
		nextNode = nextNode->next;
	}

}

/*Function to free List*/
void freeList(struct LinkedList* list)
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
