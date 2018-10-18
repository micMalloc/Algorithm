//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#include <iostream>
#include <memory.h>
#define INF 999999
#define MAX 1001
#define MAX 1001

using namespace std;

int cost[MAX][MAX];
int d[MAX][MAX];
int n;

void floyd_warshall () {
    
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (i != j) {
                d[i][j] = cost[i][j];
            }
        }
    }
    
    for (int k = 1; k <= n; ++ k) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main (int argc, char* argv[]) {
    int m, x;
    int u, v, c;
    int max_val = 0;
    
    ios::sync_with_stdio(false);
    
    memset(cost, INF, sizeof(cost));
    
    cin >> n >> m >> x;
    while (m --) {
        cin >> u >> v >> c;
        cost[u][v] = c;
    } floyd_warshall();
    
    for (int i = 1; i <= n; ++ i) {
        max_val = max(max_val, d[i][x] + d[x][i]);
    } printf("%d\n", max_val);
    
    return 0;
}
