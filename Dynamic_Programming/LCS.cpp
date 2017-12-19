#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define MAX 101
using namespace std;

void LCS (char[MAX], char[MAX]);
void DFS (int, int);
bool isPromising (int, int);

int table[MAX][MAX];
stack<int> s;

// Longest Common Substring
int main (int argc, char** argv) {
	char str1[MAX], str2[MAX];

	gets(str1);
	gets(str2);

	LCS(str1, str2);

	return 0;
}

void LCS (char str1[], char str2[]) {
	int len1, len2;

	len1 = strlen(str1); len2 = strlen(str2);

	for (int i = 0; i <= max(len1, len2); ++ i) {
		table[i][0] = table[0][i] = 0;
	}

	for (int i = 1; i <= len1; ++ i) {
		for (int j = 1; j <= len2; ++ j) {
			if (str1[i - 1] == str2[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			} else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	} DFS(len1, len2);
	printf("%d\n", table[len1][len2]);
	
	while (!s.empty()) {
		printf("%c ", str1[s.top()]);
		s.pop();
	} printf("\n");
}

void DFS (int x, int y) {
	if (x > 0 && y > 0) {
		if (isPromising(x, y)) {
			s.push(x - 1);
			DFS (x - 1, y - 1);
		} else {
			if (table[x][y] == table[x - 1][y])
				DFS (x - 1, y);
			else if (table[x][y] == table[x][y - 1])
				DFS (x, y - 1);
		} 
	}
}

bool isPromising (int x, int y) {
	int dx[] = {-1, 0, -1};
	int dy[] = {0, -1, -1};
	bool promising = true;
	
	for (int i = 0; i < 3; ++ i) {
		if (table[x + dx[i]][y + dy[i]] != table[x][y] - 1) {
			promising = false;
			break;
		}
	} return promising;
}