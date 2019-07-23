// 노드 접근 순서 정렬X
// 다수의 component 처리 미구현
 
#include <iostream>
using namespace std;

void DFS(int v, int n, int g[][1001], int visit[])
{
	visit[v] = 1;
	cout << v << ' ';
	for(int i=0 ; i<n ; i++)
		if(g[v][i] && !visit[i])
			DFS(i, n, g, visit);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int graph[1001][1001] = {0};
	int visit[1001] = {0};
	int N, E, start;
	int x, y;

	cin >> N >> E >> start;
	
	for(int i=0 ; i<E ; i++)
	{
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	
	DFS(start, N, graph, visit);
	
	return 0;
}
