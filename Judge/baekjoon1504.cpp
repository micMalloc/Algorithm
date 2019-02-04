#include <cstdio>
#include <cstring>
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

int Dijkstra (int start, int target) {
    int u, v, cost;

    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n; ++ i) {
        dist[i] = INF;
    }

    dist[start] = 0;

    priority_que.push({dist[start], start});

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

    return dist[target];
}

int get_distance (int route[]) {
    int d, distance = 0;

    for (int i = 1; i < 4; ++ i) {
        d = Dijkstra(route[i - 1], route[i]);

        if (d == INF) {
            return -1;
        }

        distance += d;
    }

    return distance;
}

int main (int argc, const char* argv[]) {
    int e;
    int u, v, cost;
    int landmark[2];
    int route[2][4];
    int distance[2];

    scanf("%d %d", &n, &e);

    while (e --) {
        scanf("%d %d %d", &u, &v, &cost);

        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    for (int i = 0; i < 2; ++ i) {
        scanf("%d", landmark + i);
    }

    route[0][0] = route[1][0] = 1;
    route[0][3] = route[1][3] = n;
    route[0][1] = route[1][2] = landmark[0];
    route[0][2] = route[1][1] = landmark[1];

    for (int i = 0; i < 2; ++ i) {
        distance[i] = get_distance(route[i]);
    }

    printf("%d\n", min(distance[0], distance[1]));
}
