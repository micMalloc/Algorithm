#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool is_adjacent (string u, string v) {
    int cnt = 0;
    
    for (int i = 0; i < v.size(); ++ i) {
        if (u[i] != v[i]) {
            cnt ++;
        }
        if (cnt > 1) {
            return 0;
        }
    }
    return 1;
}

int BFS (string begin, string target, vector<string> words) {
    unordered_map<string, int> idx;
    int visit[55] = {0, };
    int id = 0;
    queue<string> que;
    
    idx[begin] = id ++;
    idx[target] = id ++;
    
    for (int i = 0; i < words.size(); ++ i) {
        idx[words[i]] = id ++;
    }
    
    visit[idx[begin]] = 1;
    que.push(begin);
    
    while (!que.empty()) {
        string u = que.front();
        
        que.pop();
        
        if (u.compare(target) == 0) {
            return visit[idx[target]] - 1;
        }
        
        for (int i = 0; i < words.size(); ++ i) {
            string v = words[i];
            
            if (visit[idx[v]]) continue;
            if (is_adjacent(u, v)) {
                visit[idx[v]] = visit[idx[u]] + 1;
                que.push(v);
            }
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    answer = BFS(begin, target, words);
    
    return answer;
}
