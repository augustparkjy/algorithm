#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
		
	int x;
	short arr[1000001];
	
	cin >> x;
	
	arr[0] = 9999;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;	
	
	for(int i=4 ; i<1000001 ; i++)
	{	
		arr[i] = 1+arr[i-1];
		if(i%3==0 && (1+arr[i/3])<arr[i])
			arr[i] = 1+arr[i/3];
		if(i%2==0 && (1+arr[i/2])<arr[i])
			arr[i] = 1+arr[i/2];
	}

	cout << arr[x];
	
	return 0;
}
