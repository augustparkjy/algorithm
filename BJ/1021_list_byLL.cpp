#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* prev;
	
	Node():next(nullptr), prev(nullptr){};
	Node(int v1, Node* n, Node* p): value(v1), next(n), prev(p){};	
};

class MyQ
{
public:
	int size;
	Node* head;
	
	MyQ():size(0), head(nullptr){};
	~MyQ()
	{	
		Node* temp = head->next;
		for(int i=0 ; i<size ; i++)
		{
			delete head;
			head = temp;
			temp = temp->next;
		}
	}
	
	void init(int n)
	{
        head = new Node(1, nullptr, nullptr);
        head->next = head;
        head->prev = head;
        for(int i=1 ; i<n ; i++)
        {
            head->prev->next = new Node(i+1, head, head->prev);
			head->prev = head->prev->next;
        }
		
		size=n;
	}
	int search(int target)
	{
		Node* temp = head;
		int l=0;
		for(int i=0 ; i<size ; i++)
		{
			if(temp->value == target)
				return l;
			temp = temp->next;
			l++;
		}
	}
	int moving(int n, int m, int* target)
	{
		int x=0;
		int y=0;
        
        init(n);
        
        for(int i=0 ; i< m ; i++)
        {
   			Node* temp=head;

        	y = search(target[i]);
			if(y >= (size+1)/2)
			{
				y=size-y;
				for(int i=0 ; i<y ; i++)
					temp = temp->prev;
			}
			else
				for(int i=0 ; i<y ; i++)
					temp = temp->next;
			
			head = temp->next;
			temp->prev->next = head;
			head->prev = temp->prev;
			delete temp;
			size--;
			x+=y;
		}
		
		return x;
	}
};

ostream& operator <<(ostream& out, MyQ& q)
{
	Node* temp = q.head;
	out << '[';
	for(int i=0 ; i<q.size ; i++)
	{
		out << temp->value;
		if(i < q.size-1)
			out << ", ";
		temp = temp->next;
	}
	out << ']';
	return out;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	MyQ q;
	int target[50];
	
	cin >> N >> M;
	
	for(int i=0 ; i<M ; i++)
		cin >> target[i];
	
	cout << q.moving(N, M, target);
		
	return 0;
}
