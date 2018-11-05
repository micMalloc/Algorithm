#include <cstdio>
#include <algorithm>

using namespace std;

int main (int argc, char* argv[]) {
    int n;
    int arr[1001];
    int dp[1001];
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) scanf("%d", arr + i);
    
    for (int i = 0; i < n; ++ i) dp[i] = 1;
    
    for (int i = 1; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    int length = 0;
    for (int i = 0; i < n; ++ i) {
        length = max(length, dp[i]);
    } printf("%d\n", length);
    
    return 0;
}

