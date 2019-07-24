//TIME OVER
 
#include<iostream>
#include<string>
#define FIRST	999
using namespace std;

void escape(int x, int y, int len, int maze[][102], int path[][102])
{	
	if(path[x][y] < len+1)
		return;
	path[x][y] = len+1;
	
	if(maze[x+1][y]) //down 
		escape(x+1, y, path[x][y], maze, path);
	if(maze[x][y+1]) //right
		escape(x, y+1, path[x][y], maze, path);
	if(maze[x][y-1]) //left
		escape(x, y-1, path[x][y], maze, path);
	if(maze[x-1][y]) //up
		escape(x-1, y, path[x][y], maze, path);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N=0, M=0;
	int maze[102][102]={0};
	int path[102][102]={0};
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
	
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=M ; j++)
			path[i][j]=FIRST;
			
	escape(1, 1, 0, maze, path);

	cout << path[N][M];
	
	return 0;
}
