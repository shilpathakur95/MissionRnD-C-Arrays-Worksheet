/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	int iterator, iterator2, iterator3;
	if (len < 0 || Arr == NULL)
		return NULL;
	for (iterator = 0; iterator < len; iterator++)
	{
		for (iterator2 = iterator + 1; iterator2 < len&&Arr[iterator2] != -1; iterator2++)
		{
			if (Arr[iterator2] == Arr[iterator])
			{
				for (iterator3 = iterator2; iterator3 < len; iterator3++)
				{
					Arr[iterator3] = Arr[iterator3 + 1];
				}
			}
		}
	}
}