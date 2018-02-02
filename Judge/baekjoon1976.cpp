#include <cstdio>
#include <vector>
#define MAX 201	
using namespace std;

int adj[MAX][MAX];
int n, m;

void warshall ();

int main (int argc, char** argv) {
	int next[MAX];
	vector<int> list;

	scanf("%d", &n);
	scanf("%d", &m);

	list.resize(m);
	for (int i = 0; i < m; ++ i)
		scanf("%d", &list[i]);

	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			scanf("%d", &adj[i][j]);
	warshall();
	
	

	return 0;
}

void warshall () {
	int i, j, k;

	for (k = 1; k <= n; ++ k)
		for (i = 1; i <= n; ++ i)
			for (j = 1; j <= n; ++ j)
				adj[i][j] = adj[i][j] | (adj[i][k] & adj[k][j]);
}