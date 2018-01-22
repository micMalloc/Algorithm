#include <cstdio>
#include <vector>
#include <utility>
#define INF 1e9
using namespace std;

bool Bellman_Ford (int, int);
void initSingleSource (int, int);
bool relaxation(int, int, int);

typedef pair<int, int> Pair;

vector<vector<Pair> > adj;
vector<int> d;

int main (int argc, char** argv) {
	int n, m;
	int a, b, c;

	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	d.resize(n + 1);

	while (m --) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
	}

	if (Bellman_Ford(1, n)) {
		for (int i = 2; i <= n; ++ i) {
			if (d[i] == INF) printf("-1\n");
			else printf("%d\n", d[i]);
		}
	} else {
		printf("-1\n");
	}

	return 0;
}

bool Bellman_Ford (int source, int n) {
	int u, v, w;
	
	initSingleSource(source, n);
	for (int i = 0; i < n - 1; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			for (auto p : adj[j]) {
				relaxation(j, p.first, p.second);
			}
		}
	}

	for (int i = 1; i <= n; ++ i) {
		for (auto p : adj[i]) {
			if (relaxation(i, p.first, p.second)) {
				return false;
			}
		}
	} return true;
}

void initSingleSource (int source, int n) {
	for (int i = 1; i <= n; ++ i) {
		if (i == source) {
			d[i] = 0;
		} else {
			d[i] = INF;
		}
	}
}

bool relaxation (int u, int v, int w) {
	bool isRelax = false;
	
	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		isRelax = true;
	} return isRelax;
}