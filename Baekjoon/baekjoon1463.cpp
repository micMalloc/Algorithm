#include <cstdio>

int walk (int);

const int MAX = 1000001;

int memo[MAX];

int main (void) {
	int n;

	scanf("%d", &n);
	printf("%d\n", walk(n));

	return 0;
}

int walk (int n) {
	if (n == 1) return 0;
	if (memo[n] > 0) return memo[n];
	
	memo[n] = walk(n - 1) + 1;
	if (n % 2 == 0) {
		int tmp = walk(n / 2) + 1;
		if (memo[n] > tmp) memo[n] = tmp;
	}
	if (n % 3 == 0) {
		int tmp = walk(n / 3) + 1;
		if (memo[n] > tmp) memo[n] = tmp;
	}
	return memo[n];
}