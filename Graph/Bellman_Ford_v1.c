/*Bellman_Ford
Initialize-Single-Source (G, s)
for i <- 1 to |V[G]| - 1
	do for each edge(u, v) ¡ô E[G]
		do Relax(u, v, w)
for each edge(u, v) ¡ô E[G]
	if d[v] > d[u] + w(u, v)
		then Return False
Return True
*/
	
#include <stdio.h>
#define INFINITY 9999

void InitializeSingleSource(int, int);
int Bellman_Ford(int, int, int);
void Relax(int, int, int);
void Print(int, int);

struct EDGE
{
	int source;
	int des;
	int w;
};
typedef struct EDGE Edge;
Edge e[101];

int d[101];

int main ()
{
	int nc, ec, s;
	int i;
	//Read Node count
	scanf("%d", &nc);
	//Read Edge count and Information
	scanf("%d", &ec);
	for (i = 0; i < ec; ++ i)
		scanf("%d %d %d", &e[i].source, &e[i].des, &e[i].w);
	//Read Single source
	scanf("%d", &s);

	if (Bellman_Ford(nc, ec, s))
		Print(s, nc);
	else
		printf("Negative Cycle\n");

	return 0;
}

int Bellman_Ford (int nodeCount, int edgeCount, int s)
{
	int i, j;

	InitializeSingleSource(nodeCount, s);
	for (i = 1; i <= (nodeCount - 1); ++ i)
	{
		for (j = 0; j < edgeCount; ++ j)
			Relax(e[j].source, e[j].des, e[j].w);
	}

	for (i = 0; i < edgeCount; ++ i)
	{
		if (d[e[i].des] > d[e[i].source] + e[i].w)
			return 0;
	}
	return 1;
}

void InitializeSingleSource(int nodeCount, int source)
{
	int i;

	for (i = 1; i <= nodeCount; ++ i)
		d[i] = INFINITY;
	d[source] = 0;
}

void Relax (int u, int v, int w)
{
	if (d[v] > d[u] + w)
		d[v] = d[u] + w;
}

void Print (int source, int nodeCount)
{
	int i;

	for (i = 1; i <= nodeCount; ++ i)
	{
		if (i != source)
			printf("Source: %d	Destination: %d    distance: %d\n", source, i, d[i]);
	}
}