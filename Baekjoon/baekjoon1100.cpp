#include <iostream>

bool table[8][8];

int main (void) {
	int count;
	bool isWhite[8];
	char check;
	
	for (int i = 0; i < 8; ++ i) {
		for (int j = 0; j < 8; ++ j) {
			check = getchar();
			switch (check)
			{
			case '.': {
				table[i][j] = false;
				break;
			}
			case 'F': {
				table[i][j] = true;
				break;
			}
			default:
				printf("Invalid Value\n");
				break;
			}
		} scanf("%*c");
	}

	isWhite[0] = true;
	for (int i = 1; i < 8; ++ i) {
		if (isWhite[i - 1])
			isWhite[i] = false;
		else
			isWhite[i] = true;
	}

	count = 0;
	for (int i = 0; i < 8; ++ i) {
		for (int j = 0; j < 8; ++ j) {
			if (isWhite[i] && table[i][j]) {
				count ++;
			}

			if (isWhite[i])
				isWhite[i] = false;
			else
				isWhite[i] = true;
		}
	} printf("%d\n", count);

	return 0;
}
