#include <iostream>
#include <vector>

using namespace std;
const int M = 8, N = 8;
typedef struct
{
	int matrix[M][N];
	int n;
	int e;
} Graph;

void dijkstra(Graph& g, int* dist, int* path, int v0)
{
	//initialize
	bool* visited = new bool[g.n];
	for (int i = 0; i < g.n; ++i)
	{
		if (i != v0 && g.matrix[v0][i] > 0) {dist[i] = g.matrix[v0][i]; path[i] = v0;}
		else {dist[i] = INT_MAX; path[i] = -1;}
		visited[i] = false;
	}
	dist[v0] = 0;
	path[v0] = -1;
	visited[v0] = true;

	for (int i = 1; i < g.n; ++i)
	{
		int mind = INT_MAX, minn = 0;
		for (int j = 0; j < g.n; ++j)
		{
			if (!visited[j] && dist[j] < mind)
			{
				mind = dist[j];
				minn = j;
			}
		}
		visited[minn] = true;
		for (int k = 0; k < g.n; ++k)
		{
			if (!visited[k] && g.matrix[minn][k] > 0 && dist[k] > mind+g.matrix[minn][k])
			{
				dist[k] = mind+g.matrix[minn][k];
				visited[k] = true;
				path[k] = minn;
			}
		}
	}
}

void dijkstra(Graph& g, vector<int>& dist, vector<int>& path, int v0)
{
	//initialize
	vector<int> visited(g.n, false);
	for (int i = 0; i < g.n; ++i)
	{
		if (i != v0 && g.matrix[v0][i] > 0) {dist[i] = g.matrix[v0][i]; path[i] = v0;}
		else {dist[i] = INT_MAX; path[i] = -1;}
		visited[i] = false;
	}
	dist[v0] = 0;
	path[v0] = -1;
	visited[v0] = true;

	for (int i = 1; i < g.n; ++i)
	{
		int mind = INT_MAX, minn = 0;
		for (int j = 0; j < g.n; ++j)
		{
			if (!visited[j] && dist[j] < mind)
			{
				mind = dist[j];
				minn = j;
			}
		}
		visited[minn] = true;
		for (int k = 0; k < g.n; ++k)
		{
			if (!visited[k] && g.matrix[minn][k] > 0 && dist[k] > mind+g.matrix[minn][k])
			{
				dist[k] = mind+g.matrix[minn][k];
				visited[k] = true;
				path[k] = minn;
			}
		}
	}
}

int main()
{
	Graph g;
	g.matrix[0][0] = 0;g.matrix[0][1] = 100; g.matrix[0][2] = 40; g.matrix[0][3] = -1; g.matrix[0][4] = 30; g.matrix[0][5] = -1; g.matrix[0][6] = -1; g.matrix[0][7] = 70;
	g.matrix[1][0] = 100;g.matrix[1][1] = 0; g.matrix[1][2] = 40; g.matrix[1][3] = -1; g.matrix[1][4] = -1; g.matrix[1][5] = 70; g.matrix[1][6] = -1; g.matrix[1][7] = -1;
	g.matrix[2][0] = 40;g.matrix[2][1] = 40; g.matrix[2][2] = 0; g.matrix[2][3] = 60; g.matrix[2][4] = -1; g.matrix[2][5] = 50; g.matrix[2][6] = 80; g.matrix[2][7] = 65;
	g.matrix[3][0] = -1;g.matrix[3][1] = -1; g.matrix[3][2] = 60; g.matrix[3][3] = 0; g.matrix[3][4] = -1; g.matrix[3][5] = -1; g.matrix[3][6] = -1; g.matrix[3][7] = -1;
	g.matrix[4][0] = 30;g.matrix[4][1] = -1; g.matrix[4][2] = -1; g.matrix[4][3] = -1; g.matrix[4][4] = 0; g.matrix[4][5] = -1; g.matrix[4][6] = -1; g.matrix[4][7] = 35;
	g.matrix[5][0] = -1;g.matrix[5][1] = 70; g.matrix[5][2] = 50; g.matrix[5][3] = -1; g.matrix[5][4] = -1; g.matrix[5][5] = 0; g.matrix[5][6] = -1; g.matrix[5][7] = -1;
	g.matrix[6][0] = -1;g.matrix[6][1] = -1; g.matrix[6][2] = 80; g.matrix[6][3] = -1; g.matrix[6][4] = -1; g.matrix[6][5] = -1; g.matrix[6][6] = 0; g.matrix[6][7] = -1;
	g.matrix[7][0] = 70;g.matrix[7][1] = -1; g.matrix[7][2] = 65; g.matrix[7][3] = -1; g.matrix[7][4] = 35; g.matrix[7][5] = -1; g.matrix[7][6] = -1; g.matrix[7][7] = 0;
	g.n = M;
	/*int* dist = new int[M];
	int* path = new int[M];*/
	vector<int> dist(g.n);
	vector<int> path(g.n);
	dijkstra(g, dist, path, 0);
	cout << dist[6] << endl;
	for (int i = 0; i < M; ++i)
	{

	}
}