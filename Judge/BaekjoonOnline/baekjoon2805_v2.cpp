#include <cstdio>
#define _MAX 1000000001
#define MAX_SIZE 1000001

typedef long long VeryLong;

VeryLong n, m;
VeryLong tree[MAX_SIZE];

VeryLong cutting (VeryLong height) {
    VeryLong total = 0;
    
    for (int i = 0; i < n; ++ i) {
        if (tree[i] > height) {
            total += tree[i] - height;
        }
    } return total;
}

int main (int argc, char* argv[]) {
    VeryLong total, result = 0;
    VeryLong lft, rgt, mid = 0;
    
    scanf("%lld %lld", &n, &m);
    
    for (int i = 0; i < n; ++ i) {
        scanf("%lld", tree + i);
    }
    
    lft = 0; rgt = _MAX;
    
    while (lft <= rgt) {
        mid = (lft + rgt) / 2;
        
        total = cutting(mid);
        if (total >= m) {
            if (result < mid)
                result = mid;
            lft = mid + 1;
        } else {
            rgt = mid - 1;
        }
    } printf("%lld\n", result);
    return 0;
}
