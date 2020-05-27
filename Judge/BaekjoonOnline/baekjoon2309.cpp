#include <cstdio>
#include <algorithm>
#define MAX 10

using namespace std;

int chanHo[MAX];

int main(int argc, char* argv[]) {
	int sum = 0;
	bool find = false;

	for (int i = 1; i < MAX; ++i) {
		scanf("%d", chanHo + i);
		sum += chanHo[i];
	}

	for (int i = 1; i < MAX - 1; ++i) {
		for (int j = i + 1; j < MAX; ++j) {
			if (sum - (chanHo[i] + chanHo[j]) == 100) {
				chanHo[i] = chanHo[j] = -1;
				find = true;
				break;
			}
		} if (find) break;
	} sort(chanHo + 1, chanHo + MAX);

	for (int i = 3; i < MAX; ++i) {
		printf("%d\n", chanHo[i]);
	}

	return 0;
}