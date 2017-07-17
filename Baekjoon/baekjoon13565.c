#include <stdio.h>

void DFS (int, int);

char material[1000][1001];
int visited[1000][1000];
int isGood;
int m, n;

int main (void)
{
	int i;

	scanf("%d %d%*c", &m, &n);
	for (i = 0; i < m; ++ i)
		gets(material[i]);
	
	for (i = 0; i < n; ++ i) {
		if (material[0][i] == '0' && visited[0][i] == 0)
			DFS(0, i);
	}
	for (i = 0; i < n; ++ i) {
		if (visited[m - 1][i])
			isGood = 1;
	}
	if (isGood)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}

void DFS (int x, int y) {
	visited[x][y] = 1;
	if (x > 0 && material[x - 1][y] == '0' && visited[x - 1][y] == 0)
		DFS(x - 1, y);
	if (x < m - 1 && material[x + 1][y] == '0' && visited[x + 1][y] == 0)
		DFS(x + 1, y);
	if (y > 0 && material[x][y - 1] == '0' && visited[x][y - 1] == 0)
		DFS(x, y - 1);
	if (y < n - 1 && material[x][y + 1] == '0' && visited[x][y + 1] == 0)
		DFS(x, y + 1);
}