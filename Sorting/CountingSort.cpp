#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10001]={0};

int main(){
    int N, index;
    scanf("%d",&N);
    for(int i = 0; i < N; ++i){
        scanf("%d",&index);
        arr[index]++;
    }
    for(int i = 1; i < 10001; ++i)
        if(arr[i] != 0)
            for(int j = 0; j < arr[i]; ++j)
                printf("%d\n",i);
    return 0;
}