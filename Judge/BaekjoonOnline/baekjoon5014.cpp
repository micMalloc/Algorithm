//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//#define MAXN 1000010
//int F, S, G, U, D;
//int dist[MAXN];
//bool check[MAXN];
//
//int main() {
//    scanf(" %d %d %d %d %d", &F, &S, &G, &U, &D);
//    queue<int> q;
//    q.push(S);
//    dist[S] = 0;
//    check[S] = true;
//
//    while (!q.empty()) {
//        int here = q.front();
//        q.pop();
//
//        int next = here + U;
//        if (next <= F && !check[next]) {
//            check[next] = true;
//            dist[next] = dist[here] + 1;
//            q.push(next);
//        }
//
//        next = here - D;
//        if (1 <= next && !check[next]) {
//            check[next] = true;
//            dist[next] = dist[here] + 1;
//            q.push(next);
//        }
//    }
//    if (check[G]) printf("%d\n", dist[G]);
//    else puts("use the stairs");
//}

#include <cstdio>
#include <utility>
#include <queue>
#define MAX 1000001

using namespace std;

int F, S, G, U, D;
bool visited[MAX];

int BFS (int start) {
    queue<pair<int, int>> que;

    visited[start] = true;
    que.push({start, 0});

    while (!que.empty()) {
        int current = que.front().first;
        int dist = que.front().second;
        int next;

        que.pop();

        if (current == G) return dist;

        next = current + U;
        if (next <= F && !visited[next]) {

            visited[next] = true;
            que.push({next, dist + 1});
        }

        next = current - D;
        if (next >= 1 && !visited[next]) {

            visited[next] = true;
            que.push({next, dist + 1});
        }
    }

    return 0;
}

int main (int argc, const char* argv[]) {
    int dist;

    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    dist = BFS(S);

    if (dist) {
        printf("%d\n", dist);
    }
    else {
        printf("use the stairs\n");
    }

    return 0;
}