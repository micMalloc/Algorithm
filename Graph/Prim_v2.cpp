#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#define MAX 1000

using namespace std;

void prim ();
int extractMin ();

const int INF = 99999;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<int> > pq;
vector<vector<int> > adjList;

int path[MAX], cost[MAX][MAX];
int n;
bool visited[MAX];

int main (void) {
	
	return 0;
}

void prim (int source) {
	int u, v;
	int key[MAX];

	for (int v = 1; v <= n; ++ v) {
		if (source != v)
			pq.push(make_pair(INF, v));
		else
			pq.push(make_pair(0, v));
	}

	while (!pq.empty()) {
		u = extractMin();
		for (int i = 0; i < adjList[u].size(); ++ i) {
			v = adjList[u][i];
			if (!visited[v] && (cost[u][v] < key[v])) {
				key[v] = cost[u][v];
			}
		}
	}
}

int extractMin () {
	int target = pq.top().second; pq.pop();
	visited[target] = true;
	return (target);
}