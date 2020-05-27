#include <stdio.h>
#include <string.h>

void mergeSort (int, int);
void merge (int, int);

char words[20000][51];
char* wordPtr[20000], *tmp[20000];
int n;


int main (void)
{
	int i;

	scanf("%d%*c", &n);
	for (i = 0; i < n; ++ i)
	{
		gets(words[i]);
		wordPtr[i] = words[i];
	} mergeSort(0, n - 1);

	for (i = 0; i < n; ++ i)
	{
		/* Jump Same Word */
		if (i > 0 && strcmp(wordPtr[i - 1], wordPtr[i]) == 0)
			continue;
		puts(wordPtr[i]);
	}

	return 0;
}

void mergeSort (int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort (start, mid);
		mergeSort (mid + 1, end);
		merge (start, end);
	}
}

void merge (int start, int end)
{
	int left, right, idx = 0, i;
	int mid = (start + end) / 2;

	left = start; right = mid + 1;
	while (left <= mid && right <= end)
	{
		if (strlen(wordPtr[left]) < strlen(wordPtr[right]))
			tmp[idx ++] = wordPtr[left ++];
		else if (strlen(wordPtr[left]) > strlen(wordPtr[right]))
			tmp[idx ++] = wordPtr[right ++];
		else
		{
			if (strcmp(wordPtr[left], wordPtr[right]) < 0)
				tmp[idx ++] = wordPtr[left ++];
			else
				tmp[idx ++] = wordPtr[right ++];
		}
	}

	while (left <= mid)
		tmp[idx ++] = wordPtr[left ++];
	while (right <= end)
		tmp[idx ++] = wordPtr[right ++];

	for (i = 0; i < idx; ++ i)
		wordPtr[i + start] = tmp[i];
}