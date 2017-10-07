#include <cstdio>
#define MAX 100

void insertion (int);
void insertionSort(int, int);

int list[MAX];

int main (void) {
	int n, num;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &list[i]);
		//insertionSort(i, num);
	} insertion (n);

	for (int i = 0; i < n; ++ i) printf("%d ", list[i]);

	return 0;
}

void insertion (int n) {
	int i, j, key;

	for (i = 1; i < n; ++ i) {
		key = list[i];
		j = i - 1;

		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			j --;
		} list[j + 1] = key;
	}
}

void insertionSort (int idx, int key) {
	int position, i;

	/* Search for the correct position for a new key to be inserted into the list */
	for (i = 0; i <= idx; ++ i) {
		if (list[i] > key) {
			i ++;
			break;
		}
	} position = i - 1;
	/* Move the bigger keys on the current sorted list to make room for a new key */
	/* Insert the new key into the room */
	for (i = idx; i >= position; -- i) {
		list[i + 1] = list[i];
	} list[position] = key;
}