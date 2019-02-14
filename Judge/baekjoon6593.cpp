#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>
#define MAX 31
#define DIR 6

using namespace std;

int l, r, c;
int building[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];

queue<pair<pair<int, int>, int> > que;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};

void init () {
    memset(visited, 0, sizeof(visited));
    while (!que.empty()) que.pop();
}

bool is_promising (int x, int y, int d) {

    if (x < 0 || x >= r) return false;
    if (y < 0 || y >= c) return false;
    if (d < 0 || d >= l) return false;
    if (building[d][x][y] < 0) return false;
    if (visited[d][x][y] > 0) return false;

    return true;
}

int BFS () {

    while (!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int d = que.front().second;

        que.pop();

        if (building[d][x][y] > 0) {
            return visited[d][x][y];
        }

        for (int i = 0; i < DIR; ++ i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nd = d + dh[i];

            if (is_promising(nx, ny, nd)) {
                visited[nd][nx][ny] = visited[d][x][y] + 1;
                que.push({{nx, ny}, nd});
            }
        }
    }

    return 0;
}

int main (int argc, const char* argv[]) {
    char input;
    int dist;

    while (1) {

        scanf("%d %d %d%*c", &l, &r, &c);

        if ((l + r + c) == 0) break;

        init();

        for (int k = 0; k < l; ++k) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    input = getchar();

                    switch (input) {
                        case 'S': {
                            visited[k][i][j] = 1;
                            que.push({{i, j}, k});
                            break;
                        }
                        case 'E': {
                            building[k][i][j] = 1;
                            break;
                        }
                        case '#': {
                            building[k][i][j] = -1;
                            break;
                        }
                        default: {
                            building[k][i][j] = 0;
                            break;
                        }
                    }
                }
                getchar();
            }
            getchar();
        }

        dist = BFS();

        if (dist) {
            printf("Escaped in %d minute(s).\n", dist - 1);
        } else {
            printf("Trapped!\n");
        }
    }

    return 0;
}