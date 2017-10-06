#include <cstdio>
#define MAX 100

//Prototype
void mergeSort (int, int);
void merge (int, int);

int list[MAX];
//Temporary Space for storing intermediate result
int tmp_list[MAX];

int main (void) {
	int n; // Size of a list

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &list[i]);
	
	mergeSort(0, n - 1);

	/* Print the list sorted by merge sort */
	for (int i = 0; i < n; ++ i) printf("%d ", list[i]);

	return 0;
}

void mergeSort (int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		/* Devide and Coquer */
		mergeSort (start, mid);
		mergeSort (mid + 1, end);
		merge (start, end);
	}
}

void merge (int start, int end) {
	int mid = (start + end) / 2;
	int left, right, idx = 0;

	left = start; right = mid + 1;
	while (left <= mid && right <= end) {
		if (list[left] < list[right]) {
			tmp_list[idx ++] = list[left ++];
		} else {
			tmp_list[idx ++] = list[right ++];
		}
	}

	while (left <= mid) tmp_list[idx ++] = list[left ++];
	while (right <= end) tmp_list[idx ++] = list[right ++];

	for (int i = 0; i < idx; ++ i)
		list[start + i] = tmp_list[i];
}