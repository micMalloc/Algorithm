#include <cstdio>
#include <cstring>

int memo[12];

int main (void) {
	int n, t;
	
	scanf("%d", &t);
	while (t --) {
		memset(memo, 0, 12 * sizeof(int));
		scanf("%d", &n);
		memo[0] = 1;
		for (int i = 1; i <= n; ++ i) {
			memo[i] += memo[i - 1];
			if (i >= 2) memo[i] += memo[i - 2];
			if (i >= 3) memo[i] += memo[i - 3];
		} printf("%d\n", memo[n]);
	}
	return 0;
}