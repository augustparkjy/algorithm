#include<iostream>
using namespace std;

char building[32][32][32];
bool visit[32][32][32];

void escape(int pos)
{
	int i=1, x=0, y=0, z=0, f=0, r=0, pop=0, push=0, q[27000]={0}, step=0, lr[] = {1, -1, 0, 0, 0, 0}, ud[] = {0, 0, 0, 0, 1, -1}, bf[] = {0, 0, -1, 1, 0, 0};
	q[r++] = pos;
	
	while(f<r)
	{
		for( ; i>0 ; i--)
		{
			pop = q[f++];
			x = pop/10000;
			y = (pop%10000)/100;
			z = pop%100;
			visit[x][y][z] = 1;
			
			for(int j=0 ; j<6 ; j++)
			{
				if(building[x+ud[j]][y+bf[j]][z+lr[j]]=='E')
				{
					cout << "Escaped in " << step+1 << " minute(s).\n";
					return;
				}
				
				if(building[x+ud[j]][y+bf[j]][z+lr[j]]=='.' && visit[x+ud[j]][y+bf[j]][z+lr[j]]==0)
				{	
					push++;
					q[r++] = (x+ud[j])*10000 + (y+bf[j])*100 + (z+lr[j]);
					building[x+ud[j]][y+bf[j]][z+lr[j]]='S';
				}
			}
		}
		i=push;
		push=0;
		step++;
	}
	
	cout << "Trapped!\n";
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int L=0, R=0, C=0, pos=0;
	
	while(1)
	{
		cin >> L >> R >> C;
		
		if(L+R+C == 0)
			return 0;
			
		for(int i=1 ; i<=L ; i++)
			for(int j=1 ; j<=R ; j++)
				for(int k=1 ; k<=C ; k++)
				{
					cin >> building[i][j][k];
					if(building[i][j][k]=='S')
						pos = i*10000 + j*100 + k;
				}
		
		escape(pos);
		
		for(int i=1 ; i<=L ; i++)
			for(int j=1 ; j<=R ; j++)
				for(int k=1 ; k<=C ; k++)
				{
					building[i][j][k] = 0;
					visit[i][j][k] = 0;
				}
	}
	
	return 0;
}
