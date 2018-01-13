#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void topological_sort (int);

vector<vector<int> > adj;
vector<int> degree;
queue<int> q;

int main () {
	int n, m;
	int a, b;

	scanf("%d %d", &n, &m);
	
	adj.resize(n + 1);
	degree.resize(n + 1);
	for (int i = 0; i < m; ++ i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		degree[b] ++;
	}

	topological_sort(n);

	return 0;
}

void topological_sort (int n) {
	int u;

	for (int i = 1; i <= n; ++ i) {
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		u = q.front(); q.pop();
		printf("%d ", u);
		for (int v : adj[u]) {
			if (--degree[v] == 0) {
				q.push(v);
			}
		}
	} printf("\n");
}