#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	unsigned long long arr[90];
	
	cin >> N;
	
	arr[0]=1; arr[1]=1;
	for(int i=2 ; i<N ; i++)
	{
		arr[i] = arr[i-1]+arr[i-2];
	}
	
	cout << arr[N-1];
	
	return 0;
}
