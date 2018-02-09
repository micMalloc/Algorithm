#include <cstdio>
using namespace std;

int table[100001];

int main (int argc, char** argv) {
	int n;
	int a, b;
	int count = 0;

	scanf("%d", &n);

	while (n --) {
		scanf("%d.%d", &a, &b);
		table[a * 1000 + b] ++;
	}

	for (int i = 0; i < 100001; ++ i) {
		while (table[i]) {
			table[i] --;
			count ++;
			printf("%d.%03d\n", i / 1000, i % 1000);
			if (count == 7) return 0;
		}
	}

	return 0;
}