#include <cstdio>
#include <vector>
using namespace std;

int dfs (int);
void clearData (int);

vector<int> list[1001];
bool visited[1001];

int main (void) {
	int t, n, v, cnt;

	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int u = 1; u <= n; ++ u) {
			scanf("%d", &v);
			list[u].push_back(v);
		}
		cnt = 0;
		for (int i = 1; i <= n; ++ i) {
			if (!visited[i]) {
				if (i == dfs(i)) cnt ++;
			}
		} printf("%d\n", cnt);
		clearData(n);
	}

	return 0;
}

int dfs (int v) {
	if (!visited[list[v][0]]) {
		visited[list[v][0]] = true;
		return dfs(list[v][0]);
	} return v;
}
void clearData (int n) {
	for (int i = 1; i <= 1000; ++ i) {
		list[i].clear();
		visited[i] = false;
	}
}