#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N=0, city[10000]={0}, max=0, min=1, x=0, t=0, ans=0;
	unsigned int M=0;
	
	cin >> N;
	
	for(int i=0 ; i<N ; i++)
	{
		cin >> city[i];
		t += city[i];
		if(city[i]>max)
			max = city[i];
	}
	
	cin >> M;
	
	if(t<=M)
	{
		cout << max;
		return 0;
	}
	
	while(min<=max)
	{
		t=0;
		x=(min+max)/2;
		for(int i=0 ; i<N ; i++)
		{
			if(city[i] <= x)
				t+=city[i];
			else
				t+=x;
		}
		if(t==M)
		{
			cout << x;
			return 0;
		}
		else if(t>M)
			max=x-1;
		else
		{
			min=x+1;
			ans=x;
		}
	}
	
	cout << ans;
	return 0;
}
