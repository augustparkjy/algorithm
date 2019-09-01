#include<iostream>
#include<string>
using namespace std;
typedef struct pos
{
	int x;
	int y;
}Pos;
// 2俺 谅钎 贸府 , queue[10000][2] / d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}} 茄第 贸府 

void escape(int x, int y, int n, int m, int maze[][102])
{	
	int f=0, r=0, cnt=1, visit[102][102] = {0};
	int nodes=0, step=1;
	Pos q[10000] = {0, 0};
	Pos pop={0,0};
	
	q[r].x = x;
	q[r].y = y;
	r++;
	visit[x][y] = 1;
	
	while(cnt)
	{
		step++;
		
		for(int j=cnt ; j>0 ; j--)
		{
			pop.x=q[f].x;
			pop.y=q[f].y;
			f++;
	
			for(int a=1 ; a>-1 ; a--)
			{
				if((pop.x+a)==n && (pop.y+(1-a))==m)
				{
					cout << step;
					return;
				}
				
				if(maze[pop.x+a][pop.y+(1-a)] && !visit[pop.x+a][pop.y+(1-a)])
				{
					q[r].x = pop.x+a;
					q[r].y = pop.y+(1-a);
					r++;
					visit[pop.x+a][pop.y+(1-a)] = 1;
					nodes++;
				}
			}
			for(int a=-1 ; a<1 ; a++)
			{
				if((pop.x+a)==n && (pop.y+(-1-a))==m)
				{
					cout << step;
					return;
				}
				
				if(maze[pop.x+a][pop.y+(-1-a)] &&!visit[pop.x+a][pop.y+(-1-a)])
				{
					q[r].x = pop.x+a;
					q[r].y = pop.y+(-1-a);
					r++;
					visit[pop.x+a][pop.y+(-1-a)] = 1;
					nodes++;
				}
			}
		}
		cnt = nodes;
		nodes = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N=0, M=0;
	int maze[102][102]={0};
	string s;
	
	cin >> N >> M;
	
	for(int i=1 ; i<=N ; i++)
	{
		cin >> s;
		for(int j=1 ; j<=M ; j++)
		{
			maze[i][j] = s[j-1]-48;
		}
	}

	escape(1, 1, N, M, maze);
		
	return 0;
}
