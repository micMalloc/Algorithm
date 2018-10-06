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
int depth[MAX_SIZE][MAX_SIZE];
int answer;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void init () {
    memset(visited, false, sizeof(visited));
    memset(depth, 0, sizeof(depth));
}

bool isInRange (int x, int y) {
    bool inRange = true;
    
    if (x < 0 || x >= r) inRange = false;
    if (y < 0 || y >= c) inRange = false;
    return inRange;
}

void bfs (int x, int y) {
    queue<pair<int, int>> q;
    
    visited[x][y] = true;
    q.push(make_pair(x, y));
    
    depth[x][y] = 0;
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        for (int i = 0; i < DIR; ++ i) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if (!isInRange(nx, ny) || visited[nx][ny]) continue;
            
            if (map[nx][ny] == 1) {
                visited[nx][ny] = true;
                depth[nx][ny] = depth[cur_x][cur_y] + 1;
                q.push(make_pair(nx, ny));
                
                if (answer < depth[nx][ny]) {
                    answer = depth[nx][ny];
                }
            }
        }
    }
}

int main (int argc, char* argv[]) {
    char input;
    
    scanf("%d %d%*c", &r, &c);
    for (int i = 0; i < r; ++ i) {
        for (int j = 0; j < c; ++ j) {
            input = getchar();
            switch (input) {
                case 'W':
                    map[i][j] = 0;
                    break;
                case 'L':
                    map[i][j] = 1;
                    break;
                default:
                    break;
            }
        } getchar();
    }
    
    for (int i = 0; i < r; ++ i) {
        for (int j = 0; j < c; ++ j) {
            if (map[i][j]) {
                init();
                bfs(i, j);
            }
        }
    } printf("%d\n", answer);
    
    return 0;
}
