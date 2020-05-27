#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXIMUM 401

using namespace std;

vector<int> adj[MAXIMUM];
vector<int> rev[MAXIMUM];
bool visited[MAXIMUM];

int bfs (int u, int v, vector<int> graph[]) {
    queue<int> q;
    
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        if (cur == v) return 1;
        
        for (int i = 0; i < graph[cur].size(); ++ i) {
            if (!visited[graph[cur][i]]) {
                q.push(graph[cur][i]);
                visited[graph[cur][i]] = true;
            }
        }
    }
    
    return 0;
}

int main (int argc, char* argv[]) {
    int n, k;
    int s;
    
    scanf("%d %d", &n, &k);
    while (k --) {
        int u, v;
        
        scanf("%d %d", &u, &v);
        adj[v].push_back(u);
        rev[u].push_back(v);
    }
    
    scanf("%d", &s);
    while (s --) {
        int u, v;
        
        scanf("%d %d", &u, &v);
        memset(visited, false, sizeof(visited));
        if (bfs(v, u, adj)) {
            printf("-1\n");
        } else {
            memset(visited, false, sizeof(visited));
            if (bfs(v, u, rev)) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    
    return 0;
}
