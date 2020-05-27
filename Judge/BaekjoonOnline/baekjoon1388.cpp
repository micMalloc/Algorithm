#include <cstdio>
#define MAX 100

int n, m, chunk;
char room[MAX][MAX + 1];

void goVertical (int x, int y) {
	room[x][y] = '.';
	if ((x - 1) >= 0 && room[x - 1][y] == '|') goVertical(x - 1, y);
	if ((x + 1) < n && room[x + 1][y] == '|') goVertical(x + 1, y);
}
void goHorizontal (int x, int y) {
	room[x][y] = '.';
	if ((y - 1) >= 0 && room[x][y - 1] == '-') goHorizontal(x, y - 1);
	if ((y + 1) < m && room[x][y + 1] == '-') goHorizontal(x, y + 1);
}

int main (int argc, char* argv[]) {
	
	scanf("%d %d%*c", &n, &m);
	for (int i = 0; i < n; ++ i) {
		gets(room[i]);
	}

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			if (room[i][j] != '.') {
				if (room[i][j] == '-') {
					goHorizontal(i, j);
				} else if (room[i][j] == '|') {
					goVertical(i, j);
				} chunk ++;
			}
		}
	} printf("%d\n", chunk);

	return 0;
}