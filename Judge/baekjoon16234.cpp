//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <utility>
#define MAX_SIZE 51
#define DIR 4

using namespace std;

int n;
int L, R;
int idx;
int map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
pair<int, int> _union[MAX_SIZE * MAX_SIZE];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isPromising (int x, int y) {
    bool promising = true;
    
    if (x < 0 || x >= n) promising = false;
    if (y < 0 || y >= n) promising = false;
    if (visit[x][y]) promising = false;
    
    return promising;
}

bool bfs (int x, int y) {
    int population = 0;
    queue<pair<int, int> > q;
    
    population += map[x][y];
    visit[x][y] = true;
    q.push(make_pair(x, y));
    
    idx = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        _union[idx ++] = q.front(); q.pop();
        
        for (int i = 0; i < DIR; ++ i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isPromising(nx, ny) == false) continue;
            
            int dif = abs(map[nx][ny] - map[x][y]);
            if (L <= dif && dif <= R) {
                population += map[nx][ny];
                visit[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    /* Migration */
    int avg = (int)population / idx;
    for (int i = 0; i < idx; ++ i) {
        int x = _union[i].first;
        int y = _union[i].second;
        
        map[x][y] = avg;
    }
    
    if (idx > 1) return true;
    else return false;
}

int main (int argc, char* argv[]) {
    int cnt = 0;
    
    scanf("%d %d %d", &n, &L, &R);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            scanf("%d", &map[i][j]);
        }
    }
    
    while (true) {
        bool migration = false;
        
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (visit[i][j] == false) {
                    if (bfs(i, j)) {
                        migration = true;
                    }
                }
            }
        }
        
        if (migration) {
            cnt ++;
        } else {
            break;
        }
        memset(visit, false, sizeof(visit));
    }
    printf("%d\n", cnt);
    
    return 0;
}
