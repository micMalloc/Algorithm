#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <memory.h>
#include <algorithm>

#define MAX_SIZE 1001
#define INF 99999

using namespace std;

int n;
vector<pair<int, int>> adj[MAX_SIZE];
vector<pair<int, int>> rev[MAX_SIZE];
int d[MAX_SIZE], rd[MAX_SIZE];

struct cmp {
    bool operator () (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;

pair<int, int> extract_min () {
    pair<int, int> u;
    
    u = pq.top(); pq.pop();
    return u;
}

void dijkstra (int source) {
    pair<int, int> u;
    int v, cost;
    
    for (int i = 1; i <= n; ++ i) {
        d[i] = INF;
    } d[source] = 0;
    
    for (int i = 0; i <= n; ++ i) {
        pq.push(make_pair(i, d[i]));
    }
    
    while (!pq.empty()) {
        u = extract_min();
        
        for (int i = 0; i < adj[u.first].size(); ++ i) {
            v = adj[u.first][i].first;
            cost = adj[u.first][i].second;
            
            if (d[v] > d[u.first] + cost) {
                d[v] = d[u.first] + cost;
                
                pq.push(make_pair(v, d[v]));
            }
        }
    }
}

void reverse_dijkstra (int source) {
    pair<int, int> u;
    int v, cost;
    
    for (int i = 1; i <= n; ++ i) {
        rd[i] = INF;
    } rd[source] = 0;
    
    for (int i = 0; i <= n; ++ i) {
        pq.push(make_pair(i, rd[i]));
    }
    
    while (!pq.empty()) {
        u = extract_min();
        
        for (int i = 0; i < rev[u.first].size(); ++ i) {
            v = rev[u.first][i].first;
            cost = rev[u.first][i].second;
            
            if (rd[v] > rd[u.first] + cost) {
                rd[v] = rd[u.first] + cost;
                
                pq.push(make_pair(v, rd[v]));
            }
        }
    }
}


int main (int argc, char* argv[]) {
    int m;
    int x;
    int u, v, c;
    int ans = 0;
    
    ios_base::sync_with_stdio(false);
    
    //scanf("%d %d %d", &n, &m, &x);
    cin >> n >> m >> x;
    while (m --) {
        //scanf("%d %d %d", &u, &v, &c);
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
        rev[v].push_back(make_pair(u, c));
    }
    
    dijkstra(x);
    reverse_dijkstra(x);
    
    for (int i = 1; i <= n; ++ i) {
        ans = max(ans, d[i] + rd[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}
