#include <cstdio>
#include <algorithm>
#define MAX 16

using namespace std;

typedef struct EVENT {
    int time;
    int price;
} Event;

int n;
int result;
Event events[MAX];

void DFS (int day, int sum) {

    if (day == n + 1) {
        result = max(result, sum);
        return;
    }

    DFS(day + 1, sum);

    if (day + events[day].time <= n + 1) {
        DFS(day + events[day].time, sum + events[day].price);
    }
}

int main (int argc, const char* argv[]) {

    scanf("%d", &n);

    for (int i = 1; i <= n; ++ i) {
        scanf("%d %d", &events[i].time, &events[i].price);
    }

    DFS(1, 0);

    printf("%d\n", result);

    return 0;
}