#include <stdio.h>

int main (int argc, char* argv[]) {
    char input[101];
    
    while (fgets(input, 101, stdin)) {
        printf("%s", input);
    }
    
    return 0;
}
