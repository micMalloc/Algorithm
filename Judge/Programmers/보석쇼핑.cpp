#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int id = 1;
    long long FULL = 0;
    unordered_map<string, int> jewel;
    
    for (int i = 0; i < gems.size(); ++ i) {
        if (jewel.find(gems[i]) == jewel.end()) {
            FULL += id;
            jewel[gems[i]] = id ++;
        }
    }
    
    cout << FULL << '\n';
    
    int left, right;
    int len = 1e9;
    int visit[100005] = {false, };
    
    long long sum = 0;
    
    left = right = 0;
    vector<pair<int, int> > promising;
    
    visit[jewel[gems[right]]] = 1;
    sum += jewel[gems[right]];
    
    while (left <= right && right < gems.size() - 1) {
        if (sum < FULL) {
            right ++;
            if (visit[jewel[gems[right]]] == 0) {
                sum += jewel[gems[right]];
            }
            visit[jewel[gems[right]]] ++;
        }
        
        if (sum == FULL) {
            if (len > (right - left)) {
                len = (right - left);
                if (!promising.empty()) {
                    promising.clear();
                }
            }
            promising.push_back({left, right});
            
            visit[jewel[gems[left]]] --;
            if (visit[jewel[gems[left]]] == 0) {
                sum -= jewel[gems[left]];
            }
            left ++;
        }
    }
    
    sort(promising.begin(), promising.end());
    
    answer.push_back(promising[0].first + 1);
    answer.push_back(promising[0].second + 1);
    
    return answer;
}
