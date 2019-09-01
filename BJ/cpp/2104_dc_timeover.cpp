#include<iostream> //worst case O(N) = N^2 > ex) 1 2 3 4 5 6 7 ... 
typedef long long INT;
using namespace std;
int arr[100000] = { 0 };

INT find(int i, int j)
{
	if(i==j)
		return arr[i]*arr[i];
		
	INT t1 = 0, t2 = 0, t3 = 0;
	int min = arr[j], pnt = j;
	for (int p = i; p <= j; p++)
	{
		if (arr[p]<min)
		{
			min = arr[p];
			pnt = p;
		}
		t1 += arr[p];
	}	
	t1 *= min;
	
	if (pnt == j)
	{
		t2 = find(i, pnt-1);
		return t1>t2 ? t1 : t2;
	}
	
	if (pnt == i)
	{
		t2 = find(pnt+1, j);
		return t1>t2 ? t1 : t2;
	}
	
	t2 = find(i, pnt);
	t3 = find(pnt + 1, j);
	return (t1>t2 ? (t1>t3 ? t1 : t3) : (t2>t3 ? t2 : t3));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;

	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> arr[i];

	cout << find(0, n - 1);

	return 0;
}
