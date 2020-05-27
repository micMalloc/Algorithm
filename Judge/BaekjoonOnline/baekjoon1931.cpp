#include <cstdio>
#include <algorithm>
#define MAX 100001

using namespace std;

typedef struct EVENT {
    int start, end;
} Event;

bool cmp (const Event &a, const Event &b) {
    if (a.end == b.end) {
        return a.start < b.start;
    }
    else {
        return a.end < b.end;
    }
}

int n;
Event events[MAX];

int main (int argc, const char* argv[]) {
    int current, answer;

    scanf("%d", &n);

    for (int i = 0; i < n; ++ i) {
        scanf("%d %d", &events[i].start, &events[i].end);
    }

    sort(events, events + n, cmp);

    current = answer = 0;

    for (int i = 0; i < n; ++ i) {
        if (current <= events[i].start) {
            current = events[i].end;
            answer ++;
        }
    }

    printf("%d\n", answer);

    return 0;
}