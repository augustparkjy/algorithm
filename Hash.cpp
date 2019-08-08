#include<iostream>
#define MAX 50

using namespace std;

typedef int HashFunc(int key);
class Node
{
public:
	int id;
	string data;

	Node():id(0), data(nullptr){}
	Node(int i, string s):id(i), data(s){}
};
class Hash
{
public:
	int cnt;
	HashFunc* hf1;
	HashFunc* hf2;
	Node* table[MAX]={nullptr};
	
	Hash():cnt(0), hf1(nullptr), hf2(nullptr){}	
	void setHF1(HashFunc* f)
	{
		hf1=f;
	}
	
	void setHF2(HashFunc* f)
	{
		hf2=f;
	}
	
	void insert(Node* n)
	{
		int v=hf1(n->id)%50;
		if(table[v]==nullptr)
			table[v]=n;
		else
		{
			int v2=hf2(v);
			if(table[v2]==nullptr)
				table[v2]=n;
			else
			{
				cout<<"collision\n";
				return;
			}
		}
		cnt++;
		return;
	}
	int search(int id)
	{
		int v1=id%50;
		int v2=v1;
		if(table[v2]!=nullptr)
			return v2;
		else if(table[v1]!=nullptr)
			return v1;
		else
		{
			cout << "no data\n";
			return -1;
		}
	}
	void remove(int v)
	{
		table[v] = nullptr;
		cnt--;
	}

	Node* getData(int v)
	{
		Node* n = table[v];
		cout << "id: "<<n->id << '\n';
		cout << "data: " << n->data << '\n';
		return n;
	}
};

int HF1(int k)
{
	return k%111;
}

int HF2(int k)
{
	return (k+23)%50;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, key=0, idx=0;
	string data;
	Hash h;
	h.setHF1(HF1);
	h.setHF2(HF2);
	
	cin >> n;
	
	for(int i=0 ; i<n ; i++)
	{
		cin >> key >> data;
		Node* n = new Node(key, data);
		h.insert(n);
		cout << h.cnt << '\n';
	}
	cout << flush;
	cout << "search\n";
	cin >> key;
	idx=h.search(key);
	h.getData(idx);
	h.remove(idx);
	cout << h.cnt << '\n';
	
	return 0;
}
