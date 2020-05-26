#include <iostream>

using namespace std;

const int SIZE = 11;

typedef struct PLAYER {
    int stats[SIZE];
} Player;

int answer = 0;
bool visit[SIZE];
Player players[SIZE];

void DFS (int pos, int total) {
    if (pos == SIZE) {
        answer = max(answer, total);
        return;
    }
    
    for (int i = 0; i < SIZE; ++ i) {
        if (visit[i] || !players[pos].stats[i]) continue;
        
        visit[i] = true;
        DFS(pos + 1, total + players[pos].stats[i]);
        visit[i] = false;
    }
}

int main (int argc, const char *argv[]) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int test_case;
    
    cin >> test_case;
    
    while (test_case --) {
        answer = 0;
        
        for (int i = 0; i < SIZE; ++ i) {
            for (int j = 0; j < SIZE; ++ j) {
                cin >> players[i].stats[j];
            }
        }
        
        DFS(0, 0);
        
        cout << answer << '\n';
    }
    
    return 0;
}
