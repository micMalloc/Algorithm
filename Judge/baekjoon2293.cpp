#include <cstdio>
#define MAX 501
#define MAX_VAL 10001

using namespace std;

int n, k;
int coin[MAX];
int dp[MAX_VAL];

int main (int argc, const char* argv[]) {

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++ i) {
        scanf("%d", coin + i);
    }

    dp[0] = 1;

    for (int i = 1; i <= n; ++ i) {
        for (int j = coin[i]; j <= k; ++ j) {
            dp[j] += dp[j - coin[i]];
        }
    }

    printf("%d\n", dp[k]);

    return 0;
}