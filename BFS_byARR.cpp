#include <iostream>
using namespace std;
int graph[1001][1001] = {0};
int visit[1001] = {0};

void BFS(int v, int n)
{
	int front = 0, rear = 0, queue[1001] = {0};
	int pop = 0;
	
	visit[v] = 1;
	queue[rear++]=v;
	cout << v << ' ';
	while(front < rear)
	{
		pop = queue[front++];
		//pop�� ������ ����Ѵٸ� Ž����ģ �Ŀ��� ���� ����Ǵ� ���� ��ٷ�����. 
		for(int i=1 ; i<=n ; i++)
		{
			if(graph[pop][i] && !visit[i])
			{
				cout << i << ' ';
				queue[rear++]=i;
				if(rear == n) //��� ����� Ž�� ��ħ�� �ǹ�(�ϳ��� ������Ʈ�� �׷���  ����) 
					return; // �����鼭 Ž�������� �˷��ֹǷ� rear==n�̸� ���� 
				visit[i] = 1;
			}	
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N=0, M=0, start=0;
	int x=0, y=0;
	
	cin >> N >> M >> start;
	for(int i=0 ; i<M ; i++)
	{
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	
	BFS(start, N);
	
	return 0;
}
