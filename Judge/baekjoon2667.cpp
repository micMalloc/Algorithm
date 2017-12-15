#include <cstdio>
#include <algorithm>

using namespace std;

void DFS (int, int);
bool isInRange (int, int);

int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool visited[25][25];
int apart[25][25];
int cnt[25];
int n, chunk;

int main (void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) scanf("%1d", &apart[i][j]);
	}

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			if (apart[i][j] && !visited[i][j]) {
				DFS(i, j);
				chunk ++;
			}
		}
	} sort (cnt, cnt + chunk);

	printf("%d\n", chunk);
	for (int i = 0; i < chunk; ++ i) printf("%d\n", cnt[i]);

	return 0;
}

void DFS (int x, int y) {
	visited[x][y] = true;
	cnt[chunk] ++;

	int nx, ny;
	for (int i = 0; i < 4; ++ i) {
		nx = x + dx[i]; ny = y + dy[i];
		if (isInRange(nx, ny) && apart[nx][ny] && !visited[nx][ny])
			DFS(nx, ny);
	}
}

bool isInRange (int nx, int ny) {
	return (0<= nx && nx < n) && (0 <= ny && ny < n);
}