#include <cstdio>
#include <queue>
#include <vector>
#define INF 1e9
#define MAX 500
using namespace std;

bool SPFA (int, int);

typedef pair<int, int> Pair;
vector<Pair> adj[MAX];
int d[MAX];

int main (int argc, char** argv) {
	int n, m;
	int u, v, c;

	scanf("%d %d", &n, &m);
	while (m --) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
	}

	if (SPFA(n, 1)) {
		for (int i = 2; i <= n; ++ i) {
			if (d[i] == INF) {
				printf("-1\n");
			} else {
				printf("%d\n", d[i]);
			}
		}
	} else {
		printf("-1\n");
	}

	return 0;
}

bool SPFA (int n, int s) {
	queue<int> q;
	int cycle[MAX] = {0,};
	bool isInQ[MAX] = {false, };
	int u, v, c;
	
	for (int i = 1; i <= n; ++ i) {
		d[i] = INF;
	} d[s] = 0;

	q.push(s); isInQ[s] = true; cycle[s] ++;
	while (!q.empty()) {
		u = q.front(); q.pop(); isInQ[u] = false;
		for (Pair p : adj[u]) {
			v = p.first; c = p.second;
			if (d[v] > d[u] + c) {
				d[v] = d[u] + c;
				if (isInQ[v] == false) {
					cycle[v] ++;
					if (cycle[v] >= n) {
						return false;
					}
					q.push(v); isInQ[v] = true;
				}
			}
		}
	} return true;
}