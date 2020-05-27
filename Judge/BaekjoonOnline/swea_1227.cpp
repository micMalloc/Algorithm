#include <stdio.h>

const int MAX_SIZE = 100;
const int DIR = 4;

typedef struct POINT {
    int x, y;
} Point;

int map[MAX_SIZE][MAX_SIZE];

int BFS (const Point src, const Point dest) {
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    int visit[MAX_SIZE][MAX_SIZE] = {0,};
    Point que[MAX_SIZE * MAX_SIZE];
    int front, rear;

    front = rear = -1;

    que[++ rear] = src;
    visit[src.x][src.y] = 1;

    while (front != rear) {
        front ++;

        int x = que[front].x;
        int y = que[front].y;

        if (x == dest.x && y == dest.y) return 1;

        for (int i = 0; i < DIR; ++ i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= MAX_SIZE) continue;
            if (ny < 0 || ny >= MAX_SIZE) continue;
            if (visit[nx][ny] == 1 || map[nx][ny] == 1) continue;

            que[++ rear] = {nx, ny};
            visit[nx][ny] = 1;
        }
    }

    return 0;
}

int main (int argc, const char* argv[]) {
    int test_case = 10;
    int t;
    Point src, dest;

    while (test_case --) {
        scanf("%d\n", &t);

        // Read Data
        for (int i = 0; i < MAX_SIZE; ++ i) {
            for (int j = 0; j < MAX_SIZE; ++ j) {
                scanf("%1d", &map[i][j]);

                if (map[i][j] == 2) {
                    src = {i, j};
                }
                if (map[i][j] == 3) {
                    dest = {i, j};
                }
            }
        }

        if (BFS(src, dest)) {
            printf("#%d 1\n", t);
        }
        else {
            printf("#%d 0\n", t);
        }
    }

    return 0;
}