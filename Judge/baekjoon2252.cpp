#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

void dfs (int);

vector<vector<int> > adj;
vector<bool> visited;
stack<int> s;

int main (int argc, char** argv) {
	int n, m;
	int a, b;
	
	scanf("%d %d", &n, &m);

	adj.resize(n + 1);
	visited.resize(n + 1);
	while (m --) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; ++ i) {
		if (!visited[i])
			dfs(i);
	}

	while (!s.empty()) {
		printf("%d ", s.top());
		s. pop();
	}

	return 0;
}

void dfs (int v) {
	visited[v] = true;

	for (int next : adj[v]) {
		if (!visited[next]) {
			dfs(next);
		}
	} s.push(v);
}