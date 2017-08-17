#include <cstdio>
#include <queue>
using namespace std;

int main (void) {
	int m, n;
	int crt, count = 0;
	queue<int> q;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++ i) q.push(i);

	printf("<");
	while (!q.empty()) {
		crt = q.front(); q.pop();
		count ++;
		if (count % m) q.push(crt);
		else {
			n --;
			if (n) printf("%d, ", crt);
			else printf("%d", crt);
		}
	} printf(">\n");

	

	return 0;
}