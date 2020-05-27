#include <cstdio>
#include <vector>
using namespace std;

int find_set (int);
void union_set (int, int);

vector<int> parent;

int main (int argc, char** argv) {
	int n, m;
	int a, b, code;

	scanf("%d %d", &n, &m);
	parent.resize(n + 1);

	for (int i = 1; i <= n; ++ i) {
		parent[i] = i;
	}

	while (m --) {
		scanf("%d %d %d", &code, &a, &b);
		switch (code) {
		case 0: {
			union_set(a, b);
			break;
		}
		case 1: {
			if (find_set(a) == find_set(b)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
			break;
		}
		default:
			break;
		}
	}
	
	return 0;
}

int find_set (int u) {
	if (u == parent[u]) {
		return u;
	} return parent[u] = find_set(parent[u]);
}

void union_set (int a, int b) {
	int p, q;

	p = find_set(a);
	q = find_set(b);

	if (p != q) {
		parent[p] = q;
	}
}