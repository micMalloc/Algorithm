//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#include <cstdio>
#include <queue>

using namespace std;

int n, k;
int val[101];
int visit[10001];

int bfs (int v) {
    queue<pair<int, int> > q;
    
    q.push(make_pair(v, v));
    
    while (!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();
        
        if (cur == k) {
            return d;
        }
        
        for (int i = 0; i < n; ++ i) {
            int next = cur + val[i];
            if (next <= k && visit[next] == 0) {
                q.push(make_pair(cur + val[i], d + 1));
                visit[next] = 1;
            }
        }
    } return 0;
}

int main (int argc, char* argv[]) {
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &val[i]);
    }
    int d = bfs(0);
    if (d) {
        printf("%d\n", d);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
