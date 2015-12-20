/*File name: DoublyLinkedList.h
 * Author Name: Baljot Singh
 * Description: Header file for interface of DoublyLinkedList
 *               data structure
 *               */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct DoublyLinkedList;

struct Iterator;

struct DoublyLinkedList* initLinkedList();

struct Iterator* initIterator(struct DoublyLinkedList* list);

void addFront(const char* val, struct DoublyLinkedList* list);

char* getFront(struct DoublyLinkedList* list);

char* getLast(struct DoublyLinkedList* list);

int removeFront(struct DoublyLinkedList* list);

int removeLast(struct DoublyLinkedList* list);

void printList(struct DoublyLinkedList* list);

void addLast(const char* val, struct DoublyLinkedList* list);

int addBefore(const char* newVal, const char* existingVal, struct DoublyLinkedList* list);

int addAfter(const char* newVal, const char* existingVal, struct DoublyLinkedList* list);

int removeNode(const char* val, struct DoublyLinkedList* list);

int getLength(struct DoublyLinkedList* list);

int hasNext(struct Iterator* iter);

char* next(struct Iterator* iter);

void freeList(struct DoublyLinkedList* list);

void printListReverse(struct DoublyLinkedList* list);

#endif
