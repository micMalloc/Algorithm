#include <cstdio>
#include <cstring>

int main (int argc, char* argv[]) {
    long long result;
    int A, B, C;
    int count[10], idx;

    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);

    result = A * B * C;

    memset(count, 0, sizeof(count));

    while (result) {
        idx = result % 10;
        count[idx] ++;

        result /= 10;
    }

    for (int i = 0; i < 10; ++ i) {
        printf("%d\n", count[i]);
    }

    return 0;
}