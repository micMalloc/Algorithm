//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 20001
#define INF 999999

using namespace std;

int n;
vector<int> adj[MAX_SIZE];
int depth[MAX_SIZE];

void bfs (int start) {
    queue<int> q;
    
    depth[start] = 1;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (int i = 0; i < adj[u].size(); ++ i) {
            int v = adj[u][i];
            
            if (depth[v] == 0) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
}

int main (int argc, char* argv[]) {
    int m;
    int u, v;
    
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    while (m --) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(1);
    
    int target = 1;
    for (int i = 2; i <= n; ++ i) {
        if (depth[target] < depth[i]) {
            target = i;
        }
    }
    
    int count = 0;
    for (int i = 0; i <= n; ++ i) {
        if (depth[target] == depth[i]) {
            count ++;
        }
    }
    
    printf("%d %d %d\n", target, depth[target] - 1, count);
    
    return 0;
}
/*
 6 7
 3 6
 4 3
 3 2
 1 3
 1 2
 2 4
 5 2
 */
