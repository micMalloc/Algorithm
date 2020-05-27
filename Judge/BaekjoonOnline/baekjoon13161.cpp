#include <cstdio>
#include <vector>
#define INF 1e9
using namespace std;

typedef pair<int, int> Pair;

void init_data (int);

bool Bellman_Ford (int, int);
void init_single_source (int, int);
bool relaxation (int, int, int);

vector<vector<Pair> > adj;
vector<int> d;

int main (int argc, char** argv) {
	int T;
	int n, m, w;
	int s, e, t;
	int source = 1;

	scanf("%d", &T);
	while (T --) {
		scanf("%d %d %d", &n, &m, &w);

		init_data(n);
		for (int i = 0; i < m; ++ i) {
			scanf("%d %d %d", &s, &e, &t);
			adj[s].push_back(make_pair(e, t));
			adj[e].push_back(make_pair(s, t));
		}
		for (int i = 0; i < w; ++ i) {
			scanf("%d %d %d", &s, &e, &t);
			adj[s].push_back(make_pair(e, -t));
		}

		if (Bellman_Ford(n, source)) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
		adj.clear();
		d.clear();
	}

	return 0;
}

void init_data (int n) {
	adj.resize(n + 1);
}

bool Bellman_Ford (int n, int source) {
	int k;

	init_single_source(n, source);
	for (k = 0; k < (n - 1); ++ k) {
		for (int u = 1; u <= n; ++ u) {
			for (Pair v : adj[u]) {
				if (d[u] != INF)
					relaxation(u, v.first, v.second);
			}
		}
	}

	for (int u = 1; u <= n; ++ u) {
		for (Pair v : adj[u]) {
			if (relaxation(u, v.first, v.second))
				return false;
		}
	} return true;
}

void init_single_source (int n, int source) {
	d.resize(n + 1, INF);
	d[source] = 0;
}

bool relaxation (int u, int v, int w) {
	bool isRelaxed = false;

	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		isRelaxed = true;
	} return isRelaxed;
}