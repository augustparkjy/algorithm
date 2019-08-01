/*
** reference :
** https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220787042377&categoryNo=299&parentCategoryNo=0&viewDate=&currentPage=10&postListTopCurrentPage=1&from=menu&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=10
*/
#include <iostream>
#define NOPATH 1000000000
using namespace std;

int N, W[16][16], dp[16][1<<16];

int TSP(int current, int visited)
{
	int x=0;
	int &len = dp[current][visited];
	if(len != -1) return len;
	if(visited == (1<<N)-1)
	{
		if(W[current][0] != 0) return W[current][0];
		return NOPATH;
	}
	len = NOPATH;
	for(int i=0 ; i<N ; i++)
	{
		if(visited & (1<<i) || W[current][i]==0) continue;
		x=TSP(i, visited | (1<<i));
		len = (len >= x + W[current][i] ? x + W[current][i] : len);
	}
	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			cin >> W[i][j];
	
	for(int i=0 ; i<16 ; i++)
		for(int j=0 ; j<(1<<16) ; j++)
			dp[i][j] = -1;
	
	cout << TSP(0,1);
	return 0;
}
