#include <iostream>
#include <algorithm>
typedef long long INT;
using namespace std;

INT a[1000000]={0};
bool desc(int a, int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0;
	INT m=0, c=1, t=0, min=0, max=0;
	
	cin >> n >> m;
	
	for(int i=0 ; i<n ; i++)
	{
		cin >> a[i];
		if(a[i]>max)
			max = a[i];
	}
	sort(a, a+n, desc);
	while(c>=1)
	{
		t=0;
		c=(max+min)/2;
		for(int i=0 ; i<n ; i++)
		{
			if(a[i]<=c)
				break;
			t+=a[i]-c;
		}
		if(min==max || min==c || max==c || t==m)
			break;
		else if(t>m)
			min=c;
		else
			max=c;
	}
	
	cout << c;

	return 0;
}
