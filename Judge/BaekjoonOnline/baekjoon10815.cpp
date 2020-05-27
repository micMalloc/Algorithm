#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAX 500000

using namespace std;

int n;
int list[MAX];
int card[MAX];

bool find (int start, int end, int idx) {
    int mid;
    
    while (start <= end) {
        mid = (start + end) / 2;
        if (list[idx] == card[mid]) {
            return true;
        } else {
            if (list[idx] < card[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    } return false;
}

int main (int argc, char* argv[]) {
    int m;
    bool isInList[MAX];
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", card + i);
    } sort(card, card + n);
    
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d", list + i);
    }
    
    memset(isInList, false, sizeof(isInList));
    for (int i = 0; i < m; ++ i) {
        if (find(0, n - 1, i)) {
            isInList[i] = true;
        }
    }
    
    for (int i = 0; i < m; ++ i) {
        if (isInList[i]) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    } printf("\n");
    
    return 0;
}
