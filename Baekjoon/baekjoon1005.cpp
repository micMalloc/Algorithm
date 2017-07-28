#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
const int MAX = 1001;

void find (int, vector<int>[MAX]);


int cost[MAX], dist[MAX];
queue<int> q;

int main (void) {
	int t;

	scanf("%d", &t);
	while (t --) {
		int n, k, target, u, v;
		vector<int> adj[MAX];

		memset(cost, 0, MAX * sizeof(int));
		memset(dist, 0, MAX * sizeof(int));

		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; ++ i)
			scanf("%d", &cost[i]);
		for (int i = 1; i <= k; ++ i) {
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			q.push(u);
			dist[u] = cost[u];
		} scanf("%d", &target);
		find (target, adj);
	}

	return 0;
}

void find (int target, vector<int> adj[]) {
	int next;

	while (!q.empty()) {
		int current = q.front(); q.pop();
		
		for (int i = 0; i < adj[current].size(); ++ i) {
			next = adj[current][i];
			
			if (dist[current] + cost[next] > dist[next]) {
				dist[next] = dist[current] + cost[next];
				q.push(next);
			}
		}
	} printf("%d\n", dist[target]);
}