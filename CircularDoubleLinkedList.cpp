#include <iostream>
#define	ERR	-1
#define DONE	1
using namespace std;

template <typename T>
class Node {
public:
	T value;
	Node<T>* next;
	Node<T>* prev;

	Node<T>(): next(nullptr), prev(nullptr) {}
	Node<T>(T v, Node<T>* n, Node<T>* p): value(v), next(n), prev(p){}
};

template<typename T>
class CDLL {
public:
	Node<T>* head;
	int size;
	
	CDLL<T>(): head(nullptr), size(0) {}
	~CDLL<T>()
	{
		Node<T>* temp;

		for (int i=0 ; i<size ; i++)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	
	int insert(int idx, T value)
	{
		if(idx>size)
		{
			cout << "invalid index\n";
			return ERR;
		}
		
		if(size==0)
		{
			head = new Node<T>(value, nullptr, nullptr);
			head->next = head;
			head->prev = head;
		}
		else
		{
			Node<T>* temp = head;
			if(idx > (size/2)) for(int i=0 ; i<idx ; i++) temp = temp->prev;
			else for(int i=0 ; i<idx ; i++)	temp = temp->next;
			
			temp->prev->next = new Node<T>(value, temp, temp->prev);
			temp->prev = temp->prev->next;
			if(idx==0)
				head = temp->prev;
		}
		size++;
		return DONE;
	}
	
	int search(int target)
	{
		Node<T>* temp=head;
		
		for(int i=0 ; i<size ; i++)
		{
			if(temp->value == target)
				return i;
			
			temp = temp->next;
		}
		
		cout << "NO DATA\n";
		return ERR;
	}
	
	int remove(int idx)
	{
		if(idx > size)
		{
			cout << "invalid index\n";
			return ERR;
		}
		else if(size == 0)
		{
			cout << "NO DATA\n";
			return ERR;
		}
		else
		{
			Node<T>* temp = head;
			if(idx > (size/2)) for(int i=0 ; i<idx ; i++) temp = temp->prev;
			else for(int i=0 ; i<idx ; i++) temp = temp->next;
			
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			if(idx==0 && size!=1)
			{
				head = temp->next;		
			}
			delete temp;
		}
		size--;
		return DONE;
	}
	
};

template<typename T>
ostream& operator <<(ostream& out, const CDLL<T>& cdll)
{
	Node<T>* temp = cdll.head;
	out << '[';
	for(int i=0 ; i<cdll.size ; i++)
	{
		out << temp->value;
		if(i<cdll.size-1) out << ", ";
		temp = temp->next;
	}
	out << ']';
	return out;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	CDLL<int> l; cout << l << '\n';

	cout << l.search(1) << ": search error\n";
	cout << l.remove(0) << ": remove error\n";
	
	cout << "---------------insert test\n";
	l.insert(0, 1); cout << l << "\t size: " << l.size <<'\n';	
	l.insert(0, 2); cout << l << "\t size: " << l.size <<'\n';
	l.insert(1, 3); cout << l << "\t size: " << l.size <<'\n';
	l.insert(3, 4); cout << l << "\t size: " << l.size <<'\n';
	l.insert(100,100); cout << l << "\t size: " << l.size <<'\n';
	l.insert(2, 1); cout << l << "\t size: " << l.size <<'\n';
	
	cout << "---------------search test\n";
	cout << l.search(3) << ": search done\n";
	cout << l.search(5) << ": search error\n";	
	
	cout << "---------------remove test\n";
	l.remove(1); cout << l << "\t size: " << l.size <<'\n';
	l.remove(1); cout << l << "\t size: " << l.size <<'\n';
	l.remove(1); cout << l << "\t size: " << l.size <<'\n';
	l.remove(0); cout << l << "\t size: " << l.size <<'\n';
	l.remove(0); cout << l << "\t size: " << l.size <<'\n';
	l.remove(0); cout << l << "\t size: " << l.size <<'\n';
	return 0;
}






