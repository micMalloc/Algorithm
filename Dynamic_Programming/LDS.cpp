
for (int i = 1; i < n; ++ i) {
    for (int j = 0; j < i; ++ j) {
        if (list[i] < list[j]) {
            if (dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1
            }
        }
    }
}
