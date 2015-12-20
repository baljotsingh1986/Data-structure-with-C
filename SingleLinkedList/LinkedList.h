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

void addFront(const char* val, struct LinkedList* list);

void printList(struct LinkedList* list);

void addLast(const char* val, struct LinkedList* list);

int addBefore(const char* newVal, const char* existingVal, struct LinkedList* list);

int addAfter(const char* newVal, const char* existingVal, struct LinkedList* list);

int removeNode(const char* val, struct LinkedList* list);

int getLength(struct LinkedList* list);

void reverseList(struct LinkedList* list);

int hasNext(struct Iterator* iter);

char* next(struct Iterator* iter);

void freeList(struct LinkedList* list);

#endif
