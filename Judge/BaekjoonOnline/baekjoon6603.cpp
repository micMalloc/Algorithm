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

int k;
int num[14];
int set[7];

void dfs (int start, int count) {
    
    if (count == 6) {
        for (int i = 0; i < 6; ++ i) {
            printf("%d ", set[i]);
        } printf("\n");
        return;
    }
    
    for (int i = start; i < k; ++ i) {
        set[count] = num[i];
        dfs(i + 1, count + 1);
    }
}

int main (int argc, char* argv[]) {
    
    while (1) {
        scanf("%d", &k);
        for (int i = 0; i < k; ++ i) {
            scanf("%d", num + i);
        }
        if (k == 0) break;
        
        dfs(0, 0);
        printf("\n");
    }
    
    return 0;
}
