#include <cstdio>

int dp[1001];

int main (int argc, char* argvp[]) {
    int list[1001];
    int n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", list + i);
        dp[i] = 1;
    }
    
    for (int i = 1; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (list[i] < list[j]) {
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
    }
    
    int max = dp[0];
    for (int i = 1; i < n; ++ i) {
        if (max < dp[i]) {
            max = dp[i];
        }
    } printf("%d\n", max);
    
    return 0;
}
