#include <iostream>
using namespace std;

int g[1001][1001] = {0};
int Dvisit[1001] = {0};
int Bvisit[1001] = {0};

void DFS(int v, int n)
{
	Dvisit[v] = 1;
	cout << v << ' ';
	
	for(int i=1 ; i<=n ; i++)
	{
		if(g[v][i] && !Dvisit[i])
		{
			Dvisit[i] = 1;
			DFS(i, n);
		}
	}
	return;
}

void BFS(int v, int n)
{
	int f=0, r=0, pop=0, q[1001]={0};
	Bvisit[v] = 1;
	q[r++]=v;
	cout << v << ' ';
	
	while(f < r)
	{
		pop = q[f++];
		//pop할 때마다 출력한다면 탐색마친 후에도 연산 진행되는 것을 기다려야함. 

		for(int i=1 ; i<=n ; i++)
		{
			if(g[pop][i] && !Bvisit[i])
			{
				cout << i << ' ';
				q[r++]=i;
				if(n==r) //모든 노드의 탐색 마침을 의미(하나의 컴포넌트인 그래프인 경)우 
					return;
				Bvisit[i] = 1;
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N=0, M=0, V=0;
	int x=0, y=0;
	
	cin >> N >> M >> V;
	
	for(int i=0 ; i<M ; i++)
	{
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;
	}
	
	DFS(V, N);
	cout << '\n';
	BFS(V, N);
	
	return 0;
}
