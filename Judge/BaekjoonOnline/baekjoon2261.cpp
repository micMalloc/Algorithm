#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct POINT {
    int x, y;
} Point;

bool cmp_x (const Point p, const Point q) {
    if (p.x == q.x) {
        return p.y < q.y;
    }
    else {
        return p.x < q.x;
    }
}

bool cmp_y (const Point p, const Point q) {
    if (p.y == q.y) {
        return p.x < q.x;
    }
    else {
        return p.y < q.y;
    }
}

int dist(const Point p, const Point q) {
    return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}

int closest_pair(vector<Point>::iterator it, int n) {
    if (n == 2)
        return dist(it[0], it[1]);
    if (n == 3)
        return min({dist(it[0], it[1]), dist(it[1], it[2]), dist(it[2], it[0])});
     
    int d = min(closest_pair(it, n/2), closest_pair(it + n/2, n - n/2));
    
    vector<Point> mid;
    mid.reserve(n);
    
    int mid_idx = n >> 1;
    
    for (int i = 0; i < n; i++) {
        if (it[mid_idx].x - d <= it[i].x && it[i].x <= it[mid_idx].x + d) {
            mid.push_back(it[i]);
        }
    }
 
    sort(mid.begin(), mid.end(), cmp_y);
     
    int mid_sz = (int)mid.size();
    for (int i = 0; i < mid_sz - 1; i++)
        for (int j = i + 1; j < mid_sz && (int)pow((mid[j].y - mid[i].y), 2.0) < d; j++)
            d = min(d, dist(mid[i], mid[j]));
    
    return d;
}

int main (int argc, const char *argv[]) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    int x, y;
    vector<Point> p;
    
    cin >> n;
    
    for (int i = 0; i < n; ++ i) {
        cin >> x >> y;
        p.push_back({x, y});
    }
    
    sort(p.begin(), p.end(), cmp_x);
    
    cout << closest_pair(p.begin(), n) << '\n';
    
    return 0;
}
