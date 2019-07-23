/* 
##Âü°í : 
## https://romanceboong.tistory.com/entry/C%EC%96%B8%EC%96%B4-BFS%EC%99%80-DFS
*/

#include<iostream>
using namespace std;

int Graph[1001][1001] = {0};
int DFSvisit[1001] = {0};
int BFSvisit[1001] = {0};
int queue[1001];

void DFS(int v, int n)
{
	int i;
	
	DFSvisit[v] = 1;
	cout << v << ' ';
	for(int i=1 ; i<=n ; i++)
		if(Graph[v][i] == 1 && DFSvisit[i]==0)
			DFS(i, n);
	
	return;
}

void BFS(int v, int n)
{
	int front=0, rear=0, pop, i;
	
	cout << v << ' ';
	queue[0] = v;
	rear++;
	BFSvisit[v]=1;
	while(front<rear)
	{
		pop = queue[front];
		front++;
		
		for(int i=1 ; i<=n ; i++)
		{
			if(Graph[pop][i] == 1 && BFSvisit[i]==0)
			{
				cout<< i << ' ';
				queue[rear] = i;
				rear ++;
				BFSvisit[i] = 1;
			}
		}
	}
	return;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, start; //N: # of Nodes, M: # of edges, start: start node 
	int i, x, y; 
	
	cin >> N >> M >> start;
		
	for(int i=0 ; i<M ; i++)
	{
		cin >> x >> y;
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}
	
	DFS(start, N);
	cout << '\n';
//	BFS(start, N);
	
	return 0;

}
