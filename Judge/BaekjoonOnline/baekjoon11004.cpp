#include <iostream>
#include <algorithm>

using namespace std;

int nums[5000000];
int n, k;
int num;

int main (int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++ i) {
        cin >> num;
        nums[i] = num;
    }
    
    sort(nums, nums + n);
    printf("%d\n", nums[k - 1]);
    
    return 0;
}
