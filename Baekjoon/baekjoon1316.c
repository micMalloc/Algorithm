#include <stdio.h>

#define MAX 26
#define BUFSIZE 111
#define ASCII_CODE 97

void initLocaArray ();
int checkWord ();

int idxLoca[MAX];
char word[BUFSIZE];

int main (void)
{
	int i;
	int n, count;

	count = 0;
	scanf("%d%*c", &n);
	for (i = 0; i < n; ++ i)
	{
		initLocaArray();

		gets(word);
		if (checkWord())
			count ++;
	} printf("%d\n", count);

	return 0;
}

void initLocaArray ()
{
	int i;

	for (i = 0; i < MAX; ++ i)
		idxLoca[i] = -1;
}

int checkWord ()
{
	int i;

	for (i = 0; word[i] != '\0'; ++ i)
	{
		if (idxLoca[word[i] - ASCII_CODE] == -1)
			idxLoca[word[i] - ASCII_CODE] = i;
		else
		{
			if (i - idxLoca[word[i] - ASCII_CODE] > 1)
				return 0;
			else
				idxLoca[word[i] - ASCII_CODE] = i;
		}
	} return 1;
}