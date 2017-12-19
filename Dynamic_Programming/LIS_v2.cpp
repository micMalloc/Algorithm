#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 1e9
using namespace std;

int LIS (int, int[MAX]);
vector<int> lis;

int main (int argc, char** argv) {
	int list[MAX], n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", list + i);
	}

	printf("%d\n", LIS(n, list));

	return 0;
}

// Implement LIS by using Binary Search
int LIS (int n, int list[]) {
	int max = 0;

	lis.push_back(-INF);
	for (int i = 0; i < n; ++ i) {
		if (lis.back() < list[i]) {
			lis.push_back(list[i]);
			max ++;
		} else {
			auto it = lower_bound(lis.begin(), lis.end(), list[i]);
			*it = list[i];
		}
	} return max;
}