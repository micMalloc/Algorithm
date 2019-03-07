#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#define MAX 501

using namespace std;

int n, in_degree[MAX], cost[MAX], dist[MAX];
vector<int> adj[MAX];

void topology_sort () {
    int u, v;
    queue<int> que;

    for (int i = 1; i <= n; ++ i) {
        dist[i] = cost[i];
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        u = que.front(); que.pop();

        for (int i = 0; i < adj[u].size(); ++ i) {
            v = adj[u][i];

            dist[v] = max(dist[v], dist[u] + cost[v]);

            if (--in_degree[v] == 0) {
                que.push(v);
            }
        }
    }
}


int main (int argc, const char* argv[]) {
    int c, u;

    scanf("%d", &n);

    for (int v = 1; v <= n; ++ v) {
        scanf("%d", &c);

        cost[v] = c;

        while (1) {
            scanf("%d", &u);

            if (u == -1) break;

            adj[u].push_back(v);
            in_degree[v] ++;
        }
    }

    topology_sort();

    for (int i = 1; i <= n; ++ i) {
        printf("%d\n", dist[i]);
    }

    return 0;
}