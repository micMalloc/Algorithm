//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#define MAX 101
#define INF 99999

int cost[MAX][MAX];

void Floyd_Warshall (int n) {
    int d[MAX][MAX];
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            d[i][j] = cost[i][j];
        }
    }
    
    for (int k = 0; k < n; ++ k) {
        for (int i = 0; i < n; ++ i) {
            if (d[i][k] == INF) continue;
            
            for (int j = 0; j < n; ++ j) {
                if (d[k][j] == INF || k == j) continue;
                
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}
