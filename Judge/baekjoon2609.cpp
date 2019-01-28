#include <cstdio>

int gcd (int a, int b) {
    int tmp;

    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    } return a;
}

int lcm (int a, int b) {
    return a * b / gcd(a, b);
}

int main (int argc, char* argv[]) {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", gcd(a, b));
    printf("%d\n", lcm(a, b));

    return 0;
}