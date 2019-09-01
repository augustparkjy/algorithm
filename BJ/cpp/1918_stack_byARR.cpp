#include<iostream>
using namespace std;

int getPri(char x)
{
	if(x=='*' ||x=='/') return 1;
	else if(x=='+'||x=='-') return 2;
	else return 3;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	char s[101];
	char stack[65];
	char op;
	int pos=0;
	cin >> s;
	
	for(int i=0 ; s[i]!='\0' ; i++)
	{
		op=s[i];
		if(op=='(') stack[pos++]=op;
		else if(op==')')
		{
			while(1)
			{
				if(stack[pos-1]=='(')
				{
					pos--;
					break;
				}
				cout << stack[--pos];
			}	
		}
		else if(op=='+'||op=='-'||op=='*'||op=='/')
		{
			if(getPri(stack[pos-1]) > getPri(op)) 
				stack[pos++] = op;
			else
			{
				while(1)
				{
					if(getPri(stack[pos-1]) > getPri(op))
						break;
					cout << stack[--pos];
				}
				stack[pos++] = op;
			}
		}
		else
			cout << op;
	}
	
	while(pos!=0)
		cout << stack[--pos];
		
	return 0;
}
