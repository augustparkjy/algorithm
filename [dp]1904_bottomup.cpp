#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	unsigned long long x=1, y=2;
	
	cin >> N ;
	
	while(N-->1)
	{
		x=((y+=x)-x)%15746;	
	}
	
	cout << x;
	
	return 0;
}
