#include <cstdio>
#include <algorithm>
#include <cstring>
#define BUF 101
#define MAX 3

using namespace std;

int dp[BUF][BUF][BUF];

bool is_promising (char a, char b, char c) {

    return ((a == b) && (b == c) && (a == c));
}

int main (int argc, const char* argv[]) {
    int size[MAX];
    char str[MAX][BUF];

    for (int i = 0; i < MAX; ++ i) {
        gets(str[i]);
        size[i] = strlen(str[i]);
    }

    for (int k = 1; k <= size[0]; ++ k) {
        for (int i = 1; i <= size[1]; ++ i) {
            for (int j = 1; j <= size[2]; ++ j) {
                if (is_promising(str[0][k - 1], str[1][i - 1], str[2][j - 1])) {
                    dp[k][i][j] = dp[k - 1][i - 1][j - 1] + 1;
                }
                else {
                    dp[k][i][j] = max(dp[k - 1][i][j], max(dp[k][i - 1][j], dp[k][i][j - 1]));
                }
            }
        }
    }

    printf("%d\n", dp[size[0]][size[1]][size[2]]);

    return 0;
}