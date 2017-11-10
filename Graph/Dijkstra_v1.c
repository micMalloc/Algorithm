#include <stdio.h>
#define MAXIMUM 101
#define INFINITY 999

void dijkstra (int);
int isEmpty ();
int isFull ();
void Insert (int);
int Delete ();
int Extract_Min ();
void mergeSort (int, int);
void merge (int, int);
void Print ();

int Q[MAXIMUM], tmp[MAXIMUM];
int cost[MAXIMUM][MAXIMUM];
int dist[MAXIMUM];
int selected[MAXIMUM];
int front, back, n;

int main ()
{
	int i, j;
	int u, v, w, m;
	
	//Read The Number Of Nodes
	scanf("%d", &n);
	//Initialize Cost table
	for (i = 0; i < n; ++ i)
	{
		for (j = 0; j < n; ++ j)
			cost[i][j] = INFINITY;
	}
	//Read Adjacency Information
	scanf("%d", &m);
	for (i = 0; i < m; ++ i)
	{
		scanf("%d %d %d", &u, &v, &w);
		cost[u][v] = w;
	}
	
	dijkstra(0);
	Print();

	return 0;
}

/*
Description: Compute the single source shortest path by using Dijkstra Algorithm
Input: Source
Output: None
*/
void dijkstra (int source)
{
	int i, u;

	/* Q <- V[G]*/
	for (i = 0; i < n; ++ i)
	{
		if (isFull())
			Insert(i);
	}
	/* for all each d[v] <- INFINITY */
	for (i = 1; i <= n; ++ i)
		dist[i] = INFINITY;
	dist[source] = 0;
	
	while (isEmpty())
	{
		u = Extract_Min();
		selected[u] = 1;
		for (i = 0; i < n; ++ i)
		{//Relaxation Step
			if (dist[i] > dist[u] + cost[u][i])
				dist[i] = dist[u] + cost[u][i];
		}
	}
}

/*
Description: Check if the Q is empty or not
Input: None
Output: If it is empty, return 0
		Else it is not, return 1
*/
int isEmpty ()
{
	if (front >= back)
		return 0;
	else
		return 1;
}
/*
Description: Check if the Q is full or not
Input: None
Output:	If it is full, return 0
		Else it is not, return 1
*/
int isFull ()
{
	if (back >= n)
		return 0;
	else
		return 1;
}
/*
Description: Insert received key into the Q
Input: Key
Output: None
*/
void Insert (int key)
{
	Q[++ back] = key;
}
/*
Description: Delete the front value from the Q
Input: None
Output: The value deleted from the Q
*/
int Delete ()
{
	return (Q[++ front]);
}
/*
Description: Sort the Q by priority and Pop(Delete) the vertex
Input: None
Output: the value that has the highest priority in the Q
*/
int Extract_Min ()
{
	mergeSort(front + 1, back);

	return (Delete());
}

/*
Description: Split the list to be merged
Input: start and end
Output: None
*/
void mergeSort (int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, end);
	}
}
/*
Description: Merge the two sorted list
Input: start and end
Output: None
*/
void merge (int start, int end)
{
	int mid = (start + end) / 2;
	int left, right, idx, i;

	left = start; right = mid + 1;

	idx = 0;
	while (left <= mid && right <= end)
	{
		if (dist[Q[left]] < dist[Q[right]])
			tmp[idx ++] = Q[left ++];
		else
			tmp[idx ++] = Q[right ++];
	}

	while (left <= mid)
		tmp[idx ++] = Q[left ++];
	while (right <= end)
		tmp[idx ++] = Q[right ++];

	for (i = 0; i < idx; ++ i)
		Q[start + i] = tmp[i];
}

/*
Description: Print the each path distance from source to target
Input: None
Output: None
*/
void Print()
{
	int i;

	printf("\nRESULT\n");
	for (i = 1; i < n; ++ i)
		printf("Source: %c  Destination: %c  Distance: %d\n", 's', i + 96, dist[i]);
}