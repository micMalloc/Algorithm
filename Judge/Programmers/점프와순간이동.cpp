#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int search (int n) {
    int answer,right,mid;
    
    answer = 0;
    right = n;
    
    while (right) {
        if (right % 2 == 0) {
            right /= 2;
        }
        else {
            right --;
            answer ++;
        }
    }
    
    return answer;
}

int solution(int n)
{
    return search(n);
}
