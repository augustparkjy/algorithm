#include <iostream>
#define MAX 50
using namespace std;

class Heap
{
public:
	int heap[MAX+1]={0};
	int cnt;

	Heap():cnt(0){}
	
	void insert(int key)
	{
		int child = ++cnt;
		int parent = child/2;
		
		while(child>1 && key > heap[parent])
		{
			heap[child]=heap[parent];
			child=parent;
			parent=child/2;
		}
		heap[child]=key;
	}
	
	int remove()
	{
		int max = heap[1];
		int parent=1, child=parent*2;
		int temp = heap[cnt--];
		
		while(child<=cnt)
		{
			if((child < cnt) && heap[child] < heap[child+1])
				child++;
			if(temp >= heap[child])
				break;
				
			heap[parent] = heap[child];
			
			parent=child;
			child*=2;
		}
		
		heap[parent] = temp;
		return max;
	}
	
	int pop()
	{
		return heap[1];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, data=0;
	Heap h;
	
	cin >> n;
	
	for(int i=0 ; i<n ; i++)
	{
		cin >> data;
		h.insert(data);
	}
	
	for(int i=0 ; i<h.cnt ; i++)
	{
		cout << h.remove();
	}
	
	return 0;
}
