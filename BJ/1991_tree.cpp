#include <iostream>
using namespace std;

char g[26][26]={{0}};
void preorder(int cur, int t)
{
	int l=0, r=0;
	
	for(int i=0 ; i<t ; i++)
	{
		if(g[cur][i]=='l') l = i;
		if(g[cur][i]=='r') r = i;
	}
	cout << (char)(cur+65);
	if(l!=0) preorder(l, t);
	if(r!=0) preorder(r, t);
}

void inorder(int cur, int t)
{
	int l=0, r=0;
	
	for(int i=0 ; i<t ; i++)
	{
		if(g[cur][i]=='l') l = i;
		if(g[cur][i]=='r') r = i;
	}
	if(l!=0) inorder(l, t);
	cout << (char)(cur+65);
	if(r!=0) inorder(r, t);
}

void postorder(int cur, int t)
{
	int l=0, r=0;
	
	for(int i=0 ; i<t ; i++)
	{
		if(g[cur][i]=='l') l = i;
		if(g[cur][i]=='r') r = i;
	}
	if(l!=0) postorder(l, t);
	if(r!=0) postorder(r, t);
	cout << (char)(cur+65);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=0;
	char n=0, l=0, r=0;
	
	cin >> t;
	
	for(int i=0 ; i<t ; i++)
	{
		cin >> n >> l >> r;
		if(l!='.')
			g[n-65][l-65] = 'l';
		if(r!='.')
			g[n-65][r-65] = 'r';
	}
	
	preorder(0, t);cout << '\n';
	inorder(0, t);cout << '\n';
	postorder(0, t);cout <<'\n';
	
	return 0;
}

