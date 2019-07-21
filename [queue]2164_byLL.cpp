#include <iostream>
using namespace std;

class Node
{
public:
	int val;
	Node* next;
	Node(int v, Node* n) :val(v), next(n) {}
};
class CQ
{
public:
	int size;
	Node* head;
	Node* tail;

	CQ() :size(0), head(nullptr), tail(nullptr) {}
	~CQ()
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
		int N;
		cin >> N;
		size = N;
		head = new Node(1, nullptr);
		head->next = head;
		Node* temp = head;
		for (int i = 1; i < N; i++)
		{
			temp->next = new Node(i + 1, temp->next);
			temp = temp->next;
		}
		tail = temp;
	}

	int operate()
	{
		init();

		for (; size>1;)
		{
			Node* t1 = head->next;
			tail->next = t1;
			delete head;
			head = t1->next;
			tail = t1;
			size--;
		}
		return head->val;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	CQ q;

	cout << q.operate();

	return 0;
}
