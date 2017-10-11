#include <cstdio>
#define MAX  100

void quickSort (int, int);
int partition (int, int);
void swap (int, int);

int list[MAX];

int main (void) {
	int n;

	return 0;
}

void quickSort (int start, int end) {
	int pivot;
	if (start < end) {
		pivot = partition (start, end);
		quickSort (start, pivot - 1);
		quickSort (pivot + 1, end);
	}
}

int partition (int start, int end) {
	int left, right;
	int pivot = list[end];

	left = start; right = end - 1;
	while (left < right) {
		
	}
}

void swap (int a, int b) {
	int tmp;

	tmp = list[a];
	list[a] = list[b];
	list[b] = tmp;
}