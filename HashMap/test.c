/*File name: main.c
 * Author Name: Baljot Singh
 * Description: Test HashMap if _setNewSize works
 *               */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "HashMap.h"

int main()
{
	struct HashMap* map = NULL;  /*HashMap*/
	char word[50];
	char buffer[10];
	FILE *filePtr;
	int key = 0;

	filePtr = fopen("input.txt", "r");
	map = initHashMap(); /*Initialize HashMap*/
	
	/*Just to test HashMap if _setNewSize works*/
	if(filePtr)
	{
		while(fscanf(filePtr, "%s", word) != EOF)
		{
			snprintf(buffer, 15, "%d", key);
			put(buffer, word, map);
			key++;
		}
	}
	
	/*Print map*/
	printMap(map);

	/*Get total number of links*/
	printf("Links in map: %d\n", getSize(map));

	/*total number of words in input.txt*/
	printf("Num of words in input.txt: %d\n", key);

	/*Free map*/
	freeHashMap(map);

	/*Free filePtr*/
	fclose(filePtr);

	return 0;
}
