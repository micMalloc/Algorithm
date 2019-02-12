#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#define BUFSIZE 1001

using namespace std;

stack<char> LCS (char str1[], char str2[]) {
    int len1, len2;
    int dp[BUFSIZE][BUFSIZE];

    len1 = strlen(str1);
    len2 = strlen(str2);

    for (int i = 0; i <= max(len1, len2); ++ i) {
        dp[i][0] = dp[0][i] = 0;
    }

    for (int i = 1; i <= len1; ++ i) {
        for (int j = 1; j <= len2; ++ j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int i = len1;
    int j = len2;
    stack<char> lcs;

    while (dp[i][j] != 0) {
        if (dp[i][j] == dp[i][j - 1]) {
            j --;
        }
        else if (dp[i][j] == dp[i - 1][j]) {
            i --;
        }
        else if (dp[i][j] - 1 == dp[i - 1][j - 1]) {
            lcs.push(str1[i - 1]);
            i --;
            j --;
        }
    }

    return lcs;
}

int main (int argc, const char* argv[]) {

    stack<char> lcs;
    char str[2][BUFSIZE];

    for (int i = 0; i < 2; ++ i) {
        gets(str[i]);
    }

    lcs = LCS(str[0], str[1]);

    printf("%d\n", lcs.size());

    while (!lcs.empty()) {
        printf("%c", lcs.top());
        lcs.pop();
    }

    printf("\n");

    return 0;
}