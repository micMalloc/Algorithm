#include <stdio.h>
#define MAX 100

int addSticks (int);
void splitStick ();
void abandonStick ();

int stick[MAX], idx = 0;

int main (void)
{
	int x;

	stick[idx] = 64;
	scanf("%d", &x);
	while (addSticks(idx) != x)
	{
		splitStick();
		if (addSticks(idx - 1) > x)
			abandonStick();
	}
	if (idx > 0)
		printf("%d", idx - 1);
	else
		printf("%d", idx + 1);

	return 0;
}

int addSticks (int num)
{
	int i = 0, total = 0;

	for (i = 0; i <= num; ++ i)
		total += stick[i];
	return total;
}

void splitStick ()
{
	int tmp = stick[idx];

	stick[idx ++] = tmp / 2;
	stick[idx] = tmp / 2;
}

void abandonStick ()
{
	idx --;
}