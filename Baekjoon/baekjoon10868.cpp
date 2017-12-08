#include <cstdio>
#include <vector>
#define INF 1000000001
using namespace std;

const int MAX = 10;

int make_segment_tree (int, int, int);
int find_min (int, int, int, int, int);

vector<int> data;
vector<int> segTree;

int main () {
	int n, m;
	int left, right;

	scanf("%d %d", &n, &m);
	data.resize(n + 1);
	segTree.resize(4 * n);
	segTree[0] = 0;
	
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &data[i]);
	} make_segment_tree(1, 0, n - 1);

	for (int i = 0; i < m; ++ i) {
		scanf("%d %d", &left, &right);
		printf("%d\n", find_min(left - 1, right - 1, 0, n - 1, 1));
	}

	return 0;
}

int make_segment_tree (int loca, int start, int end) {
	int mid;
	int leftVal, rightVal;

	if (start < end) {
		mid = (start + end) / 2;

		leftVal = make_segment_tree(2 * loca, start, mid);
		rightVal = make_segment_tree((2 * loca) + 1, mid + 1, end);

		if (leftVal < rightVal) segTree[loca] = leftVal;
		else segTree[loca] = rightVal;
	} else {
		segTree[loca] = data[start];
	} return segTree[loca];
}

int find_min (int left, int right, int start, int end, int loca) {
	int mid;
	int leftVal, rightVal;

	if (left > end || right < start) return INF;

	if (left <= start && right >= end) return segTree[loca];

	mid = (start + end) / 2;
	leftVal = find_min(left, right, start, mid, 2 * loca);
	rightVal = find_min(left, right, mid + 1, end, (2 * loca) + 1);
	if (leftVal < rightVal) return leftVal;
	else return rightVal;
}