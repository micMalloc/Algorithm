#include <cstdio>

int dp[1001];

int get_answer (int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (dp[x] != 0) return dp[x];

    return dp[x] = (get_answer(x - 1) + get_answer(x - 2)) % 10007;
}

int main (int argc, const char* argv[]) {
    int n;

    scanf("%d", &n);
    printf("%d", get_answer(n));

    return 0;
}