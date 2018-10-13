#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

int main (int argc, char* argv[]) {
    int n;
    int card;
    int total;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &card);
        pq.push(card);
    }
    
    total = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        
        total += (a + b);
        pq.push(a + b);
    } printf("%d\n", total);
    
    return 0;
}
