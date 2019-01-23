#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#define DIR 4
#define MAX 301

using namespace std;

typedef struct INFO {
    int x, y;
    int cnt;
} Info;

int n, m;
int chunk;
int area[MAX][MAX];
int visited[MAX][MAX];
queue<Info> list;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void init () {
    chunk = 0;
    memset(visited, 0, sizeof(visited));
}

bool is_promising (int x, int y) {

    if (x < 1 || x >= (n - 1)) return false;
    if (y < 1 || y >= (m - 1)) return false;
    if (area[x][y] <= 0) return false;
    if (visited[x][y]) return false;

    return true;
}

void check (int x, int y) {
    int cnt = 0;
    Info info;

    for (int i = 0; i < DIR; ++ i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (area[nx][ny] == 0) cnt ++;
    }

    if (cnt > 0) {
        info.x = x;
        info.y = y;
        info.cnt = cnt;
        list.push(info);
    }
}

void bfs (int x, int y) {
    queue<pair<int, int> > q;

    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < DIR; ++ i) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (is_promising(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

void melting () {
    Info info;

    for (int i = 1; i < (n - 1); ++ i) {
        for (int j = 1; j < (m - 1); ++ j) {
            if (area[i][j] > 0) {
                check(i, j);
            }
        }
    }

    while (!list.empty()) {
        info = list.front(); list.pop();

        int x = info.x;
        int y = info.y;
        int cnt = info.cnt;

        area[x][y] -= cnt;
        if (area[x][y] < 0) area[x][y] = 0;
    }
}

int main (int argc, char* argv[]) {
    int year;

    scanf("%d %d", &n, &m);

    for (int i =0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            scanf("%d", &area[i][j]);
        }
    }

    year = 0;
    while (1) {

        init();

        for (int i = 1; i < (n - 1); ++ i) {
            for (int j = 1; j < (m - 1); ++ j) {
                if (visited[i][j] == 0 && area[i][j] > 0) {
                    bfs(i, j);
                    chunk ++;
                }
            }
        }

        if (chunk >= 2 || chunk == 0) {
            break;
        }

        year ++;
        melting();
    }

    if (chunk >= 2) {
        printf("%d\n", year);
    } else {
        printf("0\n");
    }

    return 0;
}