/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int iterator, temp1, temp2;
	if (len<0 || Arr == NULL)
		return NULL;
	for (iterator = 0; iterator < len; iterator++)
	{
		if (Arr[iterator] > num)
			break;
	}
	temp1 = Arr[iterator];
	Arr[iterator] = num;
	for (iterator = iterator + 1; iterator <= len; iterator++)
	{
		temp2 = Arr[iterator];
		Arr[iterator] = temp1;
		temp1 = temp2;
	}
	return Arr;
}