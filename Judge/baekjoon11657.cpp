#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;
int main(){
    int N, M, dist[500];
    scanf("%d %d", &N, &M);
    vector<P> adj[500];
    for(int i=0; i<M; i++){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        adj[A-1].push_back(P(B-1, C));
    }
    bool minusCycle = false;
    fill(dist, dist+N, INF);
    dist[0] = 0;
    for(int i=0; i<N; i++){ 
        for(int j=0; j<N; j++){
            for(auto &p: adj[j]){
                int next = p.first, d = p.second;
                if(dist[j] != INF && dist[next] > dist[j] + d){
                    dist[next] = dist[j] + d;
                    if(i == N-1) minusCycle = true;
                }
            }
        }
    }
    if(minusCycle) {
		puts("-1");
	}
    else{
        for(int i=1; i<N; i++)
            printf("%d\n", dist[i]!=INF ? dist[i] : -1);
    }
}