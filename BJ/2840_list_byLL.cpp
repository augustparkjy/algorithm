#include <iostream>
using namespace std;

class Node
{
public:
	char data;
	Node* next;
	Node* prev;
	Node(char d, Node* n, Node* p):data(d), next(n), prev(p){}
};

class List
{
public:
	int size;
	Node* head;
	List():size(0), head(nullptr){}
	~List()
	{
		Node* temp = head;
		for(int i=0 ; i<size ; i++)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
	
	int init()
	{
		int n=0, k=0;
			
		cin >> n >> k;
		
		size = n;
		head = new Node(0, nullptr, nullptr);
		head->next = head;
		head->prev = head;
		
		for(int i=1 ; i<size ; i++)
		{
			head = new Node(0, head, head->prev);
			head->prev->next = head;
			head->next->prev = head;
		}
		
		return k;
	}
	
	void wheel(int k)
	{
		int step=0;
		char alpha=0;
		char check[26]={0};
		
		Node* temp=head;
		for(int i=0 ; i<k ; i++)
		{
			cin >> step >> alpha;
			
			for(int j=0 ; j<step ; j++)
				temp = temp->next;
			if((temp->data!=0 && temp->data!=alpha) || temp->data==0 && check[alpha-65]==1)
			{
				cout << '!';
				return;
			}
			if(temp->data==0)
			{
				temp->data = alpha;
				check[alpha-65]=1;
			}
		}
		
		for(int i=0 ; i<size ; i++)
		{
			if(temp->data==0)
				cout << '?';
			else
				cout << temp->data;
			temp=temp->prev;
		}
		return;
	}	
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	List l;
	
	l.wheel(l.init());
	
	return 0;
}
