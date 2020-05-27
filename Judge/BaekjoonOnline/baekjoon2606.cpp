#include <iostream>
#include <vector>

using namespace std;

void DFS (int);

vector <int> list[111];
int visited[111];

int main ()
{
	int n, e;
	int a, b;
	int result = 0;

	scanf("%d", &n);
	scanf("%d", &e);

	for (int i = 0; i < e; ++ i)
	{
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	DFS (1);

	for (int i = 2; i <= n; ++ i)
	{
		if (visited[i] == 1)
			result ++;
	}
	printf("%d\n", result);

	return 0;
}

void DFS (int start)
{
	visited[start] = 1;

	for (int i = 0; i < list[start].size(); ++ i)
	{
		if (visited[list[start][i]] != 1)
			DFS(list[start][i]);
	}
}