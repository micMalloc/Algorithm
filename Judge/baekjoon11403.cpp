#include <cstdio>
#define MAX  101
using namespace std;

void Warshall (int);
void print_result (int);

int adj[MAX][MAX];

int main (int argc, char** argv) {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &adj[i][j]);
		}
	} Warshall(n);
	print_result(n);

	return 0;
}

void Warshall (int n) {
	int i, j, k;

	for (int k = 0; k < n; ++ k) {
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				adj[i][j] = adj[i][j] | (adj[i][k + 1] & adj[k + 1][j]);
			}
		}
	}
}

void print_result (int n) {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j)
			printf("%d ", adj[i][j]);
		printf("\n");
	}
}