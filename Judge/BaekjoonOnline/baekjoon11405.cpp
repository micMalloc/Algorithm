#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 9999

using namespace std;
const int MAX_N = 250;
const int MAX_V = 2 * (MAX_N + 1);
const int S = MAX_N - 2;
const int E = MAX_N - 1;

int capacity[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int main (void) {
	int n, m;
	int u, v;
	vector<int> adj[MAX_V];

	scanf("%d %d", &n, &m);
	for (int i = MAX_N; i < MAX_N + n; ++ i) {
		/* A */
		scanf("%d", &capacity[i][E]);
		adj[E].push_back(i);
		adj[i].push_back(E);
	}
	for (int i = 0; i < n; ++ i) {
		/* B */
		scanf("%d", &capacity[S][i]);
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for (int i = 0; i < m; ++ i) {
		for (int j = MAX_N; j < MAX_N + n; ++ j) {
			scanf("%d", &cost[i][j]);
			cost[j][i] = -cost[i][j];
			capacity[i][j] = INF;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	
	int result = 0;
	/* MCMF */
	while (1) {
		int prev[MAX_V], dist[MAX_V];
		bool inQ[MAX_V] = {0};
		queue<int> q;

		memset(prev, -1, MAX_V * sizeof(int));
		memset(dist, 9999, MAX_V * sizeof(int));

		dist[S] = 0;
		inQ[S] = true;
		q.push(S);

		while (!q.empty()) {
			int current = q.front(); q.pop();
			inQ[current] = false;
			for (int i = 0; i < adj[current].size(); ++ i) {
				if (capacity[current][adj[current][i]] - flow[current][adj[current][i]] > 0 && dist[adj[current][i]] > dist[current] + cost[current][adj[current][i]]) {
					dist[adj[current][i]] = dist[current] + cost[current][adj[current][i]];
					prev[adj[current][i]] = current;
					if (!inQ[adj[current][i]]) {
						q.push (adj[current][i]);
						inQ[adj[current][i]] = true;
					}
				}
			}
		}
		if (prev[E] == -1) break;

		int f = INF;
		for (int i = E; i != S; i = prev[i]) {
			if (f > capacity[prev[i]][i] - flow[prev[i]][i])
				f = capacity[prev[i]][i] - flow[prev[i]][i];
		}

		for (int i = E; i != S; i = prev[i]) {
			result += f * cost[prev[i]][i];
			flow[prev[i]][i] += f;
			flow[i][prev[i]] -= f;
		}
	} printf("%d\n", result);

	return 0;
}