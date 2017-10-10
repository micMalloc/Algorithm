#include <cstdio>
#define MAX 100

void quickSort (int[MAX], int, int);
int partition (int[MAX], int, int);
void swap (int*, int*);

int main (void) {
	int list[MAX], n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &list[i]);
	quickSort (list, 0, n - 1);

	for (int i = 0; i < n; ++ i) printf("%d ", list[i]);

	return 0;
}

/*
Description: Do partition and recursivly qucikSort
Input: List array, start, and end value
Output: None
*/
void quickSort (int list[], int start, int end) {
	int pivot;
	if (start < end) {
		pivot = partition (list, start, end);
		quickSort (list, start, pivot - 1);
		quickSort (list, pivot + 1, end);
	}
}

/*
Description: Select a pivot and Partition a list by the pivot
Input: list array, start, and end value of a list
Output: Proper pivot's index
*/
int partition (int list[], int start, int end) {
	int pivot = list[end];
	int i = start;

	for (int j = start; j < end; ++ j) {
		if (list[j] <= pivot) {
			swap (&list[i ++], &list[j]);
		}
	} swap (&list[i], &list[end]);
	return (i);
}

/*
Description: Swap a with b
Input: Address of two elements of a list
Output: None
*/
void swap (int* a, int* b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}