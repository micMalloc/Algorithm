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
#define MAXN 100010
int p[MAXN], n;

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    p[x] = y;
}

int main() {
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) p[i] = i;
    int m; scanf(" %d", &m);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x; scanf(" %d", &x);
        if (!find(x)) break;
        ans++;
        int c = find(x);
        merge(c, c-1);
    }
    printf("%d\n", ans);
    return 0;
}
