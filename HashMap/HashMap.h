/*File name: HashMap.h
 * Author Name: Baljot Singh
 * Description: Header file for interface of HashMap
 *               data structure
 *               */


#ifndef HASHMAP_H
#define HASHMAP_H

struct HashMap;

struct HashMap* initHashMap();

int put(const char* key, const char* val, struct HashMap* map);
void printMap(struct HashMap* map);
int removeKey(const char* key, struct HashMap* map);
int containKey(const char* key, struct HashMap* map);
char* getValue(const char* key, struct HashMap* map);
int getSize(struct HashMap* map);

void freeHashMap(struct HashMap* map);

#endif
