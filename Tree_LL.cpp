#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d, Node* l, Node* r) :data(d), left(l), right(r) {};
	Node() : data(0), left(nullptr), right(nullptr) {};
};

class Tree
{
public:
	Node * root;
	int num;
	Tree() :root(nullptr), num(0) {};

	Node* search(Node* node, int data)
	{
		if (node == nullptr) return nullptr;
		if (data == node->data) return node;
		else if (data < node->data) search(node->left, data);
		else search(node->right, data);
	}

	void insertNode(int data)
	{
		Node* cur = root;
		Node* parent = nullptr;
		if (root == nullptr)
			root = new Node(data, nullptr, nullptr);
		else
		{
			while (1)
			{
				if (data > cur->data)
				{
					if (cur->right == nullptr)
					{
						cur->right = new Node(data, nullptr, nullptr);
						break;
					}
					cur = cur->right;
				}
				else
				{
					if (cur->left == nullptr)
					{
						cur->left = new Node(data, nullptr, nullptr);
						break;
					}
					cur = cur->left;
				}
			}
		}
		num++;
	}

	Node* getRoot()
	{
		return root;
	}

	void preorder(Node* node)
	{
		if (node == nullptr) return;
		cout << node->data << ' ';
		preorder(node->left);
		preorder(node->right);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Tree T;
	int n = 0, data = 0;

	cin >> n;

	for (int i = 0; i<n; i++)
	{
		cin >> data;
		T.insertNode(data);
	}

	T.preorder(T.getRoot());

	return 0;
}
