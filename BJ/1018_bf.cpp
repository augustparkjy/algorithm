#include <iostream>
using namespace std;

int func(int x, int y, char (*chess)[50])
{
	int cnt=0;
	char c='B';
	
	for(int i=x ; i<x+8 ; i++)
	{
		for(int j=y ; j<y+8 ; j++)
		{
			if(c=='B')
			{
				if(chess[i][j]=='W') cnt++;
				c='W';
			}
			else
			{
				if(chess[i][j]=='B') cnt++;
				c='B';
			}	
		}
			if(c=='B') c='W';
			else c='B';
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M=0, N=0, change=64, temp=0;
	char chess[50][50]={0};
	
	cin >> M >> N;
	
	for(int i=0 ; i<M ; i++)
		for(int j=0 ; j<N ; j++)
			cin >> chess[i][j];
	
	
	for(int i=0; i<=M-8 ; i++)
		for(int j=0 ; j<=N-8 ; j++)
		{
			temp = func(i, j, chess);
			if(temp > 32) temp = 64-temp;
			if(temp < change)
				change = temp;
		}
	
	cout << change;
	
	return 0;
}
