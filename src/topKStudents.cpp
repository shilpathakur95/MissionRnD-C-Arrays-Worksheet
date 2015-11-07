/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
struct student ** topKStudents(struct student *students, int len, int K) {
	int iterator, iterator2 = 0, max,temp;
	struct student **stud;
	stud = (struct student **)malloc(sizeof(struct student));
	if (len < 0 || students == NULL || K <= 0)
		return NULL;
	if (K > len)
		K = len;
	temp = 0;
	for (iterator = 1; iterator < len; iterator++)
	{
		if (students[iterator].score>students[temp].score)
			temp = iterator;
	}
	K--;
	stud[iterator2] = &students[temp];
	iterator2++;
	while (K > 0)
	{
		max = 0;
		for (iterator = 1; iterator < len; iterator++)
		{
			if ((students[temp].score - students[iterator].score<students[temp].score - students[max].score || students[temp].score - students[max].score <= 0) && (students[temp].score - students[iterator].score!=0))
				max = iterator;
		}
		K--;
		stud[iterator2] = &students[max];
		iterator2++;
		temp = max;
	}
	return stud;
}