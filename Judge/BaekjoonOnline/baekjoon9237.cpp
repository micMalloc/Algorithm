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

int n;
int tree[100001];

bool desc (int a, int b) {
    return a > b;
}

int main (int argc, char* argv[]) {
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &tree[i]);
    } sort(tree, tree + n, desc);
    
    int max = 0;
    int day = 2;
    for (int i = 0; i < n; ++ i) {
        tree[i] += day ++;
        if (max < tree[i]) {
            max = tree[i];
        }
    }
    
    printf("%d\n", max);
    
    return 0;
}
