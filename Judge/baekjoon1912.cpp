#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100000;

int main (void) {
	int n;
	int memo[MAX], list[MAX];

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &list[i]);
	memo[0] = list[0];
	for (int i = 1; i < n; ++ i) memo[i] = max(memo[i - 1] + list[i], list[i]);
	
	int max = memo[0];
	for (int i = 1; i < n; ++ i) {
		if (max < memo[i]) max = memo[i];
	} printf("%d\n", max);

	return 0;
}