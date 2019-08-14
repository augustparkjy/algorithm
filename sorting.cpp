#include <iostream>
#include <ctime>
using namespace std;

void merge(int l, int m, int r, int* arr, int* arr2)
{
	int x=l, y=m+1, z=r, k=l;
	while(x<=m&&y<=z)
	{
		if(arr[x]>arr[y]) arr2[k++] = arr[y++];
		else arr2[k++] = arr[x++];
	}
	
	while(x<=m) arr2[k++]=arr[x++];
	for(int i=l ; i<k ; i++)
		arr[i]=arr2[i];
}


void sortByMerge(int l, int r, int* arr, int* arr2)
{
	if(l==r) return;
	int m = (l+r)/2;
	
	sortByMerge(l, m, arr, arr2);
	sortByMerge(m+1, r, arr, arr2);
	merge(l, m, r, arr, arr2);
}

void merge2(int l, int m, int r, int* ar, int* ar2)
{
	int x=l, y=m+1, k=l;
	
	while(x<=m && y<=r)
	{
		if(ar[x] < ar[y]) ar2[k++] = ar[y++];
		else ar2[k++] = ar[x++];
	}
	
	while(x<=m) ar2[k++] = ar[x++];
	for(int i=l ; i<k ; i++)
		ar[i] = ar2[i];
}

void sortByMerge2(int l, int r, int* ar, int* ar2)
{
	if(l==r) return;
	int m = (l+r)/2;
	
	sortByMerge2(l, m, ar, ar2);
	sortByMerge2(m+1, r, ar, ar2);
	merge2(l, m, r, ar, ar2);
}

void sortByQuick(int l, int r, int* ar)
{
	if(r<=l) return;
	int x=l, y=r, p=ar[rand()%(r-l)+l];
	while(x<=y)
	{
		while(ar[x]<p) x++;
		while(ar[y]>p) y--;
		if(x<=y) swap(ar[x++], ar[y--]);
	}
	sortByQuick(l, y, ar);
	sortByQuick(x, r, ar);
}

void sortByQuick2(int l, int r, int* ar)
{
	if(l>=r) return;
	int x=l, y=r, p=ar[rand()%(l-r)+l];
	while(x<=y)
	{
		while(ar[x]>p) x++;
		while(ar[y]<p) y--;
		if(x<=y) swap(ar[x++], ar[y--]);
	}
	sortByQuick2(l, y, ar);
	sortByQuick2(x, r, ar);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	srand((unsigned int)time(NULL));
	int a[] = {5,2,3,1,9,6,7,4,8,0};
	int a2[10] = {0};
	
	sortByMerge(0, 9, a, a2);
	for(int i=0 ; i<10 ; i++)
		cout << a[i] << ' ';
	cout << '\n';
	
	sortByMerge2(0, 9, a, a2);
	for(int i=0 ; i<10 ; i++)
		cout << a[i] << ' ';
	cout << '\n';
	
	sortByQuick(0, 9, a);
	for(int i=0 ; i<10 ; i++)
		cout << a[i] << ' ';
	cout << '\n';
	
	sortByQuick2(0, 9, a);
	for(int i=0 ; i<10 ; i++)
		cout << a[i] << ' ';
	cout << '\n';
	
	return 0;
}
