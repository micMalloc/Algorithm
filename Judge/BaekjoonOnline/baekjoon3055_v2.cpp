#include <cstdio>
#include <queue>
#include <memory.h>
#include <utility>
#define DIR 4
#define MAX 50
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int r, c;
int map[MAX][MAX];
int d[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> start, dest;
queue<pair<int, int> > wq;

void init () {
    memset(visited, false, sizeof(visited));
    memset(d, 0, sizeof(d));
}

bool isInRange (int x, int y) {
    bool inRange = true;
    
    if (x < 0 || x >= r) inRange = false;
    if (y < 0 || y >= c) inRange = false;
    if (map[x][y] == -2) inRange = false;
    return inRange;
}

void flooding () {
    
    while (!wq.empty()) {
        int x = wq.front().first;
        int y = wq.front().second;
        wq.pop();
        
        for (int i = 0; i < DIR; ++ i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!isInRange(nx, ny)) continue;
            if (map[nx][ny] == -1 || map[nx][ny] > 0) continue;
            
            map[nx][ny] = map[x][y] + 1;
            wq.push(make_pair(nx, ny));
        }
    }
}

bool bfs () {
    queue<pair<int, int> > q;
    int x = start.first;
    int y = start.second;
    
    visited[x][y] = true;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if (x == dest.first && y == dest.second) {
            return true;
        }
        for (int i = 0; i < DIR; ++ i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!isInRange(nx, ny) || visited[nx][ny]) continue;
            if (d[x][y] + 1 < map[nx][ny] - 1 || map[nx][ny] == -1) {
                visited[nx][ny] = true;
                d[nx][ny] = d[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    } return false;
}

int main (int argc, char* argv[]) {
    char input;
    
    scanf("%d %d%*c", &r, &c);
    for (int i = 0; i < r; ++ i) {
        for (int j = 0; j < c; ++ j) {
            input = getchar();
            
            switch (input) {
                case '.':
                    map[i][j] = 0;
                    break;
                case '*':
                    map[i][j] = 1;
                    wq.push(make_pair(i, j));
                    break;
                case 'X':
                    map[i][j] = -2;
                    break;
                case 'D': {
                    map[i][j] = -1;
                    dest = make_pair(i, j);
                    break;
                }
                case 'S': {
                    map[i][j] = 0;
                    start = make_pair(i, j);
                    break;
                }
                default:
                    break;
            }
        } getchar();
    } flooding();
    
//    for (int i = 0; i < r; ++ i) {
//        for (int j = 0; j < c; ++ j) {
//            printf("%d ", map[i][j]);
//        } printf("\n");
//    } flooding();
//    printf("\n");
//    for (int i = 0; i < r; ++ i) {
//        for (int j = 0; j < c; ++ j) {
//            printf("%d ", map[i][j]);
//        } printf("\n");
//    }
    
    init();
    if (bfs()) {
        printf("%d\n", d[dest.first][dest.second]);
    } else {
        printf("KAKTUS\n");
//        printf("\n");
//        for (int i = 0; i < r; ++ i) {
//            for (int j = 0; j < c; ++ j) {
//                printf("%d ", d[i][j]);
//            } printf("\n");
//        }
    }
    
    return 0;
}
