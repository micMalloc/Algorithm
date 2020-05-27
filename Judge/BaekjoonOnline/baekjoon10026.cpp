#include <cstdio>
#include <queue>
#include <utility>
#include <memory.h>
#define MAX_SIZE 101
#define DIR 4

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int grid[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int n;
int cnt;

void init () {
    cnt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (grid[i][j] == 2) {
                grid[i][j] --;
            }
        }
    }
}

bool isPromising (int x, int y) {
    bool promising = true;
    
    if (x < 0 || x >= n) promising = false;
    if (y < 0 || y >= n) promising = false;
    if (visited[x][y]) promising = false;
    
    return promising;
}

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    
    visited[x][y] = true;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        for (int i = 0; i < DIR; ++ i) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if (!isPromising(nx, ny)) continue;
            
            if (grid[cur_x][cur_y] == grid[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main (int argc, char* argv[]) {
    char input;
    
    scanf("%d%*c", &n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            input = getchar();
            switch (input) {
                case 'R':
                    grid[i][j] = 1;
                    break;
                case 'G':
                    grid[i][j] = 2;
                    break;
                case 'B':
                    grid[i][j] = 3;
                    break;
                default:
                    break;
            }
        } getchar();
    }
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt ++;
            }
        }
    } printf("%d ", cnt);
    
    init();
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt ++;
            }
        }
    } printf("%d\n", cnt);
    
    return 0;
}
