/*File name: Heap.h
 * Author: Baljot Singh
 * Description:Header file for Interface for
 *             Heap(min-Heap) data structure
 *             */

#include<stdio.h>
#include<stdlib.h>

#include "Type.h"

#ifndef HEAP_H
#define HEAP_H

struct Heap;
struct Heap* initHeap();
void insert(TYPE val, struct Heap* minHeap);
TYPE removeMin(struct Heap* minHeap);
int isEmpty(struct Heap* minHeap);
void printHeap(struct Heap* heap);
void freeHeap(struct Heap* heap);
void heapSort(TYPE* arr, int size);
void reverseArray(TYPE* arr, int size);

#endif
