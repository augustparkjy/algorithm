#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
	unsigned int start;
	unsigned int end;
}Meeting;

bool cmp(const Meeting &m1, const Meeting &m2)
{
	if(m1.end < m2.end)
		return true;
    else if(m1.end == m2.end && m1.start < m2.start)
        return true;
    else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N=0, cnt=1;
	unsigned int s=0, e=0;
	
	Meeting m[100000];
	Meeting min;
	
	cin >> N;
	
	for(int i=0; i<N ; i++)
	{
		cin >> s >> e;
		
		m[i].start = s;
		m[i].end = e;	
	}
	
	sort(m, m+N, cmp);
	
	min = m[0];
	
	for(int i=1 ; i<N ; i++)
	{
		if(min.end > m[i].start) continue;
		cnt++;
		min=m[i];
	}
	
	cout << cnt;
	
	return 0;
}
