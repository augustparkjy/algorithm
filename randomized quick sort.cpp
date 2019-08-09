#include <iostream>
#include <ctime>
#define MAX	100
using namespace std;

int arr[MAX];
void qsort_a(int i, int j) //ascending
{
	if(i>=j) return;
	int left=i, right=j, pivot = arr[rand()%(j-i)+i];
	
	while(left <= right)
	{
		while(arr[left]<pivot) left++;
		while(arr[right]>pivot) right--;
		if(left<=right)
			swap(arr[left++], arr[right--]);
	}
	qsort_a(i, right);
	qsort_a(left, j);
}

void qsort_d(int i, int j) // descending
{
	if(i>=j) return;
	int left=i, right=j, pivot = arr[rand()%(j-i)+i];
	
	while(left <= right)
	{
		while(arr[left]>pivot) left++;
		while(arr[right]<pivot) right--;
		if(left<=right)
			swap(arr[left++], arr[right--]);
	}
	qsort_d(i, right);
	qsort_d(left, j);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	srand((unsigned int)time(NULL));
	
	for(int i=0 ; i<MAX ; i++)
		arr[i] = rand()%1000;
	
	qsort_a(0, MAX-1);
	
	cout<< "sort ascending\n";
	for(int i=0 ; i<MAX ; i++)
		cout << arr[i] << ' ';
	
	cout << '\n';
	qsort_d(0, MAX-1);
	cout << "sort descending\n";
	for(int i=0 ; i<MAX ; i++)
		cout << arr[i] << ' ';
	return 0;
}
