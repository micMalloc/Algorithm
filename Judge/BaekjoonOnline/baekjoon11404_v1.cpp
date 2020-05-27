//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 101
#define INF 100001

int table[MAX][MAX];
int dp[MAX][MAX];

void floyd (int n) {
    
    for (int k = 0; k < n; ++ k) {
        for (int i = 0; i < n; ++ i) {
            if (dp[i][k] == INF) continue;
            
            for (int j = 0; j < n; ++ j) {
                if (dp[k][j] == INF || i == j) continue;
                
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}

int main (int argc, char* argv[]) {
    int n, m;
    int cost;
    int u, v;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = table[i][j] = INF;
            }
        }
    }
    
    scanf("%d", &m);
    while (m --) {
        scanf("%d %d %d", &u, &v, &cost);
        if (table[u - 1][v - 1] > cost)
            dp[u - 1][v - 1] = table[u - 1][v - 1] = cost;
    } floyd(n);
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (dp[i][j] == INF) {
                printf("0 ");
            } else {
                printf("%d ", dp[i][j]);
            }
        } printf("\n");
    }
    
    return 0;
}
