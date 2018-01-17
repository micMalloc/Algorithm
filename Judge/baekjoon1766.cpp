#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

/* Using In-Degree based on BFS */
void topological_sort (int);

vector<vector<int> > adj;
vector<int> indegree;

int main (int argc, char** argv) {
	int n, m;	
	int a, b;

	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	indegree.resize(n + 1);

	for (int i = 0; i < m; ++ i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		indegree[b] ++;
	}
	topological_sort(n);

	return 0;
}

void topological_sort (int n) {
	int u;
	priority_queue<int, vector<int>, greater<int> > q;

	for (int v = 1; v <= n; ++ v) {
		if (indegree[v] == 0) {
			q.push(v);
		}
	}

	while (!q.empty()) {
		u = q.top(); q.pop();
		printf("%d ", u);
		for (int v : adj[u]) {
			if (-- indegree[v] == 0) {
				q.push(v);
			}
		}
	} printf("\n");
}