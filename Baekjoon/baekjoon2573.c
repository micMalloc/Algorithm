#include <stdio.h>
#define MAX 301

void melting();
void countChunk();
int check(int, int);
void DFS(int, int);
void initVisit();

int iceberg[MAX][MAX];
int adjacent[MAX][MAX];
int visited[MAX][MAX];
int n, m, chunk = 0, year = 0;

int main (void)
{
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++ i)
	{
		for (j = 0; j < m; ++ j)
			scanf("%d", &iceberg[i][j]);
	}

	while (1)
	{
		countChunk();
		if (chunk >= 2 || chunk == 0)
			break;
		year ++;
		melting();
	}
	if (chunk >= 2)
		printf("%d\n", year);
	else
		printf("0\n");

	return 0;
}

void initVisit ()
{
	int i, j;
	for (i = 0; i < n; ++ i)
	{
		for (j = 0; j < m; ++ j)
			visited[i][j] = 0;
	}
}

void countChunk ()
{
	int i, j;

	initVisit();
	chunk = 0;
	for (i = 1; i < n - 1; ++ i)
	{
		for (j = 1; j < m - 1; ++ j)
		{
			if (visited[i][j] == 0 && iceberg[i][j] > 0)
			{
				DFS(i, j);
				chunk ++;
			}
		}
	}
}

void DFS (int i, int j)
{
	visited[i][j] = 1;
	
	if (visited[i - 1][j] == 0 && iceberg[i - 1][j] > 0)
		DFS(i - 1, j);
	if (visited[i][j - 1] == 0 && iceberg[i][j - 1] > 0)
		DFS(i, j - 1);
	if (visited[i + 1][j] == 0 && iceberg[i + 1][j] > 0)
		DFS(i + 1, j);
	if (visited[i][j + 1] == 0 && iceberg[i][j + 1] > 0)
		DFS(i, j + 1);
}

int check (int i, int j)
{
	int count = 0;

	if (iceberg[i - 1][j] == 0)
		count ++;
	if (iceberg[i][j - 1] == 0)
		count ++;
	if (iceberg[i + 1][j] == 0)
		count ++;
	if (iceberg[i][j + 1] == 0)
		count ++;

	return count;
}

void melting ()
{
	int i, j;

	for (i = 1; i < n - 1; ++ i)
	{
		for (j = 1; j < m - 1; ++ j)
		{
			if (iceberg[i][j] > 0)
				adjacent[i][j] = check(i, j);
		}
	}
	for (i = 1; i < n - 1; ++ i)
	{
		for (j = 1; j < m - 1; ++ j)
		{
			iceberg[i][j] -= adjacent[i][j];
			if (iceberg[i][j] < 0)
				iceberg[i][j] = 0;
		}
	}
}