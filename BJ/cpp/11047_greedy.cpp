#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	int arr[10];
	int cnt=0;
	int t=0;
	
	cin >> N >> K;
	for(int i=0 ; i<N ; i++)
	{
		cin >> arr[i];
	}
	
	for(int i=N-1 ; i>=0 ; i--)
	{
		if((t=K/arr[i])!=0)
		{
			cnt += t;
			K-=(arr[i]*t);
		}
	}
	
	cout << cnt;
	
	return 0;
}
