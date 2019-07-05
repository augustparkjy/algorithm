#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k=1;
	int n, t;
	
	cin>>n;
	
	for(k=1;n/(10*k)!=0;k*=10);
		
	for (int i=(int)(n*0.8) ; i<n ; i++)
	{
		t=i;
		for(int j=1 ; j<=k ; j*=10)
		{
			t+=((i/j)%10);
		}
		if(n==t)
		{
			cout << i << '\n';
			return 0;
		}
	}
	
	cout << "0\n";
	
	return 0;
	
}
