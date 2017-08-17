#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
void initData();
void BFS ();

queue<pair<int, int> > q;
int visited[300][300], n;
pair<int, int> start, target;

int main (void) {
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		scanf("%d %d", &start.first, &start.second);
		scanf("%d %d", &target.first, &target.second);
		BFS();
		printf("%d\n", visited[target.first][target.second] - 1);
		initData();
	}
	return 0;
}

void initData () {
	for (int i = 0; i < 300; ++ i)
		for (int j = 0; j < 300; ++ j)
			visited[i][j] = 0;
	while (!q.empty()) q.pop();
}

void BFS () {
	int x, y;

	q.push(start);
	visited[start.first][start.second] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == target.first && y == target.second) break;
		if (x - 1 >= 0 && y - 2 >= 0 && visited[x - 1][y - 2] == 0) {
			q.push(make_pair(x - 1, y - 2));
			visited[x - 1][y - 2] = visited[x][y] + 1;
		}
		if (x - 2 >= 0 && y - 1 >= 0 && visited[x - 2][y - 1] == 0) {
			q.push(make_pair(x - 2, y - 1));
			visited[x - 2][y - 1] = visited[x][y] + 1;
		}
		if (x - 1 >= 0 && y + 2 <= (n - 1) && visited[x - 1][y + 2] == 0) {
			q.push(make_pair(x - 1, y + 2));
			visited[x - 1][y + 2] = visited[x][y] + 1;
		}
		if (x - 2 >= 0 && y + 1 <= (n - 1) && visited[x - 2][y + 1] == 0) {
			q.push(make_pair(x - 2, y + 1));
			visited[x - 2][y + 1] = visited[x][y] + 1;
		}
		if (x + 1 <= (n - 1) && y - 2 >= 0 && visited[x + 1][y - 2] == 0) {
			q.push(make_pair(x + 1, y - 2));
			visited[x + 1][y - 2] = visited[x][y] + 1;
		}
		if (x + 2 <= (n - 1) && y - 1 >= 0 && visited[x + 2][y - 1] == 0) {
			q.push(make_pair(x + 2, y - 1));
			visited[x + 2][y - 1] = visited[x][y] + 1;
		}
		if (x + 1 <= (n - 1) && y + 2 <= (n - 1) && visited[x + 1][y + 2] == 0) {
			q.push(make_pair(x + 1, y + 2));
			visited[x + 1][y + 2] = visited[x][y] + 1;
		}
		if (x + 2 <= (n - 1) && y + 1 <= (n - 1) && visited[x + 2][y + 1] == 0) {
			q.push(make_pair(x + 2, y + 1));
			visited[x + 2][y + 1] = visited[x][y] + 1;
		}
	}
}