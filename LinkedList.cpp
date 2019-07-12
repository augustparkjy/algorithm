/*# 
##Âü°í : 
## https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220781402507&categoryNo=299&parentCategoryNo=0&viewDate=&currentPage=11&postListTopCurrentPage=1&from=menu&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=11
*/

#include <iostream>
#define DONE	 1
#define ERROR	-1

using namespace std;

template <typename T>
class Node{
public:
	T value;
	Node<T>* next;
	
	Node<T>() : next(nullptr){}
	Node<T>(T value1, Node<T>* next1) : value(value1), next(next1){}
};

template<typename T>
class LinkedList{
public:
	Node<T>* head;
	int size;
	
	LinkedList<T>() : head(nullptr), size(0){}
	~LinkedList<T>(){
		Node<T>* temp;
		while(head!=nullptr)
		{
			temp = head->next;
			delete head;
			head = temp;
			size--;
		}
	}
	
	int insert(int idx, T value){
		if(idx>size || idx<0)
		{
			cout << "invalid index" <<'\n';
			return ERROR;
		} 
		else if(idx == 0)
		{
			head = new Node<T>(value, head);
			size++;
			return DONE;
		}
		else
		{
			int i = 0;
			Node<T>* t1 = head;
			for(i=0 ; i<idx-1 ; i++)
			{
				t1=t1->next;
			}
			t1->next = new Node<T>(value, t1->next);
			size++;
			return DONE;
		}
	}
	
	int search(T target)
	{
		Node<T>* temp = head;
		
		for(int i=0 ; i<size ; i++)
		{
			if(temp->value == target)
				return i;
			temp = temp->next;
		}
		
		return ERROR;
	}
	
	int remove(T target)
	{
		Node<T>* t1 = head;
		Node<T>* t2;
		int i=0;
		
		if(size == 0)
		{
			cout << "size is 0\n";
			return ERROR;
		}
		
		for(i=0 ; i<size ; i++)
		{
			if(t1->value == target)
			{
				if(i==0)
				{
					head = t1->next;
					delete t1;
					size--;
					return i;
				}
				else
				{
					t2 -> next = t1 -> next;
					delete t1;
					size--;
					return i;
				}
			}
			t2 = t1;
			t1 = t1->next;
		}
		
		return ERROR;
	}
};

template<typename T>	
ostream& operator <<(ostream& out, const LinkedList<T>& LL)
{
	Node<T>* temp = LL.head;
	out << '[';
	for(int i=0 ; i<LL.size ; i++)
	{
		out << temp->value;
		temp = temp->next;
		if(i < LL.size-1) 
			out << ", ";
	}
	out << ']';
	return out;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	LinkedList<int> l; cout << l <<"\t size: "<<l.size<<'\n';
	l.insert(0,0); cout << l <<"\t size: "<<l.size<<'\n';
	l.insert(0,1); cout << l <<"\t size: "<<l.size<<'\n';
	l.insert(2,2); cout << l <<"\t size: "<<l.size<<'\n';
	l.insert(1,3); cout << l <<"\t size: "<<l.size<<'\n';
	l.insert(9,9); cout << l <<"\t size: "<<l.size<<'\n';
	
	cout << l.search(3) <<'\n';
	cout << l.search(4) <<'\n';
	
	l.remove(0); cout << l <<'\n';
	l.remove(2); cout << l <<'\n';
	
	return 0;
}
