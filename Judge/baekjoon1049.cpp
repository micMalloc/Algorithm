#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int THRESHOLD = 6;

int main (int argc, const char* argv[]) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    int pack, pie;
    int idx = 1;

    vector<int> prices;
    vector<int> package;
    vector<int> piece;

    cin >> n >> m;

    while (n > idx * THRESHOLD) {
        idx ++;
    }

    for (int i = 0; i < m; ++i) {
        cin >> pack >> pie;

        package.push_back(pack);
        piece.push_back(pie);

        prices.push_back(pack * idx);
        prices.push_back(pie * n);
    }

    for (int i = 1; i < idx; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k) {
                prices.push_back(i * package[j] + ((n - i * THRESHOLD) * piece[k]));
            }
        }
    }

    sort(prices.begin(), prices.end());

    cout << prices[0] << '\n';

    return 0;
}