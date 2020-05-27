#include <cstdio>
using namespace std;

int idx[1000000];

int main (int argc, char* argv[]) {
	int t, a, b;
	char c;
	
	scanf("%d%*c", &t);
	while (t --) {
		int ptr = 0;
		scanf("%d %d%*c", &a, &b);
		c = getchar();
		while (c != '\n') {
			idx[ptr ++] = (a * (c - 'A') + b) % 26;
			c = getchar();
		}
		for (int i = 0; i < ptr; ++ i) {
			printf("%c", 'A' + idx[i]);
		} printf("\n");
	}
	return 0;
}