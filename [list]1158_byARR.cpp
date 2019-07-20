#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	int cnt=0, i=0, j=0, r=0;
	
	int q[5000]={false};
	cin >> N >> K;
	cout <<'<';
	for(i=0 ; cnt<N ; )
	{
		for(j=0 ; r<K ; j++)
		{
			if(!q[(i+j)%N])
				r++;
		}
		q[(i+j-1)%N] = true;
		i=(i+j)%N;
		if(i==0)
			cout<<N;
		else
			cout << i;
		cnt++;
		r=0;
		if(cnt < N)
			cout << ", ";
	}
	cout << '>';
	
	return 0;
}
