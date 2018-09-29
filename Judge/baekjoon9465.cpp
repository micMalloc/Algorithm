//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#include <cstdio>
#include <algorithm>
#define MAX 100001
using namespace std;

int main (int argc, char* argv[]) {
    int test_case;
    
    scanf("%d", &test_case);
    while (test_case --) {
        int n;
        int val[2][MAX], dp[3][MAX] = {0,};
        
        scanf("%d", &n);
        for (int i = 0; i < 2; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d", &val[i][j]);
            }
        }
        
        for (int i = 0; i < n; ++ i) {
            dp[0][i + 1] = max(dp[0][i + 1], max(dp[0][i], max(dp[1][i], dp[2][i])));
            dp[1][i + 1] = max(dp[1][i + 1], max(dp[0][i], dp[2][i]) + val[0][i]);
            dp[2][i + 1] = max(dp[2][i + 1], max(dp[0][i], dp[1][i]) + val[1][i]);
        } printf("%d\n", max(dp[0][n], max(dp[1][n], dp[2][n])));
    }
    
    return 0;
}
