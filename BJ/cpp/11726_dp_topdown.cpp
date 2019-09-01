#include <iostream>
using namespace std;

int computing(int x, int arr[])
{
	if(arr[x]!=0)
		return arr[x];
	if(x<=0) 
		return 0;
	
	return arr[x] = (computing(x-2, arr) + computing(x-1, arr))%10007;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0;
	int arr[1001]={0,1,2};
	
	cin >> n;
	
	cout << computing(n, arr);
	
	return 0;
}
