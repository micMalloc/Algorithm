//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//

#include <cstdio>

int dp[41];

int fibo (int n) {
    if (n == 0) {
        dp[0] = 0;
        return dp[0];
    } else if (n == 1) {
        dp[1] = 1;
        return dp[1];
    }
    
    if (dp[n]) {
        return dp[n];
    }
    
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main (int argc, char* argv[]) {
    int test_case;
    int n;
    
    scanf("%d", &test_case);
    while (test_case --) {
        scanf("%d", &n);
        if (n == 0) {
            printf("1 0\n");
        } else if (n == 1) {
            printf("0 1\n");
        } else {
            fibo(n);
            printf("%d %d\n", dp[n - 1], dp[n]);
        }
    }
    
    return 0;
}
