#include <cstdio>
#define MAX_SIZE 21
#define DIR 4

using namespace std;

int r, c;
int table[MAX_SIZE][MAX_SIZE];
int visited[30];
int cnt = 1;
int answer = 1;
int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0, -1, 1};

bool isPromising (int x, int y) {
    bool promising = true;
    
    if (x < 0 || x >= r) promising = false;
    if (y < 0 || y >= c) promising = false;
    
    return promising;
}

void dfs (int x, int y, int len) {
    if (answer < len) answer = len;
    if (answer > 25) return;
    visited[table[x][y]] = 1;

    for (int i = 0; i < DIR; ++ i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (!isPromising(nx, ny)) continue;
        if (visited[table[nx][ny]]) continue;
        
        dfs(nx, ny, len + 1);
    }
    visited[table[x][y]] = 0;
}

int main (int argc, char* argv[]) {
    char tmp;
    
    scanf("%d %d%*c", &r, &c);
    for (int i = 0; i < r; ++ i) {
        for (int j = 0; j < c; ++ j) {
            tmp = getchar();
            table[i][j] = tmp - 'A';
        } getchar();
    }
    
    dfs(0, 0, 1);
    printf("%d\n", answer);
    
    return 0;
}
