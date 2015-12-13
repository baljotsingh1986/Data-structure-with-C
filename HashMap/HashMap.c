/*File name: HashMap.c
 * Author Name: Baljot Singh
 * Description: Implementation of HashMap.h
 *               */

#include "LinkedList.h"
#include "HashMap.h"

int PRIME_ARR[5] = {149, 257, 439, 829, 1697}; /*Prime numbers for array size*/
int PRIME_ARR_SIZE = 5;
double LOAD_FACTOR = 0.75;

/*A strcut to define a HashMap*/
struct HashMap
{
	struct LinkedList** table; /*Dynamic array of pointers to struct LinkedList*/
	int size;  /*Size of array*/
	int links; /*Number of links*/
	int primeIndex; /*To get next prime number from PRIME_ARR when capacity is increased*/
};

/*Function to get hash index for key*/
int _hash(const char* key)
{
	int r = 0;
	int i = 0;
	while (key[i] != '\0')
	{
		r += (i+1)*(key[i]);
		i++;
	}
	return r;
}

/*Function to Initialize HashMap*/
struct HashMap* initHashMap()
{
	int i;
	struct HashMap* map = NULL;
	map = malloc(sizeof(struct HashMap));
	map->table = malloc(sizeof(struct LinkedList*)*PRIME_ARR[0]);
	map->size = PRIME_ARR[0];
	map->links = 0;
	map->primeIndex = 0;

	/*Initialize each index to NULL*/
	for ( i = 0; i < map->size; i++)
	{
		map->table[i] = NULL;
	}
	return map;
}

/*Initialize HashMap with capacity as argument*/
struct HashMap* _initHashMap(int cap)
{
	int i;
	struct HashMap* map = NULL;
	map = malloc(sizeof(struct HashMap));
	map->table = malloc(sizeof(struct LinkedList*)*cap);
	map->size = cap;
	map->links = 0;
	for ( i = 0; i < map->size; i++)
	{
		map->table[i] = NULL;
	}
	return map;
}

/*Helper function to insert new entry into map*/
int _insert(const char* key, const char* val, struct HashMap* map)
{
	int hash = (int)(_hash(key)%map->size);

	if (!map->table[hash])
	{
		map->table[hash] = initLinkedList(); /*Set index to new list*/
		addFront(key, val, map->table[hash]);
		map->links++;
		return 1;
	}

	else
	{
		/*Check if key is already there*/
		if (contains(key, map->table[hash]))
		{
			printf("key is here\n");
			return 0;
		}

		addFront(key, val, map->table[hash]);
		map->links++;
		return 1;
	}
}

/*Function to Deallocate memory*/
void freeHashMap(struct HashMap* map)
{
	int i;
	for ( i = 0; i < map->size; i++)
	{
		if (map->table[i])
		{
			freeList(map->table[i]);
		}
	}
	free(map->table);
	map->table = NULL;
	free(map);
	map = NULL;
}

/*Funtion to Set new size for array when capacity is increased*/
void _setNewSize(struct HashMap* map, int newSize)
{
	int i;
	struct HashMap* newMap = NULL;
	struct LinkedList* list = NULL;
	struct Iterator* iter = NULL;
	char key [50];
	char val [50];
	newMap = _initHashMap(newSize);
	for (i = 0; i < map->size; i++)
	{
		if(map->table[i])
		{
			list = map->table[i];
			iter = initIterator(list);
			while(hasNext(iter))
			{
				strcpy(key, nextKey(iter));
				strcpy(val, nextVal(iter));
				_insert(key, val, newMap);
			}

		}
	}
	for (i = 0; i < map->size; i++) 
	{
		if(map->table[i])
		{
			freeList(map->table[i]);
		}
       	}
	free(map->table);
	map->table = NULL;
	map->table = newMap->table;
	map->size = newSize;
	map->links = newMap->links;
	free(newMap);
}

/*Function To put new entry to map*/
int put(const char* key, const char* val, struct HashMap* map)
{
	if (map->links/(double)map->size >= LOAD_FACTOR)
	{
		map->primeIndex++;
		if (map->primeIndex < PRIME_ARR_SIZE)
		{
			int newSize = PRIME_ARR[map->primeIndex];
			_setNewSize(map, newSize);
		}
	}
	if(_insert(key, val, map))
	{
		return 1;
	}

	return 0;
}

/*Function to Print key and values*/
void printMap(struct HashMap* map)
{
	int i;
	char key [50];
	char val [50];
	struct Iterator* iter = NULL;
	struct LinkedList* list = NULL;
	for(i = 0; i < map->size; i++)
	{
		if(map->table[i])
		{
			printf("Index: %d\n", i);
			list = map->table[i];
			iter = initIterator(list);
			while(hasNext(iter))
			{
				strcpy(key, nextKey(iter));
				strcpy(val, nextVal(iter));
				printf("key: %s, Value: %s\n", key, val);
			}
		}
	}
}

/*Function To check if a key is present*/
int containKey(const char* key, struct HashMap* map)
{
	int hash = (int)(_hash(key)%map->size);
	if(map->table[hash])
	{
		if(contains(key, map->table[hash]))
		{
			return (hash + 1);
		}
	}
	return 0;
}

/*Function to Remove a key from hashmap*/
int removeKey(const char* key, struct HashMap* map)
{
	int index = containKey(key, map);
	if(index)
	{
		removeNode(key, map->table[index - 1]);
		map->links--;
		if(getLength(map->table[index - 1]) == 0)
		{
			freeList(map->table[index - 1]);
			map->table[index - 1] = NULL;
		}
		return 1;
	}
	return 0;
}

/*Function to get value for a given key*/
char* getValue(const char* key, struct HashMap* map)
{
	int hash = (int)(_hash(key)%map->size);
	char keyy[50];
	char *val;
	struct Iterator* iter = NULL;
	struct LinkedList* list = NULL;

	if(map->table[hash])
	{
		list = map->table[hash];
		iter = initIterator(list);
		while(hasNext(iter))
		{
			strcpy(keyy, nextKey(iter));
			if(strcmp(key, keyy) == 0)
			{
				val = nextVal(iter);
				free(iter);
				return val;
			}
		}
	}

	return NULL;
}

/*Function to return size of map*/
int getSize(struct HashMap* map)
{
	return map->links;
}
