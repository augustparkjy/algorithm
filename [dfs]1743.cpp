#include <iostream>
using namespace std;

int DFS(int x, int y, int arr[][102], int* k)
{
	(*k)--;
	int n=1;
	arr[x][y] = 0;
	
	if(arr[x+1][y]) n += DFS(x+1, y, arr, k);
	if(arr[x][y+1]) n += DFS(x, y+1, arr, k);
	if(arr[x][y-1]) n += DFS(x, y-1, arr, k);
	if(arr[x-1][y]) n += DFS(x-1, y, arr, k);
	
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N=0, M=0, K=0;
	int r=0, c=0;
	int arr[102][102] = {0};
	int size=0;
	int temp=0;
	
	cin >> N >> M >> K;
	
	for(int i=0 ; i<K ; i++)
	{
		cin >> r >> c;
		arr[r][c] = 1;
	}
	
	for(int i=1 ; i<=N && K!=0; i++)
		for(int j=1 ; j<=M && K!=0 ; j++)
			if(arr[i][j])
				if(size < (temp=DFS(i,j,arr,&K))) size = temp;

    cout << size;
	
	return 0;
}
