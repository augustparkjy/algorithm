#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string cmd;
	int x=0, M=0, bitmask=0;
	
	cin >> M;
	
	for(int i=0 ; i<M ; i++)
	{
		cin >> cmd;
		if(cmd=="add")
		{
			cin >> x;
			if(!(bitmask & (1<<x)))
			{
				bitmask |= (1<<x);
			}
		}
		else if(cmd=="remove")
		{
			cin >> x;
			if(bitmask & (1<<x))
			{
				bitmask &= ~(1<<x);
			}
		}
		else if(cmd=="check")
		{
			cin >> x;
			if(bitmask & (1<<x))
				cout<< 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(cmd=="toggle")
		{
			cin >> x;
			if(bitmask & (1<<x))
				bitmask &= ~(1<<x);
			else
				bitmask |= (1<<x);
		}
		else if(cmd=="all")
		{
			bitmask |= (1<<21)-1;
		}
		else // s=="empty"
		{
			bitmask &= 0;
		}	
	}

	return 0;
}
