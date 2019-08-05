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
		//pop할 때마다 출력한다면 탐색마친 후에도 연산 진행되는 것을 기다려야함. 
		for(int i=1 ; i<=n ; i++)
		{
			if(graph[pop][i] && !visit[i])
			{
				cout << i << ' ';
				queue[rear++]=i;
				if(rear == n) //모든 노드의 탐색 마침을 의미(하나의 컴포넌트인 그래프  가정) 
					return; // 넣으면서 탐색했음을 알려주므로 rear==n이면 끝냄 
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
