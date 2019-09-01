#include <iostream>
using namespace std;

void DFS(int x, int y, int* k, int arr[][52])
{
	arr[x][y]=0;
	(*k)--;
	if(arr[x+1][y])
		DFS(x+1, y, k, arr);
	if(arr[x][y+1])
		DFS(x, y+1, k, arr);
	if(arr[x-1][y])
		DFS(x-1, y, k, arr);
	if(arr[x][y-1])
		DFS(x, y-1, k, arr);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T=0, M=0, N=0, K=0;
	int x=0, y=0;
	int arr[52][52] = {0};
	int cnt=0;
	
	cin >> T;
	for(int i=0 ; i<T ; i++)
	{
		cin >> M >> N >> K;
		
		for(int j=0 ; j<K ; j++)
		{
			cin >> x >> y;
			arr[x+1][y+1]=1;
		}
		
		cnt = 0;
		
		for(int p=1 ; p<M+1 && K!=0; p++)
		{
			for(int q=1 ; q<N+1 && K!=0 ; q++)
			{
				if(arr[p][q])
				{
					cnt++;
					DFS(p, q, &K, arr);
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
