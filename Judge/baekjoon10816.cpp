#include <cstdio>
#define SUM 10000000
#define MAX 500000
#define NUMS 20000004

int n, m;
int cnt[NUMS];
int list[MAX];

int main (int argc, char* argv[]) {
    int num;

    scanf("%d", &n);

    for (int i = 0; i < n; ++ i) {
        scanf("%d", &num);

        if (num < 0) {
            num *= -1;
            num += SUM;
        }

        cnt[num] ++;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; ++ i) {
        scanf("%d", &num);

        if (num < 0) {
            num *= -1;
            num += SUM;
        }

        list[i] = cnt[num];
    }

    for (int i = 0; i < m; ++ i) {
        printf("%d ", list[i]);
    }

    return 0;
}