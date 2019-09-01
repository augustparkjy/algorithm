#include <iostream>
using namespace std;

char maze[52][52] = { 0 };
int visit[52][52] = { 0 };
class Pos
{
public:
	int x;
	int y;
	char type;
	int step;
	Pos* next;
	Pos() :x(0), y(0), type(0), step(0), next(nullptr) {}
	Pos(int x1, int y1, char t, int s) : x(x1), y(y1), type(t), step(s), next(nullptr) {}
	Pos(int x1, int y1, char t, int s, Pos* n) :x(x1), y(y1), type(t), step(s), next(n) {}
};

class List
{
public:
	int cnt;
	Pos* head;
	Pos* tail;
	Pos* cur;

	List() :cnt(0), head(nullptr), tail(nullptr), cur(nullptr) {}
	~List()
	{
		Pos* temp = head;
		for (int i = 0; i<cnt; i++)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}

	void insert(int x, int y, int s, char t)
	{
		if (head == nullptr)
		{
			head = new Pos(x, y, t, s, nullptr);
			tail = head;
			cur = head;
		}
		else
		{
			tail->next = new Pos(x, y, t, s, nullptr);
			tail = tail->next;
		}
		cnt++;
	}

	int escape(int R, int C)
	{
		int f = 0, r = 0, x = 0, y = 0, s = 0;
		char t;
		Pos q[2500];
		for (int i = 0; i<cnt; i++)
		{
			q[r++] = (*cur);
			cur = cur->next;
		}

		while (f <= r)
		{
			t = q[f].type;
			if (t == 'S')
				s = q[f].step;
			x = q[f].x;
			y = q[f++].y;
			visit[x][y] = 1;
			
			if (t == '*')
			{
				if ((maze[x - 1][y] == '.' || maze[x - 1][y] == 'S') && visit[x - 1][y] == -1)
				{
					visit[x-1][y] = 1;
					maze[x - 1][y] = '*';
					q[r].x = x - 1;
					q[r].type = '*';
					q[r++].y = y;
				}
				if ((maze[x][y + 1] == '.' || maze[x][y + 1] == 'S') && visit[x][y+1] == -1)
				{
					visit[x][y+1] = 1;
					maze[x][y + 1] = '*';
					q[r].x = x;
					q[r].type = '*';
					q[r++].y = y + 1;
				}
				if ((maze[x + 1][y] == '.' || maze[x + 1][y] == 'S') && visit[x + 1][y] == -1)
				{
					visit[x+1][y] = 1;
					maze[x + 1][y] = '*';
					q[r].x = x + 1;
					q[r].type = '*';
					q[r++].y = y;
				}
				if ((maze[x][y - 1] == '.' || maze[x][y - 1] == 'S') && visit[x][y - 1] == -1)
				{
					visit[x][y-1] = 1;
					maze[x][y - 1] = '*';
					q[r].x = x;
					q[r].type = '*';
					q[r++].y = y - 1;
				}
			}
			else
			{
				
				if ((maze[x - 1][y] == '.' || maze[x-1][y] == 'D') && visit[x - 1][y] == -1)
				{

					if (maze[x - 1][y] == 'D') return s + 1;
					maze[x - 1][y] = 'S';
					q[r].x = x - 1;
					q[r].type = 'S';
					q[r].step = s + 1;
					q[r++].y = y;
				}
				if ((maze[x][y + 1] == '.' || maze[x][y + 1] == 'D') && visit[x][y + 1] == -1)
				{
					if (maze[x][y + 1] == 'D') return s + 1;
					maze[x][y + 1] = 'S';
					q[r].x = x;
					q[r].type = 'S';
					q[r].step = s + 1;
					q[r++].y = y + 1;
				}
				if ((maze[x + 1][y] == '.' || maze[x + 1][y] == 'D') && visit[x + 1][y] == -1)
				{
					if (maze[x + 1][y] == 'D') return s + 1;
					maze[x + 1][y] = 'S';
					q[r].x = x + 1;
					q[r].type = 'S';
					q[r].step = s + 1;
					q[r++].y = y;
				}
				if ((maze[x][y - 1] == '.' || maze[x][y - 1] == 'D') && visit[x][y - 1] == -1)
				{
					if (maze[x][y - 1] == 'D') return s + 1;
					maze[x][y - 1] = 'S';
					q[r].x = x;
					q[r].type = 'S';
					q[r].step = s + 1;
					q[r++].y = y - 1;
				}
			}
		}

		return 0;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R = 0, C = 0, x = 0, y = 0, result = 0;;
	List l;

	cin >> R >> C;

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			cin >> maze[i][j];
			visit[i][j] = -1;
			if (maze[i][j] == '*')
				l.insert(i, j, 0, '*');
			else if (maze[i][j] == 'S')
			{
				x = i;
				y = j;
			}
		}
	l.insert(x, y, 0, 'S');

	if (result = l.escape(R, C))
	{
		cout << result;
		return 0;
	}
	cout << "KAKTUS";
	return 0;
}
