#include <iostream>
using namespace std;
int f(int x)
{
    int t1, t2;
    if(x<=1) return 0;
    t1 = f(x/3)+x%3+1;
    t2 = f(x/2)+x%2+1;
    return t1 > t2 ? t2 : t1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
		
	int x;
	
	cin >> x;
	cout << f(x);
    
	return 0;
}
