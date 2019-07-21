#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int stack[10000];
	int N=0, X=0, i=0;
	string cmd;
		
	cin >> N;
	
	for(int j=0 ; j<N ; j++)
	{
		cin >> cmd;
		if(cmd == "push")
		{
			cin >> X;
			stack[i] = X;
			i++;
		}
		else if(cmd == "pop")
		{
			if(i==0) cout << -1 << '\n';
			else
			{
				cout << stack[i-1] << '\n';
				i--;
			}
		}
		else if(cmd == "size")
			cout << i << '\n';
		else if(cmd == "empty")
		{
			if(i==0) cout << 1 <<'\n';
			else cout << 0 << '\n';
		}
		else
		{
			if(i==0) cout << -1 <<'\n';
			else cout << stack[i-1] << '\n';
		}
	}
	
	return 0;
}
