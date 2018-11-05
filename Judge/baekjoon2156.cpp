#include <cstdio>
#include <algorithm>
#define MAX_SIZE 10001

using namespace std;

int glass[MAX_SIZE];
int dp[MAX_SIZE];

int main (int argc, char* argv[]) {
    int n;
    int cmp;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", glass + i);
    }
    
    dp[1] = glass[1];
    dp[2] = glass[2] + glass[1];
    
    for (int i = 3; i <= n; ++ i) {
        cmp = max(glass[i] + dp[i - 2], dp[i - 1]);
        cmp = max(cmp, glass[i] + (glass[i - 1] + dp[i - 3]));
        dp[i] = cmp;
    } printf("%d\n", dp[n]);
    
    return 0;
}
