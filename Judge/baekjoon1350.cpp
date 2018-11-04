#include <cstdio>
#define MAX_SIZE 1001

typedef long long VeryLong;
VeryLong list[MAX_SIZE];

int main (int argc, char* argv[]) {
    int n;
    VeryLong number_of_clusters;
    VeryLong size_of_cluster;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%lld", list + i);
    }
    
    scanf("%lld", &size_of_cluster);
    
    number_of_clusters = 0;
    for (int i = 0; i < n; ++ i) {
        if (list[i] % size_of_cluster == 0) {
            number_of_clusters += list[i] / size_of_cluster;
        } else {
            number_of_clusters += list[i] / size_of_cluster + 1;
        }
    } printf("%lld\n", number_of_clusters * size_of_cluster);
    
    return 0;
}

