#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#define INF 1000001
using namespace std;

typedef pair<int, int> Pair;

int prim (int);

vector<vector<Pair> > adj;
vector<bool> isInQ;
vector<int> key;

int main (int argc, char** argv) {
	int v, e;
	int a, b, c;

	scanf("%d", &v);
	scanf("%d", &e);
	adj.resize(v + 1);
	key.resize(v + 1);
	isInQ.resize(v + 1);

	while (e --) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}

	printf("%d\n", prim(v));

	return 0;
}

int prim (int n) {
	int source = 1;
	int u;
	int total_cost = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair> > q;

	for (int v = 1; v <= n; ++ v) {
		if (v != source) {
			q.push(make_pair(INF, v));
			key[v] = INF;
		} else {
			q.push(make_pair(0, v));
			key[v] = 0;
		}
		isInQ[v] = true;
	}

	while (!q.empty()) {
		u = q.top().second; q.pop();
		if (!isInQ[u]) continue;
		
		total_cost += key[u];
		isInQ[u] = false;
		for (int i = 0; i < adj[u].size(); ++ i) {
			int next = adj[u][i].first;
			int cost = adj[u][i].second;
			
			if (isInQ[next] && key[next] > cost) {
				key[next] = cost;
				q.push(make_pair(key[next], next));
			}
		}
	} return total_cost;
}