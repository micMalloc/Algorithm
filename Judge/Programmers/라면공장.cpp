#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int idx = 0;
    priority_queue<int> que;
    
    for (int day = 0; day < k; ++ day) {
        if (idx < dates.size() && day == dates[idx]) {
            que.push(supplies[idx ++]);
        }
        
        if (stock == 0) {
            stock = que.top();
            que.pop();
            answer ++;
        }
        stock --;
    }
    
    return answer;
}
