#include <iostream>
using namespace std;

int eureka(int arr[], int n)
{
	for(int x=0 ; x<44 ; x++)
			for(int y=0 ; y<44 ; y++)
				for(int z=0 ; z<44 ; z++)
				{
					if(n==arr[x]+arr[y]+arr[z])
						return 1;
				}
	
	return 0;			
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, n;
	int arr[44];
	
	for(int i=0 ; i<44 ; i++)
	{
		arr[i] = ((i+1)*(i+2))/2;
	}
	
	cin >> T;
	
	
	for(int i=0 ; i<T ; i++)
	{
		cin >> n;
		cout << eureka(arr, n) << '\n' << flush;
	}
	
	return 0;
}
