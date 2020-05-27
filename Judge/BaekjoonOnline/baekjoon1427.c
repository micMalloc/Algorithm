#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 11

int descending (const void *n1, const void *n2)
{
	if (*(char*)n1 < *(char*)n2)
		return 1;
	else if (*(char*)n1 < *(char*)n2)
		return -1;
	else
		return 0;
}


int main (void)
{
	char nums[MAXSIZE];

	gets(nums);

	qsort(nums, strlen(nums), sizeof(char), descending);

	puts(nums);

	return 0;
}