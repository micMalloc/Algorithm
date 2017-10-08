#include <cstdio>
#include <queue>

using namespace std;

queue<pair<int, int> > q;

int main (void) {
	int t;
	int n, idx, p, max;
	pair<int, int> target;
	
	scanf("%d", &t);

	while (t --) {
		scanf("%d %d", &n, &idx);
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &p);
			if (i == idx) target = make_pair(i, p);
			
			q.push(make_pair(i, p));

			if (i == 0) max = p;
			else if (max < p) max = p;
		}

		int count = 1, crt_p;

		crt_p = q.front().second;
		while (crt_p != max) {
			q.push(q.front());
			q.pop();
			crt_p = q.front().second;
		}
		while (!q.empty()) {
			if (target == q.front()) {
				printf("%d\n", count);
				break;
			} q.pop(); count ++;
		}
		while (!q.empty()) q.pop();
	}
	return 0;
}