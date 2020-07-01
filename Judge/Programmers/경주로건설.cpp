#include <string>
#include <vector>
#include <queue>

using namespace std;

const int S = 100;
const int C = 500;

typedef struct POINT {
    int x, y;
} Point;

typedef struct Path {
    Point p;
    int dir;
    int co;
} Path;

int n, m;
int visit[30][30][5];

void init () {
    for (int i = 0; i < 30; ++ i) {
        for (int j = 0; j < 30; ++ j) {
            for (int k = 0; k < 5; ++ k)
                visit[i][j][k] = 1e9;
        }
    }
}

int BFS (Point start, vector<vector<int>> board) {
    queue<Path> que;
    int answer = 1e9;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    init();
    
    visit[start.x][start.y][0] = 0;
    visit[start.x][start.y][1] = 0;
    
    for (int i = 0; i < 2; ++ i) {
        int nx = start.x + dx[i];
        int ny = start.y + dy[i];
        int nd = i % 2;
        int cost = S;
            
        if (board[nx][ny]) continue;
        visit[nx][ny][i] = cost;
        que.push({{nx, ny}, nd});
    }
    
    while (!que.empty()) {
        int x = que.front().p.x;
        int y = que.front().p.y;
        int dir = que.front().dir;
        
        que.pop();
        
        if (x == n - 1 && y == m - 1) {
            if (answer > visit[x][y][dir]) {
                answer = visit[x][y][dir];
            }
        }
        
        for (int i = 0; i < 4; ++ i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int cost;
            
            if (dir % 2 == i % 2) {
                cost = visit[x][y][dir] + S;
            }
            else {
                cost = visit[x][y][dir] + S + C;
            }
            
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;
            if (board[x][y]) continue;
            if (visit[nx][ny][i] < cost) {
                continue;
            }
            
            visit[nx][ny][i] = cost;
            que.push({{nx, ny}, i});
        }
    }
    
    return answer;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    n = board.size();
    m = board[0].size();
    
    answer = BFS({0, 0}, board);
    
    return answer;
}
