/*File name: main.c
 * Author Name: Baljot Singh
 * Description: Use of HashMap
 *               */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "HashMap.h"

int main()
{
	struct HashMap* map = NULL;  /*HashMap*/

	map = initHashMap(); /*Initialize HashMap*/
	
	/*Make enteries to HashMap*/
	put("Name1", "Baljot", map);
	put("Name2", "Baljot", map);

	/*Get total number of values*/
	printf("Links in map: %d\n", getSize(map));

	/*Test Contain Function*/
	if(containKey("Name1", map))
	{
		printf("Name1 is there.\n");
	}

	if(containKey("Name2", map))
	{
		printf("Name2 is there.\n");
	}
	
	if(!containKey("Nam", map))
	{
		printf("Nam is not there.\n");
	}

	/*Try to enter duplicate key*/
	put("Name1", "Baljot", map);

	/*Remove key*/
	removeKey("Name1", map);
	
	/*Check Name1 is removed*/
	if(!containKey("Name1", map))
	{
		printf("Name1 is removed.\n");
	}

	/*print value of Name2*/
	printf("Value of Name2: %s\n", getValue("Name2", map));

	/*Try to get the value of key which is not present*/
	printf("Value of Name1: %s\n", getValue("Name1", map));

	/*Print map*/
	printMap(map);

	/*Get total number of values*/
	printf("Links in map: %d\n", getSize(map));

	/*Free map*/
	freeHashMap(map);

	return 0;
}
