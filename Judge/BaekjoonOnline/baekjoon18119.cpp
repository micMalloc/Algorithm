#include <iostream>
#include <ios>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int MAX = 10000;
const int IDX = 26;

int main (int argc, const char* argv[]) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int mask = (1 << IDX) - 1;
    int n, m;
    int o;
    int words[MAX];
    string word;
    char x;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        words[i] = (1 << IDX) - 1;
        cin >> word;

        for (int j = 0; j < word.size(); ++j) {
            words[i] &= ~(1 << (word[j] - 'a'));
        }
    }

    while (m --) {
        cin >> o >> x;

        if (o == 1) {
            mask &= ~(1 << (x - 'a'));
        }
        else {
            mask |= (1 << (x - 'a'));
        }

        int cnt = 0;

        for (int i = 0; i < n; ++ i) {
            if ((mask | words[i]) == (1 << IDX) - 1) {
                cnt ++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
