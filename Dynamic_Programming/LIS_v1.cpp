#include <cstdio>
#define MAX 101
using namespace std;

int LIS (int, int[MAX]);

int dp[MAX];

int main (int argc, char** argv) {
	int list[MAX], n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", list + i);
	}

	printf("%d\n", LIS(n, list));

	return 0;
}
/* Implement LIS algo by using nested-loop */
int LIS (int n, int list[]) {
	int max;

	for (int i = 0; i < n; ++ i) {
		dp[i] = 1;
	}

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < i; ++ j) {
			if (list[j] < list[i]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}

	max = dp[0];
	for (int i = 1; i < n; ++ i) {
		if (max < dp[i]) {
			max = dp[i];
		}
	} return max;
}