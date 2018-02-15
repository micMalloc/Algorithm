#include <cstdio>
#include <vector>
using namespace std;

vector<int> data;
vector<int> s;

int main (int argc, char** argv) {
	int n, m;
	int l, r;

	scanf("%d %d", &n, &m);
	data.resize(n + 1, 0);
	s.resize(n + 1, 0);

	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &data[i]);
		s[i] = s[i - 1] + data[i];
	}
	
	while (m --) {
		scanf("%d %d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}
