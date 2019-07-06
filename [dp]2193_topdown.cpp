#include <iostream>
using namespace std;
int pinary(int n)
{
    if(n<=2) return 1;
    return pinary(n-1)+pinary(n-2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;	
    
	cin >> N;
	cout << pinary(N);
	
	return 0;
}
