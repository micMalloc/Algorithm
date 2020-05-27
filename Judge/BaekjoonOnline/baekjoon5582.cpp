#include <iostream>
#include <algorithm>
#define _BUFSIZE 4001

using namespace std;

int dp[_BUFSIZE][_BUFSIZE];

int LCS (string str1, string str2) {
    int max_length;
    int len1, len2;

    len1 = str1.length();
    len2 = str2.length();

    max_length = 0;

    for (int i = 0; i <= max(len1, len2); ++ i) {
        dp[i][0] = dp[0][i] = 0;
    }

    for (int i = 1; i <= len1; ++ i) {
        for (int j = 1; j <= len2; ++ j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_length = max(max_length, dp[i][j]);
            }
        }
    }

    return max_length;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);

    string str1;
    string str2;

    cin >> str1;
    cin >> str2;

    printf("%d\n", LCS(str1, str2));

    return 0;
}