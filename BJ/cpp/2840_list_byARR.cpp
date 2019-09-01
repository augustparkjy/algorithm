#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, k=0, pnt=0, cnt=0;
	char wheel[25]={0}, word=0;
	char alpha[26]={0};
	cin >> n >> k;
	
	for(int i=0 ; i<k ; i++)
	{
		cin >> pnt >> word;
		cnt=(cnt+pnt)%n;
		if((wheel[cnt] != 0 && wheel[cnt] != word) || (alpha[word-65] && wheel[cnt]==0))
		{
			cout << '!';
			return 0;
		}
		wheel[cnt] = word;	
		alpha[word-65] = 1;	
	}
	
	for(int i=0 ; i<n ; i++)
	{
		if(cnt-i<0)
		{
			if(wheel[n-(i-cnt)]==0)
				cout << '?';
			else
				cout << wheel[n-(i-cnt)];
		}
		else
		{
			if(wheel[cnt-i]==0)
				cout << '?';
			else
				cout << wheel[cnt-i];
		}
	}
	
	return 0;
}
