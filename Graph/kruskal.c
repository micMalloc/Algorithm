#include <stdio.h>
#define MAX 100

typedef struct EDGE {
	int u;
	int v;
	int w;
} Edge;

void kruskal ();
void make_set ();
int find_set ();
void union_set ();
void mergeSort (int , int);
void merge (int, int);

Edge e[MAX], tmp[MAX];


int main (void) {

	return 0;
}

void kruskal () {
	
}

void make_set () {
	
}
int find_set () {

}
void union_set () {

}

void mergeSort (int start, int end) {
	int mid;

	if (start, end) {
		mid = (start + end) / 2;
		mergeSort (start, mid);
		mergeSort (mid + 1, end);
		merge (start, end);
	}
}

void merge (int start, int end) {
	int mid = (start + end) / 2;
	int left, right;
	int idx = 0, i;
	
	left = start; right = mid + 1;
	while (left <= mid && right <= end) {
		if (e[left].w < e[right].w) {
			tmp[idx ++] = e[left ++];
		} else {
			tmp[idx ++] = e[right ++];
		}
	}

	for (i = 0; i < idx; ++ i) {
		e[start + i] = tmp[i];
	}
}