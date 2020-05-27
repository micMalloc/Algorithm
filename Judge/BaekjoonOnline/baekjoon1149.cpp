#include <cstdio>
#include <algorithm>
#define ROW 1000
#define COL 3

using namespace std;

int cost[ROW][COL];
int dp[ROW][COL];

int main (int argc, char* argv[]) {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < COL; ++ j) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < COL; ++ i) {
        dp[0][i] = cost[0][i];
    }

    for (int i = 1; i < n; ++ i) {
        for (int j = 0; j < COL; ++ j) {
            dp[i][j] = cost[i][j] + min(dp[i - 1][(j + 1) % COL], dp[i - 1][(j + 2) % COL]);
        }
    }

    printf("%d", min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])));

    return 0;
}