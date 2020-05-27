#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101];
int depth[101];
int n;
int x, y;

bool bfs (int source) {
    queue<int> q;
    
    q.push(source);
    depth[source] = 1;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        if (u == y) {
            return true;
        }
        
        for (int i = 0; i < adj[u].size(); ++ i) {
            int v = adj[u][i];
            
            if (depth[v] == 0) {
                q.push(v);
                depth[v] = depth[u] + 1;
            }
        }
    } return false;
}

int main (int argc, char* argv[]) {
    int m;
    int u, v;
    
    ios::sync_with_stdio(false);
    
    cin >> n;
    cin >> x >> y;
    cin >> m;
    
    while (m --) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (bfs(x)) {
        cout << (depth[y] - 1) << '\n';
    } else {
        cout << "-1\n";
    }
    
    return 0;
}
