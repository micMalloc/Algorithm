#include <cstdio>
#define MAX 100

void selectionSort (int[MAX], int);

int main (void) {
	int i;
	int list[MAX], n;

	scanf("%d", &n);
	for (i = 0; i < n; ++ i) scanf("%d", &list[i]);
	selectionSort(list, n);
	for (i = 0; i < n; ++ i) printf("%d ", list[i]);

	return 0;
}

void selectionSort (int list[], int n) {
	int min, tmp, i, j;
	//Ascending Order
	for (i = 0; i < (n - 1); ++ i) {
		min = i;
		for (j = i + 1; j < n; ++ j) {
			if (list[min] > list[j]) min = j;
		}
		tmp = list[i];
		list[i] = list[min];
		list[min] = tmp;
	}
}