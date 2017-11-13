#include <cstdio>
#include <vector>
#define MAX 1000
using namespace std;

bool bellman_ford (int, int, int);
void initializeSingleSource (int);
bool relaxation(int, int, int);
void print (int, int);

const int INF = 99999;

typedef struct EDGE {
	int from;
	int to;
	int cost;
} Edge;

vector<vector<pair<int, int> > > adjList;
vector<int> dist;
vector<Edge> e;

int main (void) {
	int nc, ec;
	int i, from, to, cost, source;

	scanf("%d", &nc);
	scanf("%d", &ec);

	adjList.resize(nc + 1);
	dist.resize(nc + 1);
	e.resize(ec);

	for (i = 0; i < ec; ++ i) {
		scanf("%d %d %d", &from, &to, &cost);
		e[i].from = from; e[i].to = to; e[i].cost = cost;
		adjList[from].push_back(make_pair(to, cost));
	}

	scanf("%d", &source);
	if (bellman_ford (nc, ec, source)) {
		print(nc, source);
	} else {
		printf("Negative Cycle is in a Graph\n");
	}

	return 0;
}

bool bellman_ford (int nc, int ec, int source) {
	int i, j;
	
	initializeSingleSource(source);
	for (i = 0; i < (nc - 1); ++ i) {
		for (j = 0; j < ec; ++ j) {
			relaxation(e[i].from, e[i].to, e[i].cost);
		}
	}

	for (i = 0; i < ec; ++ i) {
		if (relaxation(e[i].from, e[i].to, e[i].cost))
			return false;
	} return true;
}

void initializeSingleSource (int source) {
	int i;

	for (i = 1; i <= (dist.size() - 1); ++ i) {
		if (i == source) dist[i] = 0;
		else dist[i] = INF;
	}
}

bool relaxation (int from, int to, int cost) {
	if (dist[to] > dist[from] + cost) {
		dist[to] = dist[from] + cost;
		return true;
	} return false;
}

void print (int nc, int source) {
	int i;
	for (i = 1; i <= nc; ++ i) {
		if (source != i) {
			printf("Source : %d  Destination : %d  Distance : %d\n", source, i, dist[i]);
		}
	}
}