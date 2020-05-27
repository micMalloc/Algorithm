#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX 300001

using namespace std;

pair<int, int> jewel[MAX];
int bags[MAX];
priority_queue<int> pq;

int main (int argc, char* argv[]) {
    int n, k;
    long long result = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++ i) {
        scanf("%d %d", &jewel[i].first, &jewel[i].second);
    }

    for (int i = 0; i < k; ++ i) {
        scanf("%d", bags + i);
    }

    sort(jewel, jewel + n);
    sort(bags, bags + k);

    for (int i = 0, j = 0; i < k; ++ i) {
        while (j < n && jewel[j].first <= bags[i]) {
            pq.push(jewel[j++].second);
        }
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    printf("%lld\n", result);

    return 0;
}