#include <iostream>
#define ASCII 48

int findMax ();

char roomNum[1000001];
int digit[10];

int main () {
	int max = 0;

	gets(roomNum);
	for (int i = 0; roomNum[i] != '\0'; ++ i) {
		if (roomNum[i] == '6' || roomNum[i] == '9') {
			if (digit[roomNum[i] - ASCII] < max) {
				digit[roomNum[i] - ASCII] ++;
			} else {
				switch (roomNum[i])
				{
				case '6': {
					if (digit[9] < max)
						digit[9] ++;
					else
						digit[roomNum[i] - ASCII] ++;
					break;
				}
				case '9': {
					if (digit[6] < max)
						digit[6] ++;
					else
						digit[roomNum[i] - ASCII] ++;
					break;
				}
				default:
					break;
				}
			}
		} else
			digit[roomNum[i] - ASCII] ++;
		max = findMax();
	} printf("%d\n", max);

	return 0;
}

int findMax () {
	int max = 0;
	
	for (int i = 0; i < 10; ++ i) {
		if (max < digit[i])
			max = digit[i];
	} return max;
}