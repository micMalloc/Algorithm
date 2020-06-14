#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct POINT {
    int x, y;
} Point;

typedef struct PATH {
    Point p;
    int visit;
} Path;

int n, m;
vector<string> board;

int get_size(int bit) {
    int size = 0;
    
    for (int i = 0; i < 27; ++ i) {
        if (bit & (1 << i)) size ++;
    }
    
    return size;
}

int BFS (Point start) {
    const int DIR = 4;
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    int answer = 0;
    queue<Path> que;
    
    que.push({start, 0 | (1 << (board[start.x][start.y] - 'A'))});
    
    while (!que.empty()) {
        int x = que.front().p.x;
        int y = que.front().p.y;
        int visit = que.front().visit;
        int size = get_size(visit);
        
        que.pop();
        
        if (answer < size) {
            answer = size;
        }
        
        if (answer > 25) return answer;
        
        for (int i = 0; i < DIR; ++ i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;
            if (visit & (1 << (board[nx][ny] - 'A'))) continue;
            
            que.push({{nx, ny}, visit | (1 << (board[nx][ny] - 'A'))});
        }
    }
    
    return answer;
}

int main () {
    
    cin >> n >> m;
    
    string row;
    
    for (int i = 0; i < n; ++ i) {
        cin >> row;
        board.push_back(row);
    }
    
    cout << BFS({0, 0}) << endl;
    
    return 0;
}
