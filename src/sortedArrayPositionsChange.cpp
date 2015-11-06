/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int iterator1, iterator2 = -1, temp = -1;
	if (len<0 || Arr == NULL)
		return NULL;
	for (iterator1 = 0; iterator1 < len; iterator1++)
	{
		if (Arr[iterator1] > Arr[iterator1 + 1])
		{
			iterator2 = iterator1;
			break;
		}
	}
	for (iterator1 = iterator1 + 1; iterator1 < len; iterator1++)
	{
		if (Arr[iterator1] > Arr[iterator1 + 1])
		{
			temp = iterator1 + 1;
			break;
		}
	}
	if (temp != -1 && iterator2 != -1)
	{
		Arr[iterator2] += Arr[temp];
		Arr[temp] = Arr[iterator2] - Arr[temp];
		Arr[iterator2] -= Arr[temp];
	}
	return Arr;
}