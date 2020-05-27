#include <cstdio>
#include <algorithm>
#define MAX 101
#define INF 1e9
using namespace std;

int adj[MAX][MAX];
int d[MAX][MAX];

int main (int argc, char** argv) {
	int n, m;
	int a, b, c;

	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; ++ i) 
		for (int j = 1; j <= n; ++ j) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}

	while (m --) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = 1;
		d[a][b] = min(d[a][b], c);
	}

	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i) {
			//if (adj[i][k] == 0) continue;
			for (int j = 1; j <= n; ++ j) {
				//if (adj[k][j] == 0 || i == j) continue;
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			printf("%d ", d[i][j]);
		} printf("\n");
	}

	return 0;
}