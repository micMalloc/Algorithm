#include <cstdio>
#include <vector>
using namespace std;

int main (void) {
	vector<int> list;
	int n, m;

	scanf("%d %d", &m, &n);

	list.resize(n + 1);
	for (int i = 2; i <= n; ++ i) {
		list[i] = i;
	}

	for (int i = 2; i <= n; ++ i) {
		if (list[i] == 0) continue;

		for (int j = i + i; j <= n; j += i)
			list[j] = 0;
	}

	for (int i = m; i <= n; ++ i) {
		if (list[i]) printf("%d\n", list[i]);
	}

	return 0;
}