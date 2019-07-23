#include <iostream>
using namespace std;
int graph[1001][1001] = {0};
int visit[1001] = {0};

int DFS(int v, int n)
{	
	visit[v] = 1;
	for(int i=1 ; i<=n ; i++)
		if(graph[v][i] && !visit[i])
			DFS(i, n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	int x, y;
	int component=0;
	cin >> N >> M;
	
	for(int i=0 ; i<M ; i++)
	{
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	
	for(int i=1 ; i <= N ; i++)
	{
		if(!visit[i])
		{
			component++;
			DFS(i, N);
		}	
	}
	cout << component;
	
	return 0;
}
