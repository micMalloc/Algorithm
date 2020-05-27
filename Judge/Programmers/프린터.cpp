#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct DOC {
    int pos;
    int val;
} Doc;

queue<Doc> que;

bool cmp (const int a, const int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for (int i = 0; i < priorities.size(); ++ i) {
        que.push({i, priorities[i]});
    }
    
    sort(priorities.begin(), priorities.end(), cmp);
    
    int idx = 0;
    
    while (true) {
        if (priorities[idx] != que.front().val) {
            que.push(que.front());
            que.pop();
        }
        else {
            idx ++;
            if (que.front().pos == location) {
                answer = idx;
                break;
            }
            que.pop();
        }
        
        if (idx == priorities.size()) {
            break;
        }
    }
    
    return answer;
}
