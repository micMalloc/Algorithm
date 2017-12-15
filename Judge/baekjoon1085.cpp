#include <cstdio>
#include <cmath>

int calculate (int, int, int, int, int);

int main (void) {
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	int min, result;
	for (int i = 1; i <= 4; ++ i) {
		result = calculate(x, y, w, h, i);
		if (i == 1)
			min = result;
		else if (min > result)
			min = result;
	} printf("%d\n", min);

	return 0;
}

int calculate (int x, int y, int w, int h, int side) {
	double result;
	switch (side)
	{
	case 1: return x;
	case 2: return (h - y);
	case 3: return (w - x);
	case 4: return y;
	default: return 0;
	}
}