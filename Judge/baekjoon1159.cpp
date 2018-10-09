#include <cstdio>

int alpha[26];
int n;

int main (int argc, char* argv[]) {
    char input[31];
    int cnt = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%s", input);
        alpha[(int)input[0] - 97] ++;
    }
    
    for (int i = 0; i < 26; ++ i) {
        if (alpha[i] >= 5) {
            printf("%c", (char)(i + 97));
            cnt ++;
        }
    }
    
    if (cnt == 0) {
        printf("PREDAJA\n");
    }

    return 0;
}
