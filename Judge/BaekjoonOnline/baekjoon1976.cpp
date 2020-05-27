#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void init (int);
int find_set (int);
void union_set (int, int);

vector<int> p;

int main (int argc, char** argv) {
	int n, m;
	int isAdj;

	scanf("%d", &n);
	scanf("%d", &m);
	init(n);

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &isAdj);
			if (isAdj == 1) {
				union_set(i, j);
			}
		}
	}
	
	int u, v;
	bool isAvail = true;
	scanf("%d", &v);

	u = find_set(v);
	for (int i = 0; i < m - 1; ++ i) {
		scanf("%d", &v);
		if (u != find_set(v)) {
			isAvail = false;
		}
	}
	
	if (isAvail) printf("YES\n");
	else printf("NO\n");

	return 0;
}

void init (int n) {
	p.resize(n + 1);
	for (int i = 1; i <= n; ++ i) {
		p[i] = i;
	}
}

int find_set (int u) {
	if (u == p[u])
		return u;
	return p[u] = find_set(p[u]);
}

void union_set (int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a == b) return;

	if (a > b) swap(a, b);
	p[b] = a;
}