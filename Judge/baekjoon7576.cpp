#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

void BFS ();
bool isInRange(int, int);
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
queue<pair<int, int> > q;
int visited[1000][1000];
int box[1000][1000];
int n, m;

int main (void) {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	} BFS();

	int i, j, max = 0;
	for (i = 0; i < n; ++ i) {
		for (j = 0; j < m; ++ j) {
			if (max < visited[i][j])
				max = visited[i][j];
			if (box[i][j] == 0) break;
		} if (j != m) break;
	}
	if (max == 1) printf("0\n");
	else if ((i + j) != (m + n)) printf("-1\n");
	else printf("%d\n", max);

	return 0;
}

void BFS () {
	int x, y, nx, ny;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++ i) {
			nx = x + dx[i]; ny = y +dy[i];
			if (isInRange(nx, ny) && box[nx][ny] == 0) {
				visited[nx][ny] = visited[x][y] + 1;
				box[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

bool isInRange (int nx, int ny) {
	return ( (0 <= nx && nx < n) && (0 <= ny && ny < m) );
}