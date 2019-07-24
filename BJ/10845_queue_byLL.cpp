#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int val;
	Node* next;
	
	Node(int v, Node* n) : val(v), next(n) {}
};

class Queue
{
public:
	int size;
	Node* head;
	Node* tail;
	
	Queue() :size(0), head(nullptr), tail(nullptr) {}
	~Queue()
	{
		Node* temp = head;
		for(int i=0 ; i<size ; i++)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
	
	void push(int v)
	{
		if(size==0)
		{
			head = new Node(v, nullptr);
			tail = head;
		}
		else
		{
			tail->next = new Node(v, nullptr);
			tail = tail->next;
		}
		size++;
	}
		
	int pop()
	{
		if(size==0)
			return -1;
		else
		{
			int x;
			Node* temp = head;
			head = temp->next;
			x = temp->val;
			delete temp;
			size--;
			return x;
		}
	}
	
	int len()
	{
		return size;
	}
	
	int empty()
	{
		if(size==0) return 1;
		else return 0;
	}
	
	int front()
	{
		if(size == 0) return -1;
		else return head->val;
	}
	
	int back()
	{
		if(size==0) return -1;
		else return tail->val;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, v;
	string cmd;
	Queue q;
	
	cin >> N;
	
	for(int i=0 ; i<N ; i++)
	{
		cin >> cmd;
		if(cmd == "push")
		{
			cin >> v;
			q.push(v);
		}
		else if(cmd =="front") cout << q.front() <<'\n';
		else if(cmd=="back") cout << q.back() <<'\n';
		else if(cmd=="size") cout << q.len() <<'\n';
		else if(cmd=="empty") cout << q.empty()<<'\n';
		else cout << q.pop() <<'\n';
	}
	return 0;
}
