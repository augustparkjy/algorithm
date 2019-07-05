#include <iostream>
using namespace std;

int count(char b[][51], int n, int i, int j, int x)
{
	int c;
	
	for(int p=i ; p<i+2 ;p++)
	{
		c=1;
		for(int q=0 ; q<n-1 ; q++)
		{
			if(p==n) break;
			else
			{
				if(b[p][q] == b[p][q+1])
					c++;
				else
				{
					if(c>x)
						x=c;
					c=1;
				}
			}
		}
		if(c>x)
			x=c;
	}
	
	for(int p=j ; p<j+2 ;p++)
	{
		c=1;
		for(int q=0 ; q<n-1 ; q++)
		{
			if(p==n) break;
			else
			{
				if(b[q][p] == b[q+1][p])
					c++;
				else
				{
					if(c>x)
						x=c;
					c=1;
				}
			}
		}
		if(c>x)
			x=c;
	}

	return x;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	char b[51][51] = {0};
	int n;
	int t1, t2;
	int x=0;
	
	cin >> n;
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cin >> b[i][j];
		}
	}
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{	
			x=count(b, n, i, j, x);
			
			if(b[i][j+1] != 0)
			{
				if(b[i][j]!=b[i][j+1])
				{
					t1=b[i][j];
					t2=b[i][j+1];
					
					b[i][j] = t2;
					b[i][j+1] = t1;
					
					x=count(b, n, i, j, x);		
					
					b[i][j] = t1;
					b[i][j+1] = t2;		
				}		
			}
			
			if(b[i+1][j] !=0)
			{
				if(b[i][j]!=b[i+1][j])
				{
					t1=b[i][j];
					t2=b[i+1][j];
					
					b[i][j] = t2;
					b[i+1][j] = t1;
					
					x=count(b, n, i, j, x);					

					b[i][j] = t1;
					b[i+1][j] = t2;		
				}
			}
		}
	}
	
	cout << x << '\n';
	
	return 0;
}
