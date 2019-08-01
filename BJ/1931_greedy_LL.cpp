//최악의 경우를 고려한 빠른 정렬 구현 필요 

class Node
{public:
	int start;
	int end;
	Node* next;
	
	Node():start(0), end(0), next(nullptr){}
	Node(int s1, int e1, Node* n1):start(s1), end(e1), next(n1){}
};
class List
{public:
	Node* head;
	int size;
	
	List():head(nullptr), size(0){}
	~List()
	{
		Node* temp = head;
		for(int i=0 ; i<size ; i++)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}

	void init()
	{
		int n=0;
		int s=0, e=0;
		
		cin >> n >> s >> e;
		n=size;
		head = new Node(s, e, nullptr);
		
		for(int i=0 ; i<size ; i++)
		{
			head = new Node(s, e, head);
		}
		
	
	}
	
	void computing()
	{
		int cnt=1;
		int e=head->end;
		int temp;
		Node* temp = head;
		Node* del;
		
		while(size!=0)
		{
			for(int i=0 ; i<size ; i++)
			{
				if(temp->end < e)
				{
					
				}
			}
		}
		for(int i=1 ; i<size ; i++)
		{
			temp=temp->next;
			if(temp->start <e) continue;
			else
			{
				e=temp->end;
				cnt++;
			}
		}
		
		cout << cnt ;	
	}
	void init()
	{
		int n=0;
		int s=0, e=0;
		
		cin >> n >> s >> e;
		
		head = new Node(s, e, nullptr);
		Node* dummy = new Node(-1, -1, head);
		Node* cur = dummy;
		size++;
		
		for(int i=1 ; i<n ; i++)
		{
			cin >> s >> e;
			cur = dummy;
			for(int j=0 ; j<size ; j++)
			{
				if(cur->next->end >= e)
				{
					cur->next = new Node(s, e, cur->next);
					break;
				}
				cur=cur->next;
				if(j==size-1)
					cur->next = new Node(s,e,nullptr);
			}
			size++;
		}
		head = dummy->next;
		delete dummy;
	}
	
	void computing()
	{
		int cnt=1;
		int e=head->end;
		Node* temp = head;
		
		for(int i=1 ; i<size ; i++)
		{
			temp=temp->next;
			if(temp->start <e) continue;
			else
			{
				e=temp->end;
				cnt++;
			}
		}
		
		cout << cnt ;	
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	List l;
	l.init();
	l.computing();
	
	return 0;
}
