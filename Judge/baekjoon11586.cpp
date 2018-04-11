#include <cstdio>
#define BUFSIZE 100
using namespace std;

int main (int argc, char* argv[]) {
	int n, k;
	char table[BUFSIZE][BUFSIZE + 1];

	scanf("%d%*c", &n);
	for (int i = 0; i < n; ++ i) {
		gets(table[i]);
	} scanf("%d", &k);

	switch (k)
	{
	case 1: {
		for (int i = 0; i < n; ++ i) {
			puts(table[i]);
		} break;
	}
	case 2: {
		for (int i = 0; i < n; ++ i) {
			for (int j = n - 1; j >= 0; -- j) {
				putchar(table[i][j]);
			} putchar('\n');
		} break;
	}
	case 3: {
		for (int i = n - 1; i >= 0; -- i) {
			puts(table[i]);
		} break;
	}
	default:
		break;
	}
	return 0;
}