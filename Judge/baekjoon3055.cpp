#include <cstdio>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAX_SIZE 50
#define DIR 4
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c;
int d[MAX_SIZE][MAX_SIZE];
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
pair<int, int> start, dest;

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

void flooding (int depth) {
    
    for (int i = 0; i < r; ++ i) {
        for (int j = 0; j < c; ++ j) {
            if (map[i][j] == depth) {
                for (int k = 0; k < DIR; ++ k) {
                    int adj_x = i + dx[k];
                    int adj_y = j + dy[k];
                    
                    if (isInRange(adj_x, adj_y) && map[adj_x][adj_y] == 0) {
                        map[adj_x][adj_y] = map[i][j] + 1;
                    }
                }
            }
        }
    }
}

bool bfs (int x, int y) {
    queue<pair<int, int>> q;
    int depth = 0;
    
    visited[x][y] = true;
    q.push(make_pair(x, y));
    
    d[x][y] = 0;
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        if (cur_x == dest.first && cur_y == dest.second) {
            return 1;
        }
        depth ++;
        flooding(depth);
        for (int i = 0; i < DIR; ++ i) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if (!isInRange(nx, ny) || visited[nx][ny]) continue;
            
            if (map[nx][ny] == 0 || map[nx][ny] == -1) {
                visited[nx][ny] = true;
                d[nx][ny] = d[cur_x][cur_y] + 1;
                q.push(make_pair(nx, ny));
            }
        } //flooding(depth);
    } return 0;
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
    } init();
    
    for (int i = 0; i < r; ++ i) {
        for (int j = 0; j < c; ++ j) {
            printf("%d ", map[i][j]);
        } printf("\n");
    }
    
    if (bfs(start.first, start.second)) {
        printf("%d\n", d[dest.first][dest.second]);
    } else {
        printf("KAKTUS\n");
    }
    return 0;
}
