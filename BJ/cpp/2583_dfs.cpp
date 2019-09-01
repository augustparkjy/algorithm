#include <iostream>
using namespace std;
int arr[100][100]={0};
int lr[4] = {1, -1, 0, 0};
int ud[4] = {0, 0, 1, -1};

int func(int M, int N, int x, int y)
{
	int size=1;
	arr[x][y]=1;
	if(x-1<=0 && x+1 >=M && y-1<=0 && y+1 >=N && arr[x][y+1]==1 && arr[x][y-1]==1 && arr[x-1][y]==1 && arr[x+1][y]==1)
		return 1;
	
	for(int i=0 ; i<4 ; i++)
		if(arr[x+ud[i]][y+lr[i]]==0 && x+ud[i]>=0 && x+ud[i] <=M-1 && y+lr[i] >=0 && y+lr[i] <= N-1)
			size += func(M, N, x+ud[i], y+lr[i]);

	return size;
}

void merge(int l, int m, int r, int* data)
{
	int x=l, y=m+1, k=l, temp[5000]={0};
	while(x<=m && y<=r)
	{
		if(data[x]<data[y]) temp[k++]=data[x++];
		else temp[k++]=data[y++];
	}
	
	while(x<=r) temp[k++]=data[x++];
	for(int i=l ; i<=r ; i++)
		data[i]=temp[i];
}

void sort(int l, int r, int* data)
{
	if(l>=r)
		return;
	int m = (l+r)/2;
	sort(l, m, data);
	sort(m+1, r, data);
	merge(l, m, r, data);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M=0, N=0, K=0, lx=0, ly=0, rx=0, ry=0, cnt=0, size=0, data[5000]={0};
	
	cin >> M >> N >> K;
	
	for(int i=0 ; i<K ; i++)
	{
		cin >> lx >> ly >> rx >> ry;
		
		for(int i=ly ; i<ry ; i++)
			for(int j=lx ; j<rx ; j++)
				arr[i][j] = 1;
	}
	
	for(int i=0 ; i<M ; i++)
		for(int j=0 ; j<N ; j++)
		{
			if(arr[i][j]==0){
				size=func(M, N, i, j);
				data[cnt++] = size;
			}
		}
	
	sort(0, cnt-1, data);
	
	cout << cnt << '\n';
	for(int i=0 ; i<cnt ; i++)
		cout << data[i] << ' ';
		
	return 0;
}
