#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

void dijkstra(int);

const int INF = 999999999;

vector<vector<pair<int, int>>> adj;
int n, m, source;

struct cmp {
	bool operator () (pair<int, int> x, pair<int, int> y) {
		return x.second > y.second;
	}
};

int main (void) {
	scanf("%d %d\n%d", &n, &m, &source);
	adj.resize(n + 1);

	for (int i = 0; i < m; ++ i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	} dijkstra(source);

	return 0;
}

void dijkstra (int source) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; 
	
	dist[source] = 0;
	for (int i = 1; i <= n; ++ i)
		pq.push(make_pair(i, dist[i]));
	
	int u, d, v, w;
	while (!pq.empty()) {
		u = pq.top().first;
		d = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for (int i = 0; i < adj[u].size(); ++ i) {
			v = adj[u][i].first;
			w = adj[u][i].second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
	
	for (int i = 1; i <= n; ++ i) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}