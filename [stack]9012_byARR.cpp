#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int k=0;
	string str;
	
	cin>>T;
	
	for(int i=0 ; i<T ; i++)
	{
		cin >> str;
		k=0;
		for(int j=0 ; j<str.size() && k>=0 ; j++)
			str[j]=='(' ? k++ : k--;
			
		k==0 ? cout << "YES\n" : cout <<"NO\n";
	}
	return 0;
}
