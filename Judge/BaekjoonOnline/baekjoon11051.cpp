#include <cstdio>
#define MAX 1001

int dp[MAX][MAX];

int binomial (int n, int k) {

    if (n == k || k == 0) {
        return 1;
    }

    if (dp[n][k]) {
        return dp[n][k];
    }

    return (dp[n][k] = binomial(n - 1, k) + binomial(n - 1, k - 1) % 10007);
}

int main (int argc, const char* argv[]) {
    int n, k;

    scanf("%d %d", &n, &k);

    printf("%d\n", binomial(n, k) % 10007);

    return 0;
}