// Ʈ�� ���� ��� �� ������Ʈ Ž�� �� ����
 
#include <iostream>
using namespace std;

int BFS(int v, int t, int n, int g[][101], int visit[101])
{
	int f=0, r=0, pop=0, q[101]={0};
	int chon=0, cnt=1, nodes=0;
	visit[v] = 1;
	q[r++] = v;
	
	while(cnt) //cnt�� 0�̶�� ���� ������Ʈ �� ��� ��带 Ž���ߴٴ� ��. 
	{
		chon++; //Ʈ�� ����
		for(int j=cnt ; j>0 ; j--) //A���� ����� �鸱 �� ���� cnt ��ŭ�� �� ���� ��, ���� ������ �ִ� ���� �鸱 ���� chon �߰� ���ϱ� ����
		{
			pop = q[f++];
			for(int i=1 ; i<=n ; i++)
			{
				if(g[pop][i] && !visit[i]) //pop�� ���� ����� ��� �� Ȯ���ϰ� �鸮�� ���� ���� ������ nodes����(���� ������ ����� ���� ����)
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
