#include <iostream>
#define DFT 50
using namespace std;
int G[DFT+1][DFT+1] = {{0}}; //node identifier >= 1 
int BFSvisit[DFT+1] = {0};
int BFSparent[DFT+1] = {0};
int BFSchildren[DFT+1][2] ={{0}};
int DFSvisit[DFT+1] = {0};
int DFSparent[DFT+1] = {0};
int DFSchildren[DFT+1][2] ={{0}}; 

void makeTreeByDFS(int v, int n, int p)
{
	int i;
	
	DFSparent[v] = p;
	DFSvisit[v] = 1;
	for(int i=1 ; i<=n ; i++)
		if(G[v][i] && DFSvisit[i]==0)
		{
			if(DFSchildren[v][0]==0)
				DFSchildren[v][0]=i;
			else
				DFSchildren[v][1]=i;
			makeTreeByDFS(i, n, v);
		}
	return;
}

void makeTreeByBFS(int root, int n)
{
	int front = 0, rear = 0, pop=0, queue[1001] = {0};
	
	BFSvisit[root] = 1;
	queue[rear++]=root;
	
	while(front < rear)
	{
		pop = queue[front++];
		//pop할 때마다 출력한다면 탐색마친 후에도 연산 진행되는 것을 기다려야함. 
		for(int i=1 ; i<=n ; i++)
		{
			if(G[pop][i] && !BFSvisit[i])
			{
				BFSvisit[i]=1;
				queue[rear++]=i;
				BFSparent[i] = pop;
				BFSchildren[pop][0] ==0 ? BFSchildren[pop][0]=i : BFSchildren[pop][1]=i;
				if(rear == n) //모든 노드의 탐색 마침을 의미(하나의 컴포넌트인 그래프  가정) 
					return;
			}	
		}
	}
	return;
}

void DFSprint(int n)
{
	for(int i=1 ; i<= n ; i++)
	{
		cout << "NODE " << i<< ":";
		if(DFSparent[i]==0)
			cout << "parent(-), ";
		else
			cout << "parent("<<DFSparent[i]<<"), ";
		
		cout << "children(";
		if(DFSchildren[i][0]!=0)
		{
			cout<< DFSchildren[i][0];
			if(DFSchildren[i][1]!=0)
				cout << ", " << DFSchildren[i][1];
		}
		cout<< ")\n";
	}
}

void BFSprint(int n)
{
	for(int i=1 ; i<= n ; i++)
	{
		cout << "NODE " << i<< ":";
		if(BFSparent[i]==0)
			cout << "parent(-), ";
		else
			cout << "parent("<<BFSparent[i]<<"), ";
		
		cout << "children(";
		if(BFSchildren[i][0]!=0)
		{
			cout<< BFSchildren[i][0];
			if(BFSchildren[i][1]!=0)
				cout << ", " << BFSchildren[i][1];
		}
		cout<< ")\n";
	}
}

void BFSpreorder(int v)
{
	cout << v << ' ';
	if(BFSchildren[v][0]!=0)
		BFSpreorder(BFSchildren[v][0]);
	if(BFSchildren[v][1]!=0)
		BFSpreorder(BFSchildren[v][1]);
	return;
}
void BFSinorder(int v)
{
	if(BFSchildren[v][0]!=0)
		BFSinorder(BFSchildren[v][0]);
	cout << v << ' ';
	if(BFSchildren[v][1]!=0)
		BFSinorder(BFSchildren[v][1]);
	return;
}

void BFSpostorder(int v)
{
	if(BFSchildren[v][0]!=0)
		BFSpostorder(BFSchildren[v][0]);
	if(BFSchildren[v][1]!=0)
		BFSpostorder(BFSchildren[v][1]);
	cout << v << ' ';
	return;
}

void BFSlevelorder(int v, int n)
{
	int f=0, r=0, p=0, q[DFT+1]={0};
		cout << v << ' ';
		q[r++]=v;
		
		while(r<n)
		{
			p=q[f++];
			for(int i=0 ; i<2 ; i++)
			{
				if(BFSchildren[p][i]!=0)
				{
					cout << BFSchildren[p][i] << ' ';
					q[r++]=BFSchildren[p][i];
				}
			}
		}
}

void DFSpreorder(int v)
{
	cout << v << ' ';
	if(DFSchildren[v][0]!=0)
		DFSpreorder(DFSchildren[v][0]);
	if(DFSchildren[v][1]!=0)
		DFSpreorder(DFSchildren[v][1]);
	return;
}

void DFSinorder(int v)
{
	if(DFSchildren[v][0]!=0)
		DFSinorder(DFSchildren[v][0]);
	cout << v << ' ';
	if(DFSchildren[v][1]!=0)
		DFSinorder(DFSchildren[v][1]);
	return;
}

void DFSpostorder(int v)
{
	if(DFSchildren[v][0]!=0)
		DFSpostorder(DFSchildren[v][0]);
	if(DFSchildren[v][1]!=0)
		DFSpostorder(DFSchildren[v][1]);
	cout << v << ' ';
	return;
}

void DFSlevelorder(int v, int n)
{
	int f=0, r=0, p=0, q[DFT+1]={0};
	cout << v << ' ';
	q[r++]=v;
	
	while(r<n)
	{
		p=q[f++];
		for(int i=0 ; i<2 ; i++)
		{
			if(DFSchildren[p][i]!=0)
			{
				cout << DFSchildren[p][i] << ' ';
				q[r++]=DFSchildren[p][i];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0, e=0, x=0, y=0;
	
	cin >> n >> e;
	
	for(int i=0 ; i<e ; i++)
	{
		cin >> x >> y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	
	cout << "MAKE TREE BY BFS\n";
	makeTreeByBFS(1, n);
	BFSprint(n);
	cout << '\n';
	cout << "MAKE TREE BY DFS\n";
	makeTreeByDFS(1, n, 0);
	DFSprint(n);
	
	cout << "BFS TRAVERSAL\n";
	cout << "preorder\n";
	BFSpreorder(1); cout << '\n';
	cout << "inorder\n";
	BFSinorder(1); cout << '\n';
	cout << "postorder\n";
	BFSpostorder(1); cout << '\n';
	cout << "levelorder\n";
	BFSlevelorder(1, n); cout << '\n';
	
	cout << "DFS TRAVERSAL\n";
	cout << "preorder\n";
	DFSpreorder(1); cout << '\n';
	cout << "inorder\n";
	DFSinorder(1); cout << '\n';
	cout << "postorder\n";
	DFSpostorder(1); cout << '\n';
	cout << "levelorder\n";
	DFSlevelorder(1, n); cout << '\n';
	return 0;
}



/*
test input
9 10
1 2
1 3
2 4
2 6
4 5
5 6
3 7
3 9
7 9
7 8
*/
