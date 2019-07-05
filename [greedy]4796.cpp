#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int L, P, V;
	int T=1;
	int days=0;
	
	while(1)
	{
		cin >> L >> P >> V;
	
		if(L+P+V==0)
			break;
		
		days = (V/P)*L;
		if(V%P > L)
			days += L;
		else
			days += V%P;
		
		cout << "Case " << T << ": " <<days<<'\n'<<flush;
		T++;
	}

	return 0;
}
