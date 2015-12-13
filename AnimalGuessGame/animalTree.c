/* CS261- animalTree.c*/
/* Name: Baljot Singh
* Date: 5/09/2015
* Solution description: This program implements the animalTree.h It uses
* 						tree structure for implementation.
*/

/*#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"animalTree.h"

struct node
{
	char data[256];
	struct node* left;
	struct node* right;
};

struct aTree
{
	struct node* root;
	struct node* cur;
};

/*  Helper function to add  new node to left of the tree.

param: 	new string to assign to data and current node
pre:	node not null
post:	a new node with the new string
*/
struct node* _addLeft(struct node* cur, char str[])
{
	assert(cur != NULL);
	struct node* newNode;
	if (cur->left == NULL)
	{
		newNode = malloc(sizeof(struct node));
		assert(newNode != NULL);
		strcpy(newNode->data, str);
		newNode->left = newNode->right = 0;
		return newNode;
	}

	else
	{
		cur->left = _addLeft(cur->left, str);
	}
	return cur;
}

/* Helper function to add new node to right of the tree.

param: 	new string to assign to data and current node
pre:	node not null
post:	a new node with the new string
*/
struct node* _addRight(struct node* cur, char str[])
{
	assert(cur != NULL);
	struct node* newNode;
	if (cur->right == NULL)
	{
		newNode = malloc(sizeof(struct node));
		assert(newNode != NULL);
		strcpy(newNode->data, str);
		newNode->left = newNode->right = 0;
		return newNode;
	}

	else
	{
		cur->right = _addRight(cur->right, str);
	}
	return cur;
}

/* Add a new node at particular location to left.

param: 	new string to assign to data and current node
pre:	none
post:	a new node with the new string
*/
void _addLeftNode(struct node* n, char str[], char str1[])
{
	if (n == NULL)
	{
		return;
	}
	if (strcmp(n->data, str1) == 0)
	{
		n->left = _addLeft(n, str);
		//return;
	}

	_addLeftNode(n->left, str, str1);
	_addLeftNode(n->right, str, str1);
}

/* Add a new node at particular location to right.

param: 	new string to assign to data and current node
pre:	none
post:	a new node with the new string
*/
void _addRightNode(struct node* n, char str[], char str1[])
{
	if (n == NULL)
	{
		return;
	}
	if (strcmp(n->data, str1) == 0)
	{
		n->right = _addRight(n, str);
	}
	_addRightNode(n->left, str, str1);
	_addRightNode(n->right, str, str1);
}

/* To add root node.

param: 	new string to assign to data and current node
pre:	tree is not null
post:	a new node with the new string
*/
void _addRoot(struct aTree* tree, char str[])
{
	assert(tree != NULL);
	tree->root = malloc(sizeof(struct node));
	assert(tree->root != NULL);
	strcpy(tree->root->data, str);
	tree->root->left = NULL;
	tree->root->right = NULL;
}

/*
helper function to built a tree from file animal.txt
param: file
pre:  none
post: tree is built and returned
*/
struct node* _builtTree(FILE *fp)
{
	struct node* newNode = NULL;
	if (feof(fp))
	{
 		return newNode;
	}

	else if (fgetc(fp) == 'A')
	{
		newNode = malloc(sizeof(struct node));
		assert(newNode != NULL);

		fgets(newNode->data, 256, fp);
		newNode->left = NULL;
		newNode->right = NULL;
	}

	else
	{
		newNode = malloc(sizeof(struct node));
		assert(newNode != NULL);

		fgets(newNode->data, 256, fp);
		newNode->left = _builtTree(fp);
		newNode->right = _builtTree(fp);
	}

	return newNode;
}

/* Initialize tree with some animals.

param: 	None
pre:	None
post:	A tree is built
*/
struct aTree* iniTree()
{
	struct aTree* tree = malloc(sizeof(struct aTree));
	assert(tree != NULL);
	FILE *f;
	f = fopen("animal.txt", "r");

	if(f == NULL)
	{
		printf("File animal.txt is missing or corrupted.\n");

		exit(0);
	}

	/*If animal.txt file gets deleted, changed or corrupted accidently
	  Uncomment the following block of code and comment out the _builTree function call*/

