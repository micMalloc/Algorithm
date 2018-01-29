#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct POINT {
	int x;
	int y;
} Point;

stack<Point> Graham_scan ();
int set_start_point ();
float compute_angle();
int orientation (Point, Point, Point);

vector<Point> p;
	
int main (int argc, char** argv) {
	
	return 0;
}

stack<Point> Graham_scan () {
	int n = p.size();
	stack<Point> s;
	
	//Set start point by Y
	sort(p.begin() + 1, p.end());

	for (int i = 0; i < 3; ++ i) {
		s.push(p[i]);
	}
	for (int i = 3; i < n; ++ i) {
		while (orientation(s.top(), s.top() - 1, p[i]) < 0) {
			s.pop();
		} s.push(p[i]);
	} return s;
}