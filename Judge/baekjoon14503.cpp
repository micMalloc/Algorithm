#include <cstdio>
#define MAX 50

int count, dir, x, y;
int room[MAX][MAX];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main (int argc, char* argv[]) {
	int n, m;
	bool available = true;
	int nx, ny;
	
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &x, &y, &dir);

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			scanf("%d", &room[i][j]);
		}
	}

	while (available) {
		if (room[x][y] == 0) {
			count ++;
		} room[x][y] = 2;

		for (int i = 0; i < 5; ++ i) {
			if (i == 4) {
				nx = x + dx[(dir + 3) % 4];
				ny = y + dy[(dir + 3) % 4];
				if (room[nx][ny] != 1) {
					x = nx; y = ny;
				} else {
					available = false;
				}
				break;
			}

			nx = x + dx[dir]; ny = y + dy[dir];
			dir = (dir + 3) % 4;
			if (room[nx][ny] == 0) {
				x = nx; y = ny;
				break;
			}
		}
	} printf("%d\n", count);

	return 0;
}