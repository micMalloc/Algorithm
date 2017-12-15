#include <cstdio>
#include <vector>
#define MAX 1000
using namespace std;

typedef struct POINT {
	int x;
	int y;
} Point;

int orientation (Point p1, Point p2, Point p3);
vector<Point> Jarvis (int, int);
int setStartPoint (int, int);

Point pList[MAX];

int main (int argc, char** argv) {
	int n;
	int x, y, start;
	vector<Point> convexHull;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d %d", &x, &y);
		pList[i].x = x;
		pList[i].y = y;

		if (i > 0) {
			start = setStartPoint (i, start);
		} else start = i;
	}

	convexHull = Jarvis (n, start);

	return 0;
}

int orientation (Point p1, Point p2, Point p3) {
	int result;

	result = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
	if (result > 0) {
		return 1;
	} else if (result < 0) {
		return -1;
	} else {
		return 0;
	}
}

vector<Point> Jarvis (int n, int start) {
	int current, next;
	vector<Point> convexHull;
	
	current = start;
	do {
		convexHull.push_back(pList[current]);
		
		next = (current + 1) % n;
		for (int i = 0; i < n; ++ i) {
			if (orientation(pList[current], pList[i], pList[next])) {
				next = i;
			}
		} current = next;
	} while (current != start);

	return convexHull;
}

int setStartPoint (int a, int b) {
	if (pList[a].x > pList[b].x) {
		return b;
	} else {
		return a;
	}
}