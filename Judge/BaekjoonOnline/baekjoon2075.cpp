#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;

int main (int argc, const char *argv[]) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    priority_queue<long long, vector<long long>, greater<long long> > pque;
    
    cin >> n;
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            long long num;
            cin >> num;
            
            pque.push(num);
        }
        while (pque.size() > n) {
            pque.pop();
        }
    }
    
    cout << pque.top() << '\n';
    
    return 0;
}
