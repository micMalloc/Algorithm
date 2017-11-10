#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#define MAX 1000

using namespace std;

void dijkstra (int, int);
pair<int, int> extractMin ();
void printResult (int, int);

const int INF = 99999;

int dist[MAX];
struct cmp {
	bool operator () (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

// Adjacency List
vector<vector<pair<int, int> > > adjList;
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;


int main (void) {
	int nc, ec, i;
	int from, to, cost;
	int source;
//nc is Node Count Var
//ec is Edge Count Var
	
	scanf("%d", &nc);
	adjList.resize(nc + 1);

// Construct Graph Using Adjacency List
	scanf("%d", &ec);
	for (i = 0; i < ec; ++ i) {
// Format : source destination cost
		scanf("%d %d %d", &from, &to, &cost);
		adjList[from].push_back(make_pair(to, cost));
	}
// Read Source Vertex
	scanf("%d", &source);

	dijkstra(nc, source);
	printResult(nc, source);

	return 0;
}

void dijkstra (int nc, int source) {
	int i;
	int v, cost;
	pair<int, int> u;

	for (i = 1; i <= nc; ++ i) {
		dist[i] = INF;
	} dist[source] = 0;

	for (i = 1; i <= nc; ++ i) {
		pq.push(make_pair(i, dist[i]));
	}

	while (!pq.empty()) {
		u = extractMin();

		if (u.second > dist[u.first]) continue;
		for (i = 0; i < adjList[u.first].size(); ++ i) {
			v = adjList[u.first][i].first;
			cost = adjList[u.first][i].second;

			if (dist[v] > dist[u.first] + cost) {
				dist[v] = dist[u.first] + cost;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
}

pair<int, int> extractMin () {
	pair<int, int> u;
	
	u = pq.top(); pq.pop();
	return u;
}

void printResult (int nc, int source) {
	int i;

	for (i = 1; i <= nc; ++ i) {
		if (i == source) continue;
		if (dist[i] != INF)
			printf("%d  ", dist[i]);
		else
			printf("INFINITY  ");
	} printf("\n");
}