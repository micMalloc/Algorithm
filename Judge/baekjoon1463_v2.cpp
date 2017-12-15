#include <cstdio>

const int MAX = 1000001;

int memo[MAX];

int main (void) {
	int n;

	scanf("%d", &n);
	
	for (int i = 2; i <= n; ++ i) {
		memo[i] = memo[i - 1] + 1;
		if (i % 2 == 0 && memo[i] > memo[i / 2] + 1)
			memo[i] = memo[i / 2] + 1;
		if (i % 3 == 0 && memo[i] > memo[i / 3] + 1)
			memo[i] = memo[i / 3] + 1;
	} printf("%d\n", memo[n]);

	return 0;
}