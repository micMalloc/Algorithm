#include <cstdio>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

void SPFA (int, int);

typedef pair<int, int> Pair;

vector<vector<Pair>> adj;
vector<int> dist;

int main (int argc, char** argv) {
	int n, e;
	int u, v, c;
	int source;
	
	scanf("%d %d", &n, &e);
	scanf("%d", &source);

	adj.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 0; i < e; ++ i) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
	} SPFA(n, source);

	for (int i = 1; i <= n; ++ i) {
		if (dist[i] > 1e9) {
			printf("INF\n");
		} else {
			printf("%d\n", dist[i]);
		}
	}

	return 0;
}

void SPFA (int n, int s) {
	queue<int> q;
	vector<bool> isInQ(n + 1, false);

	for (int v = 1; v <= n; ++ v) {
		dist[v] = 2e9;
	} dist[s] = 0;

	q.push(s); isInQ[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		isInQ[u] = false;

		for (auto e : adj[u]) {
			int v = e.first, w = e.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				if (!isInQ[v]) {
					q.push(v);
					isInQ[v] = true;
				}
			}
		}
	}
}