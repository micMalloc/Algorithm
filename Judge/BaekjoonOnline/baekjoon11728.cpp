#include <cstdio>
#include <algorithm>
#define MAX 2000001

using namespace std;

int arr[MAX];

int main (int argc, char* argv[]) {

    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++ i) {
        scanf("%d", arr + i);
    }

    for (int i = n; i < n + m; ++ i) {
        scanf("%d", arr + i);
    }

    sort(arr, arr + (n + m));

    for (int i = 0; i < n + m; ++ i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}