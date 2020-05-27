#include <cstdio>

int binomial (int n, int k) {

    if (n == k || k == 0) {
        return 1;
    }

    return binomial(n - 1, k) + binomial(n - 1, k - 1);
}

int main (int argc, const char* argv[]) {
    int n, k;

    scanf("%d %d", &n, &k);

    printf("%d\n", binomial(n, k));

    return 0;
}