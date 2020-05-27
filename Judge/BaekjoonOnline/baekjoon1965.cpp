#include <cstdio>
#include <algorithm>
#define MAX_SIZE 1001

using namespace std;

int dp[MAX_SIZE];
int box[MAX_SIZE];

int main (int argc, char* argv[]) {
    int n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", box + i);
    }
    
    for (int i = 0; i < n; ++ i) {
        dp[i] = 1;
    }
    
    for (int i = 1; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (box[j] < box[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; ++ i) {
        answer = max(answer, dp[i]);
    } printf("%d\n", answer);
    
    return 0;
}
