#include <cstdio>
#include <cstring>

const int MAX = 10;

int convertion (char[MAX]);

int main (void) {
	char color[MAX];
	int code;
	long long result = 0;

	for (int i = 0; i < 3; ++ i) {
		gets(color);
		code = convertion(color);
		switch (i)
		{
		case 0: {
			result += code;
			break;
		}
		case 1: {
			result = (result * 10) + code;
			break;
		}
		case 2: {
			for (int j = 0; j < code; ++ j) result *= 10;
			break;
		}
		default:
			break;
		}
	} printf("%lld\n", result);
	return 0;
}

int convertion (char color[]) {
	if (strcmp(color, "black") == 0) return 0;
	else if (strcmp(color, "brown") == 0) return 1;
	else if (strcmp(color, "red") == 0) return 2;
	else if (strcmp(color, "orange") == 0) return 3;
	else if (strcmp(color, "yellow") == 0) return 4;
	else if (strcmp(color, "green") == 0) return 5;
	else if (strcmp(color, "blue") == 0) return 6;
	else if (strcmp(color, "violet") == 0) return 7;
	else if (strcmp(color, "grey") == 0) return 8;
	else if (strcmp(color, "white") == 0) return 9;
	else printf("Invalid Value\n");
}