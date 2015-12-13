/*File name: LinkedList.h
 * Author Name: Baljot Singh
 * Description: Header file for interface of linkedlist
 *               data structure
 *               */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct LinkedList;
struct Iterator;
struct LinkedList* initLinkedList();
struct Iterator* initIterator(struct LinkedList* list);
void addFront(const char* key, const char* val, struct LinkedList* list);
void printList(struct LinkedList* list);

int contains(const char* key, struct LinkedList* list);

int removeNode(const char* key, struct LinkedList* list);
int getLength(struct LinkedList* list);

int hasNext(struct Iterator* iter);
char* nextVal(struct Iterator* iter);
char* nextKey(struct Iterator* iter);
void freeList(struct LinkedList* list);

#endif
