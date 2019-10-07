#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;

vector<int> adj[MAX + 1];
int parent[MAX + 1];
int n;

void BFS (int start) {
    queue<int> que;
    int u, v;

    parent[start] = 1;
    que.push(start);

    while (!que.empty()) {
        u = que.front(); que.pop();

        for (int i = 0; i < adj[u].size(); ++ i) {
            v = adj[u][i];

            if (parent[v] == 0) {
                parent[v] = u;
                que.push(v);
            }
        }
    }
}

int main (int argc, const char* argv[]) {
    int u, v;

    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++ i) {
        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(1);

    for (int v = 2; v <= n ; ++ v) {
        printf("%d\n", parent[v]);
    }

    return 0;
}