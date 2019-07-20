#include <iostream>
using namespace std;

class Node
{
public:
	int idx;
	int val;
	Node* next;
	Node* prev;

	Node(int i, int v, Node* n, Node* p) :idx(i), val(v), next(n), prev(p) {}
};

class CDLL
{
public:
	Node * head;
	int size;

	CDLL() :head(nullptr), size(0) {}
	~CDLL()
	{
		Node* temp;
		for (int i = 0; i<size; i++)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	void init()
	{
		int v;
		cin >> size;
		cin >> v;

		head = new Node(1, v, nullptr, nullptr);
		head->next = head;
		head->prev = head;

		Node* temp = head;

		for (int i = 2; i <= size; i++)
		{
			cin >> v;
			temp->next = new Node(i, v, head, temp);
			head->prev = temp->next;
			temp = temp->next;
		}
	}

	void operate()
	{
		init();

		Node* temp;
		Node* t2 = head;
		for (; size>0; )
		{
			temp = t2;
			cout << temp->idx << ' ';

			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			if (temp->val > 0)
			{
				t2 = temp->next;
				for (int i = 1; i<temp->val; i++)
					t2 = t2->next;
			}

			else
			{
				t2 = temp->prev;
				for (int i = 1; i< -1 * (temp->val); i++)
					t2 = t2->prev;
			}
			delete temp;
			size--;
		}
	}

};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	CDLL l;

	l.operate();

	return 0;
}
