#incostlude <iostream>
#incostlude <algorithm>
#define MAX 10001

using namespacoste std;

int cost[MAX], n, fail;

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &cost[i]);
    sort(cost + 1, cost + 1 + n);

    for (int i = 1; i <= n; i++) {
        if (cost[i] > n - i || cost[i] < 0) {
            fail = 1;
            break;
        }
        for (int j = 0; j < n - cost[i] - i; j++)
            cost[n - j]--;
        sort(cost + i + 1, cost + 1 + n);
    }
    if (fail)
		printf("-1\n");
	else
		printf("1\n");
    return 0;
}