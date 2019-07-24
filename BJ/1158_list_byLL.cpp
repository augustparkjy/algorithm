#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* next;

	Node(int v, Node* n) : value(v), next(n) {}
};

class CLL
{
public:
	int size;
	Node* head;

	CLL() :size(0), head(nullptr) {}
	~CLL()
	{
		Node* temp;  //¡Øtemp = head->next; 
		
		for (int i = 0; i<size; i++)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	void init(int N)
	{
		size = N;
		head = new Node(1, nullptr);
		Node* temp = head;

		for (int i = 1; i<size; i++)
		{
			temp->next = new Node(i + 1, nullptr);
			temp = temp->next;
			if (i == size - 1)
				temp->next = head;
		}
	}

	void operate(int N, int K)
	{

		init(N);

		cout << '<';
		while (size != 0)
		{
			Node* t1 = head;
			Node* t2 = nullptr;
			for (int i = 0; i<K - 1; i++)
			{
				t2 = t1;
				t1 = t1->next;
			}
			head = t1->next;
			if (K>1)
				t2->next = t1->next;
			cout << t1->value;
			delete t1;
			if (size>1)
				cout << ", ";
			size--;
		}
		cout << '>';
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	CLL l;
	int N, K;

	cin >> N >> K;

	l.operate(N, K);

	return 0;
}

