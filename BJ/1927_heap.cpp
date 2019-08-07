#include <iostream>
using namespace std;
typedef unsigned int INT;
INT h[100000]={0};
int cnt=0;

void insert(int k)
{
	int c=++cnt, p=c/2;
	
	while(c>1 && k < h[p])
	{
		h[c]=h[p];
		c=p;
		p=c/2;
	}
	h[c] = k;
	return;
}

int remove()
{
	int min = h[1], p=1, c=2, t=h[cnt--];
	
	while(c<=cnt)
	{
		if(c<cnt && h[c] >=h[c+1])
			c++;
		if(t<h[c])
			break;
		h[p]=h[c];
		p=c;
		c*=2;
	}
	h[p] = t;
	return min;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, x=0;
	
	cin >> n;
	for(int i=0 ; i<n ; i++)
	{
		cin >> x;
		if(x==0)
		{
			if(cnt==0)
				cout << 0 <<'\n';
			else
				cout << remove() << '\n';
		}
		else
		{
			insert(x);
		}
	}
	return 0;
}
