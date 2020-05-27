#include <cstdio>
#include <cstring>
#define BUFSIZE 10

int main (int argc, const char* argv[]) {
    int s = 0;
    int m, x;
    char operation[BUFSIZE];

    scanf("%d%*c", &m);

    while (m --) {
        scanf("%s %d%*c", operation, &x);

        if (strcmp(operation, "add") == 0) {
            s |= (1 << x);
        }
        else if (strcmp(operation, "remove") == 0) {
            s &= ~(1 << x);
        }
        else if (strcmp(operation, "check") == 0) {
            if ((s & (1 << x)) == 0) {
                printf("0\n");
            }
            else {
                printf("1\n");
            }
        }
        else if (strcmp(operation, "toggle") == 0) {
            s ^= (1 << x);
        }
        else if (strcmp(operation, "all") == 0) {
            s = (1 << 21) - 1;
        }
        else if (strcmp(operation, "empty") == 0) {
            s = 0;
        }
    }

    return 0;
}