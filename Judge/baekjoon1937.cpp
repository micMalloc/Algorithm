#include <cstdio>
#include <algorithm>
#define MAX 501
#define DIR 4

using namespace std;

int n;
int area[MAX][MAX];
int dp[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_in_range (int x, int y) {

    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= n) return false;

    return true;
}

int dfs (int x, int y) {

    if (dp[x][y]) {
        return dp[x][y];
    }

    dp[x][y] = 1;
    for (int i = 0; i < DIR; ++ i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!is_in_range(nx, ny)) continue;

        if (area[x][y] < area[nx][ny]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }

    return dp[x][y];
}

int main (int argc, char* argv[]) {
    int length = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            scanf("%d", &area[i][j]);
        }
    }

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (dp[i][j] == 0) {
                length = max(length, dfs(i, j));
            }
        }
    } printf("%d\n", length);

    return 0;
}