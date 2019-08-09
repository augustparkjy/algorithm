#include<iostream>
#include<ctime>
#define MAX 20
using namespace std;

int arr[MAX];
int arr2[MAX];
	
void msort_a(int i, int m, int j)
{
	int l=i, r=m+1, p=i;
	while (l<=m && r<=j)
	{
		if (arr[l]>arr[r]) arr2[p++] = arr[r++];
		else arr2[p++] = arr[l++];
	}

	int tmp = l > m ? r : l;
	while(p<=j) arr2[p++]=arr[tmp++];
	for(int x=i ; x<=j ; x++)
		arr[x]=arr2[x];
}

void msort_d(int i, int m, int j)
{
	int l=i, r=m+1, p=i;
	while(l<=m && r <=j)
	{
		if(arr[l]<arr[r]) arr2[p++]=arr[r++];
		else arr2[p++]=arr[l++];
	}
	int tmp= l>m ? r : l;
	while(p<=j) arr2[p++]=arr[tmp++];
	for(int x=i ; x<=j ; x++)
		arr[x]=arr2[x];
}

void partition_a(int i, int j)
{
	if (i == j) return;
	int m = (i + j) / 2;

	partition_a(i, m);
	partition_a(m + 1, j);
	msort_a(i, m, j);
}

void partition_d(int i, int j)
{
	if (i == j) return;
	int m = (i + j) / 2;

	partition_d(i, m);
	partition_d(m+1, j);

	msort_d(i, m, j);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	srand((unsigned int)time(NULL));

	for (int i = 0; i<MAX; i++)
		arr[i] = rand() % 1000;

	partition_a(0, MAX - 1);

	cout << "sort ascending\n";
	for (int i = 0; i<MAX; i++)
		cout << arr2[i] << ' ';
	
	cout << '\n';
	
	partition_d(0, MAX - 1);
	
	cout << "sort descending\n";
	for(int i=0 ; i<MAX ; i++)
		cout << arr2[i] << ' ';

	return 0;
}
