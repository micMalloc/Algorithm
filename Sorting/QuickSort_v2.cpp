#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void quick_sort (int, int);
int partition (int, int);

vector<int> list;

int main (int argc, char** argv) {
	int n, key;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &key);
		list.push_back(key);
	}
	
	quick_sort(0, n - 1);
	for (int i = 0; i < n; ++ i) {
		printf("%d\n", list[i]);
	}

	return 0;
}

void quick_sort (int start, int end) {
	int pivot;

	if (start < end) {
		pivot = partition(start, end);
		quick_sort(start, pivot - 1);
		quick_sort(pivot + 1, end);
	}
}

int partition (int start, int end) {
	int pivot = end;
	int left = start, right = end;

	while (left < right) {
		while (list[left] < list[pivot] && left < right) {
			left ++;
		}
		while (list[right] >= list[pivot] && left < right) {
			right --;
		}
		if (left < right) {
			swap(list[left], list[right]);
		}
	} swap(list[pivot], list[right]);
	return right;
}

/*
void quick_sort (int, int);

vector<int> list;

int main (int argc, char** argv) {
	int n;
	int key;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &key);
		list.push_back(key);
	}
	quick_sort (0, n - 1);

	for (int i = 0; i < n; ++ i) {
		printf("%d ", list[i]);
	} printf("\n");

	return 0;
}

void quick_sort (int start, int end) {
	int pivot = list[start];
	int left, right;

	left = start; right = end;

	while (left < right) {
		while (pivot <= list[right] && left < right) right --;
		if (left > right) break;

		while (pivot >= list[left] && left < right) left ++;
		if (left > right) break;

		swap(list[left], list[right]);
	} swap(list[start], list[right]);

	if (start < left) {
		quick_sort(start, left - 1);
	}
	if (right < end) {
		quick_sort(right + 1, end);
	}
} */