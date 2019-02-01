#include <cstdio>
#define MAX 201

const int THRESHOLD = 3;

int n, m;
int adj[MAX][MAX];
bool visited[MAX];
int cnt;

void swap (int *a, int *b) {
    int tmp;

    if (*a > *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void init () {
    int a, b;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++ i) {
        for (int j = i + 1; j <= n; ++ j) {
            adj[i][j] = 1;
        }
    }

    for (int i = 0; i < m; ++ i) {
        scanf("%d %d", &a, &b);

        swap(&a, &b);
        adj[a][b] = 0;
    }
}

bool is_promising (int v) {
    bool promising = true;

    for (int u = 1; u <= n; ++ u) {
        if (visited[u] && !adj[u][v]) {
            promising = false;
        }
    }

    return promising;
}

void dfs (int u, int depth) {

    if (depth == THRESHOLD) {
        if (is_promising(u)) {
            cnt ++;
        }
        return;
    }

    visited[u] = true;

    for (int v = u + 1; v <= n; ++ v) {
        if (adj[u][v] && !visited[v]) {
            dfs(v, depth + 1);
        }
    }

    visited[u] = false;
}

int main (int argc, char* argv[]) {

    init();

    for (int i = 1; i <= n; ++ i) {
        dfs(i, 1);
    }

    printf("%d\n", cnt);

    return 0;
}