	/*_addRoot(tree, "Does it live in water?\n");

	_addRightNode(tree->root, "Is it lazy sometimes?\n", "Does it live in water?\n");
	_addLeftNode(tree->root, "Deos it climb trees?\n", "Does it live in water?\n");
	_addRightNode(tree->root, "Does it jump from tree to tree?\n", "Deos it climb trees?\n");
	_addRightNode(tree->root, "Does it live inside tree?\n", "Does it jump from tree to tree?\n");
	_addRightNode(tree->root, "Squirrel\n", "Does it live inside tree?\n");
	_addLeftNode(tree->root, "Monkey\n", "Does it live inside tree?\n");
	_addLeftNode(tree->root, "It has stripes?\n", "Does it jump from tree to tree?\n");
	_addLeftNode(tree->root, "Lion\n", "It has stripes?\n");
	_addRightNode(tree->root, "Tiger\n", "It has stripes?\n");
	_addLeftNode(tree->root, "Does it eat grass?\n", "Deos it climb trees?\n");
	_addRightNode(tree->root, "It has long neck?\n", "Does it eat grass?\n");
	_addRightNode(tree->root, "Giraffe\n", "It has long neck?\n");
	_addLeftNode(tree->root, "Zebra\n", "It has long neck?\n");
	_addLeftNode(tree->root, "Does it look like small tiger?\n", "Does it eat grass?\n");
	_addLeftNode(tree->root, "Dog\n", "Does it look like small tiger?\n");
	_addRightNode(tree->root, "Cat\n", "Does it look like small tiger?\n");
	_addRightNode(tree->root, "Does it has hard body?\n", "Is it lazy sometimes?\n");
	_addRightNode(tree->root, "It has long tail?\n", "Does it has hard body?\n");
	_addLeftNode(tree->root, "Turtle\n", "It has long tail?\n");
	_addRightNode(tree->root, "Crocodile\n", "It has long tail?\n");
	_addLeftNode(tree->root, "Does it jump?\n", "Does it has hard body?\n");
	_addLeftNode(tree->root, "Slug\n", "Does it jump?\n");
	_addRightNode(tree->root, "Frog\n", "Does it jump?\n");
	_addLeftNode(tree->root, "Is it very good at hunting?\n", "Is it lazy sometimes?\n");
	_addRightNode(tree->root, "Does it attack in group?\n", "Is it very good at hunting?\n");
	_addRightNode(tree->root, "Piranha\n", "Does it attack in group?\n");
	_addLeftNode(tree->root, "Shark\n", "Does it attack in group?\n");
	_addLeftNode(tree->root, "Is it bigger than Elephant\n", "Is it very good at hunting?\n");
	_addRightNode(tree->root, "Whale\n", "Is it bigger than Elephant\n");
	_addLeftNode(tree->root, "Cute Fish\n", "Is it bigger than Elephant\n");*/
	
	tree->root = _builtTree(f);
	return tree;
}

/* To display the current question and move to next child.

param: 	struct tree and string yes or no
pre:	tree is not null
post:	cur is moved to next child
*/
void displayData(struct aTree* tree, char str[])
{
	assert(tree != NULL);

	if (strcmp(str, "yes") == 0)
	{
		if (tree->cur->right != NULL)
		{
			tree->cur = tree->cur->right;
		}
		printf("%s", tree->cur->data);

	}

	else if (strcmp(str, "no") == 0)
	{
		if (tree->cur->left != NULL)
		{
			tree->cur = tree->cur->left;
		}
		printf("%s", tree->cur->data);

	}

	else if (tree->cur == tree->root)
	{
		printf("%s", tree->cur->data);
	}
}

/* To reset the cur to begining

param: 	struct tree
pre:	tree is not null
post:	cur is set to root
*/
void resetTree(struct aTree* tree)
{
	assert(tree != NULL);
	tree->cur = tree->root;
}

/* To add new animal by user

param: 	struct tree, question, name of animal and answer
pre:	tree is not null, cur is not NULL cur->left == NULL cur->right == NULL
post:	A new question and animal is added to tree
*/
void addNewAnimal(struct aTree* tree, char str[], char str1[], char str2[])
{
	assert(tree != NULL);
	assert(tree->cur != NULL);
	assert(tree->cur->left == NULL);
	assert(tree->cur->right == NULL);

	/*Copy the old animal to swap*/
	char oldAnimal[80];
	strcpy(oldAnimal, tree->cur->data);
	strcpy(tree->cur->data, str);

	if (strcmp(str2, "yes") == 0)
	{
		tree->cur->right = _addRight(tree->cur, str1);
		tree->cur->left = _addLeft(tree->cur, oldAnimal);
	}

	else if (strcmp(str2, "no") == 0)
	{
		tree->cur->left = _addLeft(tree->cur, str1);
		tree->cur->right = _addRight(tree->cur, oldAnimal);
	}

}

/* To check if tree is ended

param: 	struct tree
pre:	tree is not null, cur is not NULL
post:	NONE
*/
int hasNext(struct aTree* tree)
{
	assert(tree != NULL);
	assert(tree->cur != NULL);

	if (tree->cur->left == NULL)
	{
		return 0;
	}

	else if (tree->cur->right == NULL)
	{
		return 0;
	}

	return 1;
}

/*
function to free the nodes of tree
param: node  the root node of the tree to be freed
pre: none
post: node and all descendants are deallocated
*/

void _freeTree(struct node *n)
{
	if (n != 0)
	{
		_freeTree(n->left);
		_freeTree(n->right);
		free(n);
	}
}

/*
function to deallocate a dynamically allocated tree
param: tree
pre: tree != null;
post: all nodes and the tree structure itself are deallocated.
*/
void deleteTree(struct aTree *tree)
{
	assert(tree != NULL);
	_freeTree(tree->root);
	free(tree);
}

/*
helper function to copy a tree to file
param: node
pre:  none
post: all nodes are copy to file animal.txt in preorder
*/
void _copyTree(struct node* n, FILE *file)
{
	if (n == NULL)
	{
		return;
	}

	else if (n->left == NULL && n->right == NULL)
	{
		fputc('A', file);
		fputs(n->data, file);
	}

	else
	{
		fputc('Q', file);
		fputs(n->data, file);
	}
	_copyTree(n->left, file);
	_copyTree(n->right, file);
}

/*
function to copy a tree to file
param: tree
pre: tree != null;
post: all nodes are copy to file animal.txt in preorder
*/
void copyTree(struct aTree* tree)
{
	assert(tree != NULL);

	FILE *fp;
	fp = fopen("animal.txt", "w");
	_copyTree(tree->root, fp);
	fclose(fp);
}
