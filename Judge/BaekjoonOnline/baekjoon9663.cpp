#include <cstdio>
#include <vector>
using namespace std;

void nQueens (int);
void walk (int);
bool isPromising (int);
int abs_(int);

vector<int> col;
int n, cnt;

int main (void) {
	scanf("%d", &n);	
	col.resize(n + 1);

	nQueens(0);
	printf("%d\n", cnt);

	return 0;
}

void nQueens (int i) {
	walk(i);
}
void walk (int i) {
	if (isPromising(i)) {
		if (i == n) cnt ++;
		else {
			for (int j = 1; j <= n; ++ j) {
				col[i + 1] = j;
				walk(i + 1);
			}
		}
	}
}
bool isPromising (int i) {
	int k = 1;
	bool promising = true;

	while (k < i && promising) {
		if (col[k] == col[i] || abs_(i - k) == abs_(col[i] - col[k]))
			promising = false;
		k ++;
	} return promising;
}

int abs_ (int val) {
	if (val < 0) val = val * -1;
	return val;
}