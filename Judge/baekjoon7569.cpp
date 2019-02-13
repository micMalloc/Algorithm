#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#define MAX 101
#define DIR 6

using namespace std;

int n, m, d;
int basket[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};

queue<pair<pair<int, int>, int> > que;

bool is_promising (int x, int y, int h) {

    if (x < 0 || x >= m) return false;
    if (y < 0 || y >= n) return false;
    if (h < 0 || h >= d) return false;
    if (visited[h][x][y]) return false;
    if (basket[h][x][y] == -1) return false;

    return true;
}

void BFS () {

    while (!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int h = que.front().second;

        que.pop();

        for (int i = 0; i < DIR; ++ i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nh = h + dh[i];

            if (is_promising(nx, ny, nh)) {
                visited[nh][nx][ny] = visited[h][x][y] + 1;
                que.push({{nx, ny}, nh});
            }
        }
    }
}

int check () {
    int days = 0;

    for (int k = 0; k < d; ++ k) {
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (visited[k][i][j] == 0 && basket[k][i][j] != -1) {
                    return 0;
                }
                else {
                    days = max(days, visited[k][i][j]);
                }
            }
        }
    }

    return days;
}

int main (int argc, const char* argv[]) {

    scanf("%d %d %d", &n, &m, &d);

    for (int k = 0; k < d; ++ k) {
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d", &basket[k][i][j]);

                if (basket[k][i][j] == 1) {
                    visited[k][i][j] = 1;
                    que.push({{i, j}, k});
                }
            }
        }
    }

    BFS();

    int days = check();

    if (days) {
        printf("%d\n", days - 1);
    }
    else {
        printf("-1\n");
    }

    return 0;
}