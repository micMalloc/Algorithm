#include <cstdio>

typedef long long int lld;

lld dp[65][10];

int main (int argc, const char* argv[]) {
    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        for (int i = 0; i < 10; ++ i) {
            dp[1][i] = i + 1;
        }

        for (int i = 2; i <= n; ++ i) {
            dp[i][0] = 1;

            for (int j = 1; j < 10; ++ j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        printf("%lld\n", dp[n][9]);
    }

    return 0;
}