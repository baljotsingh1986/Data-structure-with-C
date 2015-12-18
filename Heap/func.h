/*File name: func.h
 * Author: Baljot Singh
 * Description:Header file to compare TYPE and print TYPE
 *             */

#include<stdio.h>
#include<stdlib.h>

#include "Type.h"

#ifndef FUNC_H
#define FUNC_H

int comparator(TYPE val1, TYPE val2)
{
	if (val1 >= val2)
	{
		return -1;
	}

	else
	{
		return 1;
	}
}

void printType(TYPE val)
{
	printf("val: %d\n", val);
}

#endif
