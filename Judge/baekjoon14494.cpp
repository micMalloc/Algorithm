#include <cstdio>
#define MAX 1002

typedef long long int lld;

lld dp[MAX][MAX];
lld mod = 1e9 + 7;

int main (int argc, const char* argv[]) {
    int n, m;

    scanf("%d %d", &n, &m);

    dp[1][1] = 1;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
        }
    }

    printf("%lld\n", dp[n][m]);

    return 0;
}