#include <algorithm>
#include <string>
#include <vector>

using namespace std;

unsigned long long binary_search (int n, vector<int> times) {
    unsigned long long limit = 0;
    unsigned long long left, right, mid;
    unsigned long long cnt = 0;
    
    left = 1;
    right = times[times.size() - 1] * n;
    
    while (left <= right) {
        mid = (left + right) >> 1;
        
        cnt = 0;
        for (int i = 0; i < times.size(); ++ i) {
            cnt += mid / times[i];
        }
        
        if (cnt >= n) {
            if (limit) {
                limit = min(limit, mid);
            }
            else {
                limit = mid;
            }
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return limit;
}

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    
    sort(times.begin(), times.end());
    
    answer = binary_search(n, times);
    
    return answer;
}
