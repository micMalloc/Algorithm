#include <cstdio>
#include <queue>
#include <vector>
#define MAX 801
#define INF 1e9

using namespace std;

int n;
vector<pair<int, int>> adj[MAX];
priority_queue<pair<int, int>> pq;
bool visited[MAX];
int dist[MAX];

int extract_min () {
    int target = pq.top().second;

    pq.pop();

    return target;
}

void Dijkstra (int start) {
    int u, v, cost;

    for (int i = 1; i <= n; ++ i) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (int i = 1; i <= n; ++ i) {
        pq.push({-dist[i], i});
    }

    while (!pq.empty()) {
        u = extract_min();

        if (visited[u]) continue;

        visited[u] = true;

        for (int i = 0; i < adj[u].size(); ++ i) {
            v = adj[u][i].first;
            cost = adj[u][i].second;

            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main (int argc, char* argv[]) {

    return 0;
}