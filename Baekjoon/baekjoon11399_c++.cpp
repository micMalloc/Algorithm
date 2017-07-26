#include <iostream>
#include <algorithm>

using namespace std;

int main (void) {
	int n;
	int p[1000];

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
		scanf("%d", &p[i]);
	sort (p, p + n);
	for (int i = 1; i < n; ++ i)
		p[i] = p[i] + p[i - 1];

	int total = 0;
	for (int i = 0; i < n; ++ i)
		total += p[i];
	printf("%d\n", total);

	return 0;
}