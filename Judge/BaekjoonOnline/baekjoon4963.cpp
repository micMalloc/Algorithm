//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#include <stdio.h>

const int dx[] = { 0,0,1,-1,1,1,-1,-1 };
const int dy[] = { -1,1,0,0,1,-1,-1,1 };

int n, m;
int a[51][51];

void dfs(int x, int y) {
    a[x][y] = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (a[nx][ny]) dfs(nx, ny);
    }
}

int main() {
    while (1) {
        int ans = 0;
        scanf("%d %d", &m, &n);
        
        if (!n && !m) break;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j]) dfs(i, j), ans++;
        
        printf("%d\n", ans);
    }
    return 0;
}
