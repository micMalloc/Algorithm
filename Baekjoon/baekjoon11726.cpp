#include <cstdio>

const int MAX = 1001;

int memo[MAX];

int main (void) {
	int n;

	scanf("%d", &n);
	memo[0] = memo[1] = 1;
	for (int i = 2; i <= n; ++ i) {
		memo[i] = memo[i - 1] + memo[i - 2];
	} printf("%d\n", memo[n] % 10007);

	return 0;
}