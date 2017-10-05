#include <cstdio>
#define MAX 100

void bubbleSort (int[MAX], int);

int main (void) {
	int i;
	int list[MAX], n;

	scanf("%d", &n);
	for (i = 0; i < n; ++ i) scanf("%d", &list[i]);
	bubbleSort(list, n);
	for (i = 0; i < n; ++ i) printf("%d ", list[i]);

	return 0;
}

void bubbleSort (int list[], int n) {
	int tmp, i, j;

	for (i = 0; i < n - 1; ++ i) {
		for (j = 0; j < n - (i + 1); j ++) {
			if (list[j] > list[j + 1]) {
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
}
