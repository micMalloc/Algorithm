#include <cstdio>
#include <algorithm>
#define MAX 51

using namespace std;

int n;
int idx;
int queue[MAX];
int list[MAX];

int go_left (int idx, int target, int cost) {

    if (queue[idx] == target) {
        return cost;
    }

    idx --;
    if (idx < 0) {
        idx = n - 1;
    }

    if (queue[idx] == -1) {
        return go_left(idx, target, cost);
    } else {
        return go_left(idx, target, cost + 1);
    }
}

int go_right (int idx, int target, int cost) {

    if (queue[idx] == target) {
        return cost;
    }

    idx = (idx + 1) % n;
    if (queue[idx] == -1) {
        return go_right(idx, target, cost);
    } else {
        return go_right(idx, target, cost + 1);
    }
}

int main (int argc, char* argv[]) {
    int m;
    int cnt = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        queue[i] = i + 1;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d", list + i);
    }

    for (int i = 0; i < m; ++ i) {
        int l = go_left(idx, list[i], 0);
        int r = go_right(idx, list[i], 0);
        //cnt += min(go_left(idx, list[i], 0), go_right(idx, list[i], 0));
        int val = min(l, r);
        cnt += val;

        idx = list[i] % n;

        if (idx < 1) queue[n - 1] = -1;
        else queue[idx - 1] = -1;

        while (i < (m - 1) && queue[idx] < 0) idx = (idx + 1) % n;
    }

    printf("%d\n", cnt);

    return 0;
}
