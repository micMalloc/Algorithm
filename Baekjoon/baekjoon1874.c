#include <stdio.h>
#define MAX 100001

int isEmpty();
void Push(int);
void Pop();
void Print();

int list[MAX], idx = 0;
int stack[MAX], top = -1;
char buf[MAX * 100];

int main (void)
{
	int n, i, num;

	scanf("%d", &n);
	for (i = 0; i < n; ++ i)
		scanf("%d", &list[i]);

	i = 0; num = 1;
	while (i < n)
	{
		if (top == -1 || stack[top] < list[i]) {
			if (num > list[i]) {
				printf("NO\n");
				break;
			}
			Push(num ++);
			buf[idx ++] = '+';
		} else if (stack[top] > list[i]) {
			Pop();
			buf[idx ++] = '-';
		} else if (stack[top] == list[i]) {
			Pop();
			buf[idx ++] = '-';
			i ++;
		}
	}
	if (i == n)
		Print();
	return 0;
}

void Print()
{
	int i;

	for (i = 0; i < idx; ++ i)
		printf("%c\n", buf[i]);
}
int isEmpty ()
{
	if (top < 0)
		return 1;
	else
		return 0;
}
void Push (int key)
{
	top ++;
	stack[top] = key;
}
void Pop ()
{
	top --;
}