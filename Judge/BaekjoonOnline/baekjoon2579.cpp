#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 301;

int memo[MAX][3];

int main (void) {
	int n;
	int stair[MAX];

	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", &stair[i]);

	memo[1][1] = stair[1];
	for (int i = 2; i <= n; ++ i) {
		memo[i][2] = memo[i - 1][1] + stair[i];
		memo[i][1] = max(memo[i - 2][1], memo[i - 2][2] + stair[i]);
	} printf("%d\n", max(memo[n][1], memo[n][2]));
	
	return 0;
}