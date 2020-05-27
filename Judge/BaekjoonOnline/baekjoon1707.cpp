#include <cstdio>
#include <vector>
using namespace std;

void dfs (int, int);

vector<int> adj[20001];
int group[20001];

int main (void) {
	int v, e, k;
	int a, b, g;
	bool isOk;

	scanf("%d", &k);
	while (k --) {
		scanf("%d %d", &v, &e);
		for (int i = 0; i < e; ++ i) {
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int i = 1; i <= v; ++ i) {
			if (group[i] == 0) dfs(i, 1);
		}
		isOk = true;
		for (int i = 1; i <= v; ++ i) {
			a = i;
			for (int j = 0; j < adj[i].size(); ++ j) {
				b = adj[a][j];
				if (group[a] == group[b]) isOk = false;
			}
		}
		if (isOk) printf("YES\n");
		else printf("NO\n");

		for (int i = 1; i <= v; ++ i) {
			adj[i].clear();
			group[i] = 0;
		}
	}
}

void dfs (int v, int g) {
	int next;

	group[v] = g;
	for (int i = 0; i < adj[v].size(); ++ i) {
		next = adj[v][i];
		if (group[next] == 0) dfs(next, 3 - g);
	}
}