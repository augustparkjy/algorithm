#include <iostream>
using namespace std;
typedef unsigned long long INT;

INT mul(INT a, INT b, INT c)
{	
	if(b==1)
		return a%c;
			
	INT temp=mul(a, b/2, c)%c;

	if(b%2==1)
		return (((temp*temp)%c)*a)%c;
	else
		return (temp*temp)%c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	INT a=0, b=0, c=0;
	
	cin >> a >> b >> c;
	cout << mul(a, b, c);
	
	return 0;
}
