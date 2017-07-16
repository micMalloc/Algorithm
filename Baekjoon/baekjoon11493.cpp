#include <iostream>
#define INFIN 9999

using namespace std;

void initData ();
void floyd_warshall ();
int matching ();

int adj[501][501];
int isWhite[501];
int bTw[250], wTb[250], idx_bTw, idx_wTb;
int n, m;

int main (void) {
	int t;
	int u, v;

	scanf("%d", &t);
	for (int i = 0; i < t; ++ i) {
		scanf("%d %d", &n, &m);

		initData ();
		for (int j = 0; j < m; ++ j) {
			scanf("%d %d", &u, &v);
			adj[u][v] = adj[v][u] = 1;
		}
		for (int j = 1; j <= n; ++ j)
			scanf("%d", &isWhite[j]);
		for (int j = 1; j <= n; ++ j) {
			int current;
			scanf("%d", &current);
			if (current != isWhite[j]) {
				if (current)
					wTb[idx_wTb ++] = j;
				else
					bTw[idx_bTw ++] = j;
			}
		}
		
		floyd_warshall();



		printf("%d\n", matching());
	}

	return 0;
}

void initData () {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j)
			adj[i][j] = INFIN;
	}
}

void floyd_warshall () {
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j]; 
}

int matching () {
	int min, count = 0;
	for (int i = 0; i < idx_bTw; ++ i) {
		min = wTb[0];
		for (int j = 0; j < idx_wTb; ++ j) {
			if (wTb[j] && adj[bTw[i]][min] > adj[bTw[i]][wTb[j]])
				min = wTb[j];
		}
		count += adj[bTw[i]][min];
		wTb[min] = 0;
	} return count;
}