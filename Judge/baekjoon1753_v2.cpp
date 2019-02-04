#include <cstdio>
#include <queue>
#include <vector>
#define MAX 20001
#define INF 987654321

using namespace std;

int n;
vector<pair<int, int>> adj[MAX];
priority_queue<pair<int, int>> priority_que;
bool visited[MAX];
int dist[MAX];

int extract_min () {
    int target = priority_que.top().second;

    priority_que.pop();

    return target;
}

void Dijkstra (int start) {
    int u, v, cost;

    for (int i = 1; i <= n; ++ i) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (int i = 1; i <= n; ++ i) {
        priority_que.push({-dist[i], i});
    }

    while (!priority_que.empty()) {
        u = extract_min();

        if (visited[u]) continue;

        visited[u] = true;

        for (int i = 0; i < adj[u].size(); ++ i) {
            v = adj[u][i].first;
            cost = adj[u][i].second;

            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                priority_que.push({-dist[v], v});
            }
        }
    }
}

int main (int argc, const char* argv[]) {
    int e, start;
    int u, v, cost;

    scanf("%d %d", &n, &e);

    scanf("%d", &start);
    while (e --) {
        scanf("%d %d %d", &u, &v, &cost);

        adj[u].push_back({v, cost});
    }

    Dijkstra(start);

    for (int i = 1; i <= n; ++ i) {
        if (dist[i] == INF) {
            printf("INF\n");
        }
        else {
            printf("%d\n", dist[i]);
        }
    }
}
