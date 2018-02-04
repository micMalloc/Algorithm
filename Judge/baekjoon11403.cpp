¤¼#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Pair;
vector<Pair> input;
vector<Pair> ans;

int main (int argc, char** argv) {
	int n;
	int r, l, result = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d %d", &l, &r);
		input.push_back(make_pair(l, r));
	} sort(input.begin(), input.end());

	ans.push_back(input[0]);
	for (int i = 1; i < n; ++ i) {
		if (ans[ans.size() - 1].second >= input[i].first) {
			if (ans[ans.size() - 1].second < input[i].second) {
				ans[ans.size() - 1].second = input[i].second;
			}
		} else {
			ans.push_back(input[i]);
		}
	}

	for (int i = 0; i < ans.size(); ++ i) {
		result += ans[i].second - ans[i].first;
	} printf("%d\n", result);

	return 0;
}