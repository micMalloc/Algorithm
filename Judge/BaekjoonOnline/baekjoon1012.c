#include <stdio.h>
#include <stdlib.h>

void DFS (int, int);
void initData ();

int area[50][50];
int visited[50][50];
int* result;
int sum = 0, count = 0;
int t, m, n, k;

int main ()
{
	int x, y;
	int i, j;
	int a = 0;
	
	scanf("%d", &t);
	result = (int*)malloc(t * sizeof (int));
	while (a < t)
	{
		scanf("%d %d %d", &m, &n, &k);

		for (i = 0; i < k; ++ i)
		{
			scanf("%d %d", &x, &y);
			area[x][y] = 1;
		}

		for (i = 0; i < m; ++ i)
		{
			for (j = 0; j < n; ++ j)
			{
				if (area[i][j] == 1 && visited[i][j] != 1)
				{
					DFS(i, j);
					count ++;

					if (sum == k)
						break;
				}
			}
		}
		result[a ++] = count;

		initData ();
	}
	for (a = 0; a < t; ++ a)
		printf("%d\n", result[a]);

	return 0;
}

void DFS (int x, int y)
{
	visited[x][y] = 1;
	sum += 1;

	if (y - 1 >= 0 && area[x][y - 1] == 1 && visited[x][y - 1] != 1)
		DFS(x, y - 1);
	if (y + 1 < n && area[x][y + 1] == 1 && visited[x][y + 1] != 1)
		DFS(x, y + 1);
	
	if (x - 1 >= 0 && area[x - 1][y] == 1 && visited[x - 1][y] != 1)
		DFS(x - 1, y);
	if (x + 1 < m && area[x + 1][y] == 1 && visited[x + 1][y] != 1)
		DFS(x + 1, y);
}

void initData ()
{
	int i, j;

	for (i = 0; i < 50; ++ i)
	{
		for (j = 0; j < 50; ++ j)
		{
			visited[i][j] = 0;
			area[i][j] = 0;
		}
	}
	count = sum = 0;
}