#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 51

using namespace std;

int n;
vector<int> adj[MAX];
priority_queue<pair<int, int>> pq[MAX];

int dfs (int u) {
    int maximum = 0;
    int plus = 0;

    for (int &v : adj[u]) {
        pq[u].push({1 + dfs(v), v});
    }

    while (!pq[u].empty()) {
        int cost = pq[u].top().first;
        pq[u].pop();

        maximum = max(maximum, cost + (plus ++));
    }
    return maximum;
}

int main (int argc, char* argv[]) {
    int u;

    scanf("%d", &n);
    for (int v = 0; v < n; ++ v) {
        scanf("%d", &u);

        if (u < 0) continue;

        adj[u].push_back(v);
    }

    printf("%d\n", dfs(0));

    return 0;
}