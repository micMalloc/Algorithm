#include <stdio.h>
#include <string.h>

void mergeSort (int, int);
void merge (int, int);

char list[1000][51], tmp[1000][51];
int count[1000];

int main (void) {
	int i, n;
	int check;
	char title[51];
	int max = 0;

	scanf("%d%*c", &n);
	for (i = 0; i < n; ++ i) {
		gets(list[i]); // O(n)
	} mergeSort (0, n - 1); // O(nlogn)
	
	check = 0;
	for (i = 1; i < n; ++ i) {
		if (strcmp(list[i - 1], list[i]) == 0)
			check ++;
		else {
			count[i - 1] = check + 1;
			check = 0;
		}
	} count[i - 1] = check + 1;

	for (i = 0; i < n; ++ i) {
		if (count[i] > max)
			max = count[i];
	}
	for (i = 0; i < n; ++ i) {
		if (count[i] == max) {
			puts(list[i]);
			break;
		}
	}

	return 0;
}

void mergeSort (int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		mergeSort (start, mid);
		mergeSort (mid + 1, end);
		merge(start, end);
	}
}

void merge (int start, int end) {
	int mid = (start + end) / 2;
	int left, right;
	int i, idx = 0;

	left = start; right = mid + 1;
	while (left <= mid && right <= end) {
		if (strcmp(list[left], list[right]) < 0)
			strcpy(tmp[idx ++], list[left ++]);
		else
			strcpy(tmp[idx ++], list[right ++]);
	}

	while (left <= mid)
		strcpy(tmp[idx ++], list[left ++]);
	while (right <= end)
		strcpy(tmp[idx ++], list[right ++]);
	for (i = 0; i < idx; ++ i)
		strcpy(list[i + start], tmp[i]);
}