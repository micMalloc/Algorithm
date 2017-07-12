#include <stdio.h>
#include <string.h>

int isInS ();
void move_Robot (int);
void turn_Robot (int);

typedef struct ROBOT
{
	int x;
	int y;
	char direction;
} Robot;

Robot R;
int m;

int main (void)
{
	int n, i;
	char instruction[5];
	int dir, d;
	int isRight = 1;

	R.direction = 'E';

	scanf("%d %d%*c", &m, &n);
	for (i = 0; i < n; ++ i)
	{
		scanf("%s", instruction);
		if (!strcmp(instruction, "MOVE"))
		{
			scanf("%d%*c", &d);
			move_Robot(d);
		}
		else if (!strcmp(instruction, "TURN"))
		{
			scanf("%d%*c", &dir);
			turn_Robot(dir);
		}
		else
			printf("Invalid Instruction\n");

		if (!isInS())
			isRight = 0;
	}
	if (isRight)
		printf("%d %d\n", R.x, R.y);
	else
		printf("-1\n");

	return 0;
}

int isInS ()
{
	if (0 > R.x || R.x > m)
		return 0;
	if (0 > R.y || R.y > m)
		return 0;
	return 1;
}

void move_Robot (int d)
{
	switch (R.direction)
	{
	case 'E':
		{
			R.x += d;
			break;
		}
	case 'W':
		{
			R.x -= d;
			break;
		}
	case 'S':
		{
			R.y -= d;
			break;
		}
	case 'N':
		{
			R.y += d;
			break;
		}
	default:
		printf("Invalid Direction\n");
		break;
	}
}

void turn_Robot (int dir)
{
	switch (R.direction)
	{
	case 'E':
		{
			if (dir)
				R.direction = 'S';
			else
				R.direction = 'N';
			break;
		}
	case 'W':
		{
			if (dir)
				R.direction = 'N';
			else
				R.direction = 'S';
			break;
		}
	case 'S':
		{
			if (dir)
				R.direction = 'W';
			else
				R.direction = 'E';
			break;
		}
	case 'N':
		{
			if (dir)
				R.direction = 'E';
			else
				R.direction = 'W';
			break;
		}
	default:
		printf("Invalid Direction\n");
		break;
	}
}