#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct POINT {
	int x;
	int y;
} Point;

vector<Point> Graham_scan ();
void set_start_point ();
float compute_angle(Point, Point);
int orientation (Point, Point, Point);

vector<Point> p;

bool cmp (Point p1, Point p2) {
	return (compute_angle(p[0], p1) < compute_angle(p[0], p2));
}

int main (int argc, char** argv) {
	int n;
	int x, y;
	vector<Point> convex_hull;

	scanf("%d", &n);

	p.resize(n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d %d", &x, &y);
		p[i].x = x;
		p[i].y = y;
	}
	convex_hull = Graham_scan();

	return 0;
}

vector<Point> Graham_scan () {
	int n = p.size();
	vector<Point> s;
	
	set_start_point();
	sort(p.begin() + 1, p.end(), cmp);

	for (int i = 0; i < 3; ++ i) {
		s.push_back(p[i]);
	}
	for (int i = 3; i < n; ++ i) {
		while (orientation(s[s.size() - 2], s[s.size() - 1], p[i]) < 0) {
			s.pop_back();
		} s.push_back(p[i]);
	} return s;
}

void set_start_point () {
	int min = 0, tmp;

	for (int i = 1; i < p.size(); ++ i) {
		if (p[min].y > p[i].y) {
			min = i;
		}
	}
	if (min != 0)
		swap(p[0], p[min]);
}

float compute_angle (Point p1, Point p2) {
	float Dx, Dy;
	float angle;

	Dx = p2.x - p1.y;
	Dy = p2.y - p1.y;

	if (Dx >= 0 && Dy == 0) {
		angle = 0;
	} else {
		angle = abs(Dy) / (abs(Dx) + abs(Dy));
		if ((Dx < 0) && (Dy >= 0))
			angle = 2 - angle;
		else if ((Dx <= 0) && (Dy < 0))
			angle = 2 + angle;
		else if ((Dx > 0) && (Dy < 0))
			angle = 4 - angle;
	} return (angle * 90);
}

int orientation (Point p1, Point p2, Point p3) {
	int temp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	temp = temp - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;

	if (temp > 0)
		return 1;
	else if (temp < 0)
		return -1;
	else
		return 0;
}