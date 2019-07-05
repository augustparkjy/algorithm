#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, L;
	int arr[1001] = {0};
	int x;
	int tape = 0;
	
	cin >> N >> L;
	
	for(int i=0 ; i<N ; i++)
	{
		cin >> x;
		arr[x] = 1;
	}
	
	for(int i=0 ; i< 1001 ; i++)
	{
		if(arr[i]==1)
		{
			tape++;
			i+=L-1;
		}
	}
	
	cout << tape << flush;
	
	return 0;
}
