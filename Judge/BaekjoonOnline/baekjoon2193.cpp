#include <cstdio>
#define MAX_SIZE 91

long long int dp[MAX_SIZE];

long long int counting (int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;

    if (dp[n]) return dp[n];

    return (dp[n] = counting(n - 1) + counting(n - 2));
}

int main (int argc, const char* argv[]) {
    int n;

    scanf("%d", &n);

    printf("%lld\n", counting(n));

    return 0;
}