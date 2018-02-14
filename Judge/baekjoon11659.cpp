#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int make_segment_tree (int, int, int);
int get_sum (int, int, int, int, int);

vector<int> data;
vector<int> segment_tree;

int main (int argc, char** argv) {
	int n, m;
	int left, right;
	int h, tree_size;
	
	scanf("%d %d", &n, &m);
	h = (int)ceil(log(n) / log(2));
	tree_size = (1 << (h + 1));

	data.resize(n + 1, 0);
	segment_tree.resize(tree_size, 0);

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &data[i]);
	} make_segment_tree (1, 0, n - 1);
	
	int sum;
	while (m --) {
		scanf("%d %d", &left, &right);

		sum = get_sum(1, left - 1, right - 1, 0, n - 1);
		printf("%d\n", sum);
	}

	return 0;
}

int make_segment_tree (int cur, int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		segment_tree[cur] += make_segment_tree(cur * 2, start, mid);
		segment_tree[cur] += make_segment_tree(cur * 2 + 1, mid + 1, end);
	} else {
		segment_tree[cur] = data[start];
	} return segment_tree[cur];
}

int get_sum (int cur, int left, int right, int start, int end) {
	int sum = 0;
	int mid;

	if (left > end || right < start) {
		return 0;
	}
	if (start <= left && right <= end) {
		return segment_tree[cur];	
	}
	
	mid = (start + end) / 2;
	sum += get_sum(cur * 2, left, right, start, mid);
	sum += get_sum(cur * 2 + 1, left, right, mid + 1, end);
	return sum;
}