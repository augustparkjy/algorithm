/*
## reference : 
## https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220785731077&categoryNo=299&parentCategoryNo=0&viewDate=&currentPage=11&postListTopCurrentPage=1&from=menu&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=11
*/
#include <iostream>
#define DEFAULT	10
using namespace std;

template <typename T>
class Node
{
public:
	T val;
	Node<T>* next;
	Node<T>* prev;
	Node<T>(int v, Node<T>* n, Node<T>* p) : val(v), next(n), prev(p) {}
};

template <typename T>
class LL
{
public:
	int size;
	Node<T>* head;
	Node<T>* tail;
	Node<T>* cur;

	LL() :size(0), head(nullptr), tail(nullptr), cur(nullptr) {}
	~LL()
	{
		Node<T>* temp = head;
		for (int i = 0; i<size; i++)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}

	void push_back(int v)
	{
		if (size == 0)
		{
			head = new Node<T>(v, nullptr, nullptr);
			head->next = head;
			head->prev = head;
			tail = head;
			cur = head;
		}

		else
		{
			tail->next = new Node<T>(v, head, tail);
			tail = tail->next;
			head->prev = tail;
		}
		size++;
	}

	void sort() //bubble sort
	{
		Node<T>* temp = head;
		Node<T>* temp2;
		Node<T>* temp3;

		if (head == nullptr)
			return;

		for (int i = 0; i<size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				temp = tail->next;
				if (temp->val > temp->next->val)
				{
					temp2 = temp->prev;
					temp3 = temp->next->next;
					temp->next->next = temp;
					temp->next->prev = temp2;
					temp2->next = temp->next;
					temp->prev = temp2->next;
					temp->next = temp3;
					temp3->prev = temp;
				}
				else
					temp = temp->next;
				if (i == 0)
					tail = temp;
			}
		}
		head = tail->next;
		cur = head;
	}

	void fill(int start, int end, T v)
	{
		Node<T>* temp = head;
		for (int i = 0; i<size; i++)
		{
			temp->val = v;
			temp = temp->next;
		}
	}

	T next()
	{
		T x = cur->val;
		cur = cur->next;
		return x;
	}

	void setVisited(int idx, bool x)
	{
		Node<T>* temp = head;
		for (int i = 0; i<idx; i++)
			temp = temp->next;
		temp->val = x;
	}

	bool getVisited(int idx)
	{
		Node<T>* temp = head;
		for (int i = 0; i<idx; i++)
			temp = temp->next;
		return temp->val;
	}
};

template<typename T>
ostream& operator <<(ostream& out, LL<T>& l)
{
	out << '[';
	Node<T>* temp = l.head;
	for (int i = 0; i<l.size; i++)
	{
		out << temp->val;
		if (i<l.size - 1)
			out << ", ";
		temp = temp->next;
	}
	out << ']';
	return out;
};

class Graph
{
public:
	int n;
	LL<int>* adj[DEFAULT];
	LL<bool> visited;

	Graph() : n(0) {}
	Graph(int N) : n(N) {
		for (int i = 0; i < n; i++)
			adj[i] = new LL<int>();
	}

	void addEdge(int u, int v)
	{
		adj[u]->push_back(v);
		adj[v]->push_back(u);
	}

	void sortList()
	{
		for (int i = 0; i<n; i++)
			adj[i]->sort();
	}

	//	void dfs()
	//	{
	//		for (int i=0 ; i<n ; i++)
	//			visited.push_back(false);
	//		dfs(0);
	//	}

	int dfsAll()
	{
		int components = 0;
		int nodes;
		for (int i = 0; i<n; i++)
			visited.push_back(false);
		for (int i = 0; i<n; i++)
		{
			if (!visited.getVisited(i))
			{
				cout << "-- new DFS --\n";
				nodes = dfs(i);
				components++;
				cout << "size: " << nodes << "\n\n";
			}
		}
		return components;
	}
	void check()
	{
		for (int i = 0; i<n; i++)
		{
			cout << "node " << i << " :";
			for (int j = 0; j<adj[i]->size; j++)
			{
				cout << adj[i]->next() << ' ';
			}
			cout << '\n';
		}
	}
private:
	int dfs(int curr)
	{
		int nv;
		int nodes = 1;
		visited.setVisited(curr, true);
		cout << "node " << curr << " visited" << '\n';

		for (int j = 0; j<adj[curr]->size; j++)
		{
			nv = adj[curr]->next();
			if (!visited.getVisited(nv))
				nodes += dfs(nv);
		}
		return nodes;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int components;

	Graph G(10);
	G.addEdge(0, 1);
	G.addEdge(1, 3);
	G.addEdge(2, 3);
	G.addEdge(4, 6);
	G.addEdge(5, 7);
	G.addEdge(5, 8);
	G.addEdge(7, 8);
	G.sortList();
	components = G.dfsAll();

	cout << "The number of component is " << components << '\n';

	return 0;
}
