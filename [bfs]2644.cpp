// 트리 레벨 계산 및 컴포넌트 탐색 후 종결
 
#include <iostream>
using namespace std;

int BFS(int v, int t, int n, int g[][101], int visit[101])
{
	int f=0, r=0, pop=0, q[101]={0};
	int chon=0, cnt=1, nodes=0;
	visit[v] = 1;
	q[r++] = v;
	
	while(cnt) //cnt가 0이라는 것은 컴포넌트 내 모든 노드를 탐색했다는 것. 
	{
		chon++;
		for(int j=cnt ; j>0 ; j--)
		{
			pop = q[f++];
			for(int i=1 ; i<=n ; i++)
			{
				if(g[pop][i] && !visit[i])
				{
					if(i==t)
						return chon;
					visit[i] = 1;
					q[r++]=i;
					nodes++;
				}
			}
		}
		cnt = nodes;
		nodes=0;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, start=0, target=0, x=0, y=0, m=0;
	int g[101][101] = {0}, visit[101] = {0};
	
	cin >> n >> start >> target >> m;
	
	for(int i=0 ; i<m ; i++)
	{
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;
	}	
	
	cout << BFS(start, target, n, g, visit);
	
	return 0;
}
