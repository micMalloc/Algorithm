#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void dfs (int);
void bfs (int);

int m, n;
bool visited[1001];
vector<int> list[1001];

int main (void) {
	int u, v, cnt = 0;

	scanf("%d %d", &n, &m);
	while (m --) {
		scanf("%d %d", &u, &v);
		list[u].push_back(v);
		list[v].push_back(u);
	}

	for (int i = 1; i <= n; ++ i) {
		if (!visited[i]) {
			bfs(i);
			cnt ++;
		}
	} printf("%d\n", cnt);
	return 0;
}

void dfs (int v) {
	visited[v] = true;
	
	for (int i = 0; i < list[v].size(); ++ i) {
		if (!visited[list[v][i]]) dfs(list[v][i]);
	}
}
void bfs (int v) {
	int crt;
	queue<int> q;
	
	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		crt = q.front(); q.pop();
		for (int i = 0; i < list[crt].size(); ++ i) {
			if (!visited[list[crt][i]]) {
				q.push(list[crt][i]);
				visited[list[crt][i]] = true;
			}
		}
	}
}