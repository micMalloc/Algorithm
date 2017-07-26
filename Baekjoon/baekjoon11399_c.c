#include <stdio.h>
#define MAX 1001

void mergeSort(int, int);
void merge(int, int);

struct PERSON
{
	int need;
	int wait;
};
typedef struct PERSON Person;
Person p[MAX];
Person s[MAX];

int n, top = -1;

int main (void)
{
	/*int i, j, total = 0;

	scanf("%d", &n);
	for (i = 0; i < n; ++ i)
	{
		scanf("%d", &p[i].need);
		p[i].wait = 0;
	} mergeSort(0, n - 1);

	for (i = 0; i < n; ++ i)
	{
		for (j = i; j < n; ++ j)
			p[j].wait += p[i].need;
	}
	for (i = 0; i < n; ++ i)
		total += p[i].wait;
	printf("%d", total);*/


	return 0;
}

void mergeSort(int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, end);
	}
}
void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int left, right, idx = 0, i;

	left = start; right = mid + 1;
	while (left <= mid && right <= end)
	{
		if (p[left].need < p[right].need)
			s[idx ++] = p[left ++];
		else
			s[idx ++] = p[right ++];
	}

	while (left <= mid)
		s[idx ++] = p[left ++];
	while (right <= end)
		s[idx ++] = p[right ++];

	for (i = 0; i < idx; ++ i)
		p[start + i] = s[i];
}