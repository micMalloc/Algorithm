#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 501;
const int U = 0;
const int R = 1;
const int D = 2;
const int L = 3;
const int T = 2;
const int F = 1;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

typedef struct POINT {
    int x, y;
} Point;

int n, m;
string maze[MAX];
bool visit[MAX][MAX][5] = {false, };
int dp[MAX][MAX];

int DFS (Point u) {
    int x = u.x;
    int y = u.y;
    int nx, ny;
    int dir;
    
    if (dp[x][y]) return dp[x][y];
    
    switch (maze[x][y]) {
        case 'U': {
            nx = x + dx[U];
            ny = y + dy[U];
            dir = U;
            break;
        }
        case 'D': {
            nx = x + dx[D];
            ny = y + dy[D];
            dir = D;
            break;
        }
        case 'R': {
            nx = x + dx[R];
            ny = y + dy[R];
            dir = R;
            break;
        }
        case 'L': {
            nx = x + dx[L];
            ny = y + dy[L];
            dir = L;
            break;
        }
        default:
            break;
    }
    
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) return T;
    if (visit[nx][ny][dir]) return F;
    
    visit[nx][ny][dir] = true;
    dp[x][y] = DFS({nx, ny});
    visit[nx][ny][dir] = false;
    
    return dp[x][y];
}

void init () {
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            for (int k = 0; k < 4; ++ k) {
                visit[i][j][k] = false;
            }
        }
    }
}

int main (int argc, const char *argv[]) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int result = 0;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++ i) {
        cin >> maze[i];
    }
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (dp[i][j]) {
                result += (dp[i][j] - 1);
            }
            else {
                visit[i][j][4] = true;
                result += (DFS({i, j}) - 1);
                visit[i][j][4] = false;
            }
        }
    }
    
    cout << result << '\n';
    
    return 0;
}

