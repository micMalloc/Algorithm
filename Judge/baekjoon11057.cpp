#include <cstdio>

int dp[1001][10];

int main (int argc, char* argv[]) {
    int n;

    scanf("%d", &n);

    for (int i = 0; i <= 9; ++ i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; ++ i) {
        for (int j = 0; j <= 9; ++ j) {
            for (int k = j; k <= 9; ++ k) {
                dp[i][k] += dp[i - 1][j];
                dp[i][k] %= 10007;
            }
        }
    }

    int result = 0;

    for (int i = 0; i <= 9; ++ i) {
        result += dp[n][i];
    }

    printf("%d\n", result % 10007);

    return 0;
}