#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	char val;
	Node* next;

	Node(char v, Node* n) : val(v), next(n) {}
};

class Stack
{
public:
	int size;
	Node* head;

	Stack() :size(0), head(nullptr) {};
	~Stack()
	{
		Node* temp = head;

		for (int i = 0; i<size; i++)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}

	int push(char v)
	{
		if (size == 0)
			head = new Node(v, nullptr);
		else
			head = new Node(v, head);
		size++;
		return size;
	}
	char top()
	{
		if (size == 0)
			return -1;
		else
			return head->val;
	}
	char pop()
	{
		if (size == 0)
			return -1;
		else
		{
			char tval = head->val;
			Node* tnode = head;
			head = head->next;
			delete tnode;
			size--;
			return tval;
		}
	}
	int len()
	{
		return size;
	}
};
int getPriority(char a)
{
	if (a == '*' || a == '/')
		return 1;
	if (a == '+' || a == '-')
		return 2;
	else
		return 3;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string in;
	string out;
	Stack s;
	char x, y;
	cin >> in;

	for (int i = 0; i<in.size(); i++)
	{
		y = in[i];
		if (y == '(')
		{
			s.push(y);
			continue;
		}
		else if (y == ')')
			while (1)
			{
				x = s.pop();
				if (x == '(')
					break;
				out += x;
			}
		else if (y >= 65 && y <= 90)
			out += y;
		else
		{
			x = s.top();
			if (getPriority(x)>getPriority(y))
				s.push(y);
			else
			{
				while (1)
				{
					x = s.top();
					if (getPriority(x)>getPriority(y))
						break;
					x = s.pop();
					out += x;
				}
				s.push(y);
			}
		}
		if (i == in.size() - 1)
			while (s.len() != 0)
			{
				out += s.pop();
			}
	}

	cout << out;
	return 0;
}
