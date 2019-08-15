// f(n) = 2*f(n-2) + f(n-1)
// f(n) = (1 + f(n-1)) + (¤±+f(n-2)) ¤±x2 
#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N=0, arr[1001]={0,1,3};
	cin >> N;
	
	for(int i=3 ; i<=N ; i++)
	{
		if(i%2==1) arr[i]=((arr[i-1]-1)*2 +1)%10007;
		else arr[i]=((arr[i-1]-1)*2 + 3)%10007;
	}
	
	cout << arr[N];
	return 0;
}
