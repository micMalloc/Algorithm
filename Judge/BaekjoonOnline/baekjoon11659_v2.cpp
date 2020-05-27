#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int init_segment_tree (int, int, int);
int get_sum (int, int, int, int, int);

vector<int> data;
vector<int> segment_tree;

int main (int argc, char** argv) {
	int n, m;
	int h, tree_size;
	int l, r;

	scanf("%d %d", &n, &m);
	data.resize(n + 1, 0);
	
	h = (int)ceil(log(n) / log(2));
	tree_size = (1 << (h + 1));
	segment_tree.resize(tree_size, 0);
	
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &data[i]);
	} init_segment_tree(1, 1, n);
	while (m --) {
		scanf("%d %d", &l, &r);
		printf("%d\n", get_sum(1, l, r, 1, n));
	}

	return 0;
}

int init_segment_tree (int node, int start, int end) {
	int mid;

	if (start == end) {
		segment_tree[node] = data[start];
	} else {
		mid = (start + end) / 2;
		segment_tree[node] += init_segment_tree(node * 2, start, mid);
		segment_tree[node] += init_segment_tree(node * 2 + 1, mid + 1, end);
	} return segment_tree[node];
}

int get_sum (int node, int left, int right, int start, int end) {
	int mid;
	int sum = 0;

	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return segment_tree[node];
	}
	
	mid = (start + end) / 2;
	sum += get_sum(node * 2, left, right, start, mid);
	sum += get_sum(node * 2 + 1, left, right, mid + 1, end);
	return sum;
}