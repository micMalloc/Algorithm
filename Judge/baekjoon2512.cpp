#include <cstdio>
#define MAX_SIZE 10001
#define _MAX 1000000001

typedef long long VeryLong;

int main (int argc, char* argv[]) {
    int n;
    int budget[MAX_SIZE];
    VeryLong m;
    VeryLong lft, rgt, mid;
    VeryLong answer, total;
    
    scanf("%d", &n);
    
    answer = total = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d", budget + i);
        if (answer < budget[i])
            answer = budget[i];
        total += budget[i];
    }
    
    scanf("%lld", &m);
    if (total <= m) {
        printf("%lld\n", answer);
        return 0;
    }
    
    answer = 0;
    lft = 0; rgt = _MAX;
    
    while (lft <= rgt) {
        mid = (lft + rgt) / 2;
        
        total = 0;
        for (int i = 0; i < n; ++ i) {
            if (budget[i] <= mid) {
                total += budget[i];
            } else {
                total += mid;
            }
        }
        
        if (total <= m) {
            if (answer < mid)
                answer = mid;
            lft = mid + 1;
        } else {
            rgt = mid - 1;
        }
    } printf("%lld\n", answer);
    
    return 0;
}
