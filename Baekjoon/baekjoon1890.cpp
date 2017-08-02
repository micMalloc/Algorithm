#include <cstdio>

const int MAX = 100;

int table[MAX][MAX];
long long visited[MAX][MAX];
int n;

int main (void) {
	scanf("%d", &n);

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j)
			scanf("%d", &table[i][j]);
	} visited[0][0] = 1;

	for (int x = 0; x < n; ++ x) {
		int nx, ny;
		for (int y = 0; y < n; ++ y) {
			if (table[x][y] > 0) {
				nx = x + table[x][y];
				ny = y + table[x][y];
				if (nx < n)
					visited[nx][y] += visited[x][y];
				if (ny < n)
					visited[x][ny] +=visited[x][y];
			}
		}
	} printf("%lld\n", visited[n - 1][n - 1]);

	return 0;
}