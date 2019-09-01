#include<iostream>
using namespace std;
char maze[1002][1002]={{0}};
bool visit[1002][1002] = {{0}};
int lr[4] = {1, -1, 0, 0};
int ud[4] = {0, 0, 1, -1};
int q[2000000]={0};
int r=0;

int func(int fire)
{
	int f=0, pop=0, step=0, x=0, y=0, cntf=fire, tmpf=0, cntm=1, tmpm=0;
	while(f<r)
	{
		for(int i=0 ; i<cntf ; i++)
		{
			pop=q[f++];
			x=pop/10000;
			y=pop%10000;
			for(int i=0 ; i<4 ; i++)
			{
				if(maze[x+ud[i]][y+lr[i]]=='.' || maze[x+ud[i]][y+lr[i]]=='@')
				{
					maze[x+ud[i]][y+lr[i]]='*';
					tmpf++;
					q[r++]=(x+ud[i])*10000+(y+lr[i]);
				}
			}
		}
		step++;
		
		for(int i=0 ; i<cntm ; i++)
		{
			pop=q[f++];
			x=pop/10000;
			y=pop%10000;
			visit[x][y]=1;
			for(int i=0 ; i<4 ; i++)
			{
				if(maze[x+ud[i]][y+lr[i]]==0)
					return step;
				if(maze[x+ud[i]][y+lr[i]]=='.' && visit[x+ud[i]][y+lr[i]]==0)
				{
					maze[x+ud[i]][y+lr[i]]='@';
					tmpm++;
					q[r++]=(x+ud[i])*10000+(y+lr[i]);
				}
			}
		}
		if(tmpm==0)	return -1;
		cntm=tmpm;
		cntf=tmpf;	
		tmpm=0;
		tmpf=0;	
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T=0, w=0, h=0, pos=0, y=0, step=0, fire=0;
	
	cin >> T;
	
	for(int i=0 ; i<T ; i++)
	{
		cin >> w >> h;
		for(int p=1 ; p<=h ; p++)
			for(int z=1 ; z<=w ; z++)
			{
				cin >> maze[p][z];
				if(maze[p][z]=='@')
					pos = 10000*p+z;
				if(maze[p][z]=='*')
				{
					q[r++]=10000*p+z;
					fire++;
				}
			}
		
		q[r++]=pos;
		step = func(fire);
		if(step>0)	cout << step;
		else	cout << "IMPOSSIBLE";
		if(i<T-1)
		{
			cout << '\n';
			for(int p=0 ; p<=h+1 ; p++)
				for(int q=0 ; q<=w+1 ; q++)
				{
					maze[p][q]=0;
					visit[p][q]=0;
				}
			r=0;
			fire=0;
		} 
	}
	return 0;
}
