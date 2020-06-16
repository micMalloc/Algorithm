#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 5 * 1e5 + 1;

int main (int argc, const char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    int h;
    
    vector<int> stalagmite, stalactite;
    
    cin >> n >> m;
    
    for (int i = 0; i < n / 2; ++ i) {
        cin >> h;
        stalagmite.push_back(h);
        cin >> h;
        stalactite.push_back(h);
    }
    
    sort(stalagmite.begin(), stalagmite.end());
    sort(stalactite.begin(), stalactite.end());
    
    int min_cnt = MAX;
    int cnt = 1;
    int tmp;
    
    for (h = 1; h <= m; ++ h) {
        tmp = stalagmite.size() - (lower_bound(stalagmite.begin(), stalagmite.end(), h) - stalagmite.begin());
        tmp += stalactite.size() - (upper_bound(stalactite.begin(), stalactite.end(), m - h) - stalactite.begin());
        
        if (min_cnt == tmp) {
            cnt ++;
        }
        else if (min_cnt > tmp) {
            min_cnt = tmp;
            cnt = 1;
        }
    }
    
    cout << min_cnt << ' ' << cnt << '\n';
    
    return 0;
}

