#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

long long init_segment_tree (int, int, int);
long long get_sum (int, int, int, int, int);
void update_segment_tree (int, int, int, int, long long);

vector<long long> data;
vector<long long> segment_tree;

int main (int argc, char** argv) {
	int n, m, k;
	int h, tree_size;
	int a, b;
	long long c;

	scanf("%d %d %d", &n, &m, &k);
	data.resize(n + 1, 0);
	
	h = (int)ceil(log(n) / log(2));
	tree_size = (1 << (h + 1));
	segment_tree.resize(tree_size, 0);
	
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld", &data[i]);
	} init_segment_tree(1, 1, n);
	
	m += k;
	while (m --) {
		scanf("%d %d %lld", &a, &b, &c);
		switch (a)
		{
		case 1: {
			update_segment_tree(1, 1, n, b, c - data[b]);
			data[b] = c;
			break;
		}
		case 2: {
			printf("%lld\n", get_sum(1, b, c, 1, n));
			break;
		}
		default:
			break;
		}
	}

	return 0;
}

long long init_segment_tree (int node, int start, int end) {
	int mid;

	if (start == end) {
		segment_tree[node] = data[start];
	} else {
		mid = (start + end) / 2;
		segment_tree[node] += init_segment_tree(node * 2, start, mid);
		segment_tree[node] += init_segment_tree(node * 2 + 1, mid + 1, end);
	} return segment_tree[node];
}

long long get_sum (int node, int left, int right, int start, int end) {
	int mid;
	long long sum = 0;

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

void update_segment_tree (int node, int start, int end, int idx, long long dif) {
	int mid;
	
	if (idx < start || idx > end) return;

	segment_tree[node] += dif;

	if (start != end) {
		mid = (start + end) / 2;
		update_segment_tree(node * 2, start, mid, idx, dif);
		update_segment_tree(node * 2 + 1, mid + 1, end, idx, dif);
	}
}