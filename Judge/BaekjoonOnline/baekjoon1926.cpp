#include <cstdio>
#include <algorithm>
#define MAX 501
#define DIR 4

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];
int cnt;

bool is_promising (int x, int y) {
    bool promising = true;

    if (x < 0 || x >= n) promising = false;
    if (y < 0 || y >= m) promising = false;
    if (board[x][y] == 0) promising = false;
    if (visited[x][y]) promising = false;

    return promising;
}

void DFS (int x, int y) {

    visited[x][y] = true;
    cnt ++;

    for (int i = 0; i < DIR ; ++ i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (is_promising(nx, ny)) {
            DFS(nx, ny);
        }
    }
}

int main (int argc, const char* argv[]) {
    int chunk = 0;
    int max_val = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (board[i][j] && !visited[i][j]) {
                cnt = 0;
                DFS(i, j);
                chunk ++;

                max_val = max(max_val, cnt);
            }
        }
    }

    printf("%d\n", chunk);
    printf("%d", max_val);

    return 0;
}