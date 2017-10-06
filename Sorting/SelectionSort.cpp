#include <cstdio>
#define MAX 100

void selectionSort (int[MAX], int);
void swap (int[MAX], int, int);

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
		if (i != min) swap(list, i, min)
	}
}
void swap (int list[], int a, int b) {
	int tmp;

	tmp = list[a];
	list[a] = list[b];
	list[b] = tmp;
}
