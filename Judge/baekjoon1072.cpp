#include<algorithm>
#include<iostream>

#define INT 0x7fff0000
#define MAX_ 1000000001

using namespace std;

typedef long long ll;
ll x, y, z; ll lft, rgt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (cin >> x >> y) {
        z = y * 100 / x;
        lft = 0;  rgt = MAX_;
        
        if (z >= 99) {
            printf("-1\n");
            continue;
        }
        
        while (lft <= rgt) {
            ll mid = (lft + rgt) / 2;
            ll per = (y + mid) * 100 / (x + mid);
            if (per > z) {
                rgt = mid - 1;
            }
            else
                lft = mid + 1;
        } cout << lft << '\n';
    }
    return 0;
}
