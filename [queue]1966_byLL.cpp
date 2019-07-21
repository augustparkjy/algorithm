#include <iostream>
using namespace std;

class Node
{
public:
	int pr;
	bool pick;
	Node* next;

	Node(int p1, bool p2, Node* n) :pr(p1), pick(p2), next(n) {}
};

class Q
{
public:
	int size;
	Node* head;
	Node* tail;
	Q() :size(0), head(nullptr), tail(nullptr) {}
	~Q()
	{
		Node* temp = head;
		for (int i = 0; i<size; i++)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}

	void init()
	{
		int n, pos;
		int pr;
		cin >> n >> pos >> pr;
		size = n;

		if (pos != 0)
			head = new Node(pr, false, nullptr);
		else
			head = new Node(pr, true, nullptr);
		Node* temp = head;
		for (int i = 1; i<size; i++)
		{
			cin >> pr;
			if (pos != i)
				temp->next = new Node(pr, false, nullptr);
			else
				temp->next = new Node(pr, true, nullptr);
			temp = temp->next;
		}
		tail = temp;
	}

	void operate()
	{
		int x;
		int cnt = 0;
		Node* t1;
		Node* t2;
		Node* t3;
		while (1)
		{
			t1 = head;
			x = t1->pr;
			for (int i = 0; i<size - 1; i++)
			{
				if (x < t1->next->pr)
				{
					t2 = t1->next;
					tail->next = head;
					tail = t1;
					tail->next = nullptr;
					head = t2;
					t1 = head;
					x= t1->pr;
				}
				else
					t1 = t1->next;
			}
			t3 = head->next;
			if (!head->pick)
			{
				delete head;
				head = t3;
				size--;
				cnt++;
			}
			else
			{
				cout << ++cnt<<'\n';
				return;
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i<T; i++)
	{
		Q* q = new Q();
		q->init();
		q->operate();
		delete q;
	}
	
	return 0;
}
