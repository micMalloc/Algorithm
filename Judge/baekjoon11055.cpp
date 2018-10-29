//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#include <cstdio>
#define MAX_SIZE 1001

int n;
int nums[MAX_SIZE];
int dp[MAX_SIZE];

int lis () {
    
    for (int i = 0; i < n; ++ i) {
        dp[i] = nums[i];
    }
    
    for (int i = 1; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (nums[j] < nums[i]) {
                if (dp[i] < dp[j] + nums[i]) {
                    dp[i] = dp[j] + nums[i];
                }
            }
        }
    }
    
    int max = 0;
    for (int i = 0; i < n; ++ i) {
        if (max < dp[i]) {
            max = dp[i];
        }
    }
    return max;
}

int main (int argc, char* argv[]) {
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", nums + i);
    }
    printf("%d\n", lis());
    
    return 0;
}
