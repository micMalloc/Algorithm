#include <iostream>

void happyNewYear ();
bool isSameYear();

int E, S, M;
int e, s, m;
int year;

int main (void) {

	year = e = s = m = 1;
	scanf("%d %d %d", &E, &S, &M);
	while (true) {
		if (isSameYear())
			break;
		happyNewYear();
	} printf("%d\n", year);

	return 0;
}

void happyNewYear () {

	e = (e + 1) % 15;
	if (e == 0) e = 15;
	s = (s + 1) % 28;
	if (s == 0) s = 28;
	m = (m + 1) % 19;
	if (m == 0) m = 19;

	year ++;
}
bool isSameYear () {
	if (E == e && S == s && M == m)
		return true;
	else
		return false;
}