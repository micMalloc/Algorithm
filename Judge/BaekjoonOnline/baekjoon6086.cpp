#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 52
#define INF 1e9
using namespace std;

int network_flow (int, int);

vector<int> adj[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];

int main (int argc, char** argv) {
	int n;
	char c_u, c_v;
	int u, v, c;
	int s, t;

	scanf("%d", &n);
	while (n --) {
		scanf(" %c %c %d", &c_u, &c_v, &c);
		if ('A' <= c_u && c_u <= 'Z') {
			u = c_u - 'A';
		} else {
			u = c_u - 'a' + 26;
		}
		if ('A' <= c_v && c_v <= 'Z') {
			v = c_v - 'A';
		} else {
			v = c_v - 'a' + 26;
		}
		
		capacity[u][v] += c;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	s = 0; t = 'Z' - 'A';
	printf("%d\n", network_flow(s, t));

	return 0;
}

int network_flow (int s, int t) {
	int total_flow = 0, max_flow;

	while (1) {
		int prev[MAX];
		memset(prev, -1, sizeof(prev));
		queue<int> q;

		prev[s] = s;
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();

			for (int i = 0; i < adj[u].size(); ++ i) {
				int v = adj[u][i];

				if (prev[v] != -1) {
					continue;
				}

				if (capacity[u][v] - flow[u][v] > 0) {
					prev[v] = u;
					q.push(v);

					if (v == t) break;
				}
			}
		}
		if (prev[t] == -1) break;

		max_flow = INF;
		for (int v = t; v != s; v = prev[v]) {
			int r = capacity[prev[v]][v] - flow[prev[v]][v];

			max_flow = min(max_flow, r);
		}
		for (int v = t; v != s; v = prev[v]) {
			flow[prev[v]][v] += max_flow;
			flow[v][prev[v]] -= max_flow;
		}
		total_flow += max_flow;
	} return total_flow;
}