#include <cstdio>
#include <queue>

using namespace std;

void BFS (int, int);

queue<int> q;
int visited[100001];

int main (void) {
	int n, k;

	scanf("%d %d", &n, &k);
	BFS(n, k);
	printf("%d\n", visited[k] - 1);

	return 0;
}

void BFS (int n, int k) {
	int crt;

	q.push(n); visited[n] = 1;
	while (!q.empty()) {
		crt = q.front(); q.pop();
		if (crt == k) break;
		
		if (crt > 0 && visited[crt - 1] == 0) {
			q.push(crt - 1);
			visited[crt - 1] = visited[crt] + 1;
		}
		if (crt < 100000 && visited[crt + 1] == 0) {
			q.push(crt + 1);
			visited[crt + 1] = visited[crt] + 1;
		}
		if (2 *crt <= 100000 && visited[2 * crt] == 0) {
			q.push(2 * crt);
			visited[2 * crt] = visited[crt] + 1;
		}
	}
}