/*File name: LinkedList.c
 * Author Name: Baljot Singh
 * Description: Implementation of file LinkedList.h
 *               */

#include "LinkedList.h"

/*A strcut to define a node of linked list*/
struct node
{
	char val [50];
	char key [50];
	struct node* next;
};


/*Struct to make a list of nodes and count it*/
struct LinkedList
{
	struct node* head;
	int count;
};

/*Struct to make a list of nodes and count it*/
struct Iterator
{
	struct node* cur;
};

/*Helper function ro Build a new Node*/
struct node* _newNode()
{
	struct node* newNode  = malloc(sizeof(struct node));
	newNode->next = NULL;
	return newNode;
}

/*Function to Initialize linked list*/
struct LinkedList* initLinkedList()
{
	struct LinkedList* list = NULL;
	list = malloc(sizeof(struct LinkedList));
	list->head = _newNode();
	list->count = 0;
	return list;
}

/*Function to initialize Iterator*/
struct Iterator* initIterator(struct LinkedList* list)
{
	struct Iterator* iter = malloc(sizeof(struct Iterator));
	iter->cur = list->head;
	return iter; 
}

/*Function to Add new node at front*/
void addFront(const char* key, const char* val, struct LinkedList* list)
{
	struct node* newNode = _newNode();
	strcpy(newNode->val, val);
	strcpy(newNode->key, key);
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->count++;
}


/*Function to Remove node*/
int removeNode(const char* key, struct LinkedList* list)
{
	struct node* nextNode = list->head->next;
	struct node* prevNode = list->head;
       	while(nextNode)
       	{
	       if(strcmp(nextNode->key, key) == 0)
	       {
			struct node* temp = nextNode;
			prevNode->next = nextNode->next;
			free(temp);
			temp = NULL;
			list->count--;
			return 1;
	       }
	       prevNode = nextNode;
	       nextNode = nextNode->next;
       	}	
       	return 0;
}

/*Function To check if key is already there*/ 
int contains(const char* key, struct LinkedList* list)
{
	struct node* nextNode = list->head->next;
       	while(nextNode)
       	{
	       if(strcmp(nextNode->key, key) == 0)
	       {
			return 1;
	       }
	       nextNode = nextNode->next;
       	}	
       	return 0;
}

/*Function to get length of list*/
int getLength(struct LinkedList* list)
{
	return list->count;
}

/*Function to use Iterator for Iteration over linked list*/
int hasNext(struct Iterator* iter)
{
	if(iter->cur->next == NULL)
	{
		free(iter);
		iter = NULL;
		return 0;
	}
	return 1;
}

/*Function to Return the value*/
char* nextVal(struct Iterator* iter)
{
	return iter->cur->val;
}

/*Function to Return the key and move iterator to next node*/
char* nextKey(struct Iterator* iter)
{
	iter->cur = iter->cur->next;
	return iter->cur->key;
}

/*Function to Print List*/
void printList(struct LinkedList* list)
{
	struct node* nextNode = list->head->next;
	while(nextNode)
	{
		printf("Key: %s ,", nextNode->key);
		printf("Val: %s\n", nextNode->val);
		nextNode = nextNode->next;
	}

}

/*Function to deallocate memory for list*/
void freeList(struct LinkedList* list)
{
	struct node* nextNode = list->head->next;
	while(nextNode)
	{
		struct node* temp = nextNode;
		nextNode = nextNode->next;
		free(temp);
		temp = NULL;
	}

	free(list->head);
	list->head = NULL;
	free(list);
	list = NULL;
}

