#include<iostream>
#include<algorithm>
using namespace std;

char m[27][27]={0};
int lr[4] = {1, -1, 0, 0};
int bf[4] = {0, 0, -1, 1};
int c=0;

int func(int n, int x, int y, int cnt)
{	
	cnt++;
	m[x][y]='0';
	if(m[x][y+1] == '0' && m[x][y-1] == '0' && m[x-1][y] == '0' && m[x+1][y] == '0') return cnt;
	
	for(int k=0 ; k<4 ; k++)
		if(m[x+bf[k]][y+lr[k]]=='1')
			cnt = func(n, x+bf[k], y+lr[k], cnt);
	
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, homes[625]={0}, k=0;
	cin >> n;
	
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			cin >> m[i][j];
		
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
		{
			if(m[i][j]=='1')
			{
				c++;
				homes[k++]=func(n, i, j, 0);
			}
		}
	
	sort(homes, homes+k);
	
	cout << c;
	for(int i=0 ; i<k ; i++)
		cout << '\n' << homes[i];
	return 0;
}
