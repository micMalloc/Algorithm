#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX = 10000;

void distribution (int);
void find (int);

int chunk[MAX], tmp[MAX];

int main (void) {
	int t;
	
	scanf("%d", &t);
	while (t --) {
		int n;
		
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &chunk[i]);

		sort (chunk, chunk + n);
		
		distribution(n);
		find(n);
	}

	return 0;
}

void distribution (int n) {
	int check = 1;
	int left = 0, right = n - 1;

	while (check <= n) {
		if (check % 2) 
			tmp[left ++] = chunk[check - 1];
		else
			tmp[right --] = chunk[check - 1];
		check ++;
	}
}

void find (int n) {
	int max = 0;

	for (int i = 1; i < n; ++ i) {
		if (max < tmp[i] - tmp[i - 1])
			max = tmp[i] - tmp[i - 1];
	} printf("%d\n", max);
}