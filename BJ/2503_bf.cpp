#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, s=0, b=0, in=0;
	int back=0, sip=0, il=0, r[988]={0}, cnt=0;
		
	cin >> n;
	
	for(int i=0 ; i<n ; i++)
	{
		cin >> in >> s >> b;
		
		back = in/100 * 100;
		sip = (in-back)/10 * 10;
		il = in - back - sip;
		
		if(s==3)
		{
			cout << 1;
			return 0;
		}
		else if(s==2)
		{
			for(int i=1 ; i<=9 ; i++)
			{
				if(i==il || back/100 ==i || sip/10==i) continue;
				r[back+sip+i]++; //SSX
				r[back+i*10+il]++; //SXS
				r[i*100+sip+il]++; //XSS 
			}
		}
		else if(s==1)
		{
			if(b==2)
			{
				r[back+il*10+sip/10]++; //SBB
				r[il*100+sip+back/100]++; //BSB
				r[sip*10+back/10+il]++; //BBS
			}
			else if(b==1)
			{
				for(int i=1 ; i<=9 ; i++)
				{
					if(i==il || i==sip/10 || i==back/100) continue;	
					r[back+i*10+sip/10]++; //SBX
					r[i*100+sip+back/100]++; //BSX
					r[back+il*10+i]++; //SXB
					r[i*100+back/10+il]++; //BXS
					r[il*100+sip+i]++; //XSB
					r[sip*10+i*10+il]++; //XBS
				}
			}
			else
			{
				for(int i=1 ; i<=9 ; i++)
				{
					for(int j=1 ; j<=9 ; j++)
					{
						if(i==j || back/100==i || back/100==j || sip/10==i || sip/10==j || il==i || il==j) continue;
						r[back+i*10+j]++; //SXX
						r[i*100+sip+j]++; //XSX
						r[i*100+j*10+il]++; //XXS
					}					
				}
			}
		}
		else if(s==0)
		{
			if(b==3)
			{
				r[sip*10+il*10+back/100]++;
				r[il*100+back/10+sip/10]++;
			}
			else if(b==2)
			{
				for(int i=1 ; i<=9 ; i++)
				{
					if(back/100==i || sip/10==i || il==i) continue;
					r[sip*10+back/10+i]++; //BBX
					r[i*100+back/10+sip/10]++; //BBX
					r[sip*10+back/100+i*10]++; //BBX
					r[il*100+back/100+i*10]++; //BXB
					r[back/10+il*100+i]++; //BXB
					r[il*10+back/100+i*100]++; //BXB
					r[i*100+il*10+sip/10]++; //XBB
					r[il*100+sip/10+i*10]++; //XBB
					r[sip*10+il*10+i]++; //XBB
				}
			}
			else if(b==1)
			{
				for(int i=1 ; i<=9 ; i++)
				{
					for(int j=1 ; j<=9 ; j++)
					{
						if(i==j || back/100==i || back/100==j || sip/10==i || sip/10==j || il==i || il==j) continue;
						r[i*100+j*10+back/100]++; //BXX
						r[i*100+back/10+j]++; //BXX
						r[sip*10+i*10+j]++; //XBX
						r[i*100+j*10+sip/10]++; //XBX
						r[il*100+i*10+j]++; //XXB
						r[i*100+il*10+j]++; //XXB
					}					
				}
			}
			else
			{
				for(int i=1 ; i<=9 ; i++)
				{
					for(int j=1 ; j<=9 ; j++)
					{
                        if(i==j) continue;
						for(int p=1 ; p<=9 ; p++)
						{
							if(i==p || j==p || back/100 ==p || back/100==i || back/100==j || sip/10==p || sip/10==i || sip/10==j || il==p || il==i || il==j) continue;
							r[i*100+j*10+p]++; //XXX
						}					
					}
				}
			}
		}
	}
	
	for(int i=123 ; i<=987 ; i++)
		if(r[i]==n) cnt++;
		
	cout << cnt;
	return 0;
}
