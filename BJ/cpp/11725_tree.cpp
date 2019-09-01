#include<iostream>
using namespace std;

class Node
{
public:
	int num;
	Node* next;
	Node(int n, Node* nxt):num(n), next(nxt){}
};

class List
{
public:
	int size;
	Node* head;
	Node* cur;
	List():size(0), head(nullptr){}
	~List()
	{
		Node* temp = head;
		for(int i=0 ; i<size ;i++)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
	
	void push(int d)
	{
		if(size==0)
			head=new Node(d, nullptr);
		else
		{
			head=new Node(d, head);
		}
		size++;
		cur = head;
	}
	
	Node* iter()
	{
		Node* temp = cur;
		if(cur->next == nullptr)
			cur = head;
		else
			cur = cur->next;
		
		return temp;
	}
};

List l[100000];
int parent[100000]={0};

void DFS(int cur)
{
	for(int i=0 ; i<l[cur].size ; i++)
	{
		Node* next = l[cur].iter();
		if(parent[next->num] == 0)
		{
			parent[next->num] = cur+1;
			DFS(next->num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, x=0, y=0;
	cin >> n;
	
	for(int i=0 ; i<n-1 ; i++)
	{
		cin >> x >> y;
		l[x-1].push(y-1);
		l[y-1].push(x-1);
	}
	
	DFS(0);
	
	for(int i=1 ; i<n ; i++)
		cout << parent[i] << '\n';
	
	return 0;
}
