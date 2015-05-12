#include<iostream>
#include<string.h>
#include<set>
using namespace std;

#define M 1000005
typedef int state[9];
int st[M][9];
int goal[9];
int dist[M];
//set<int> vis;
const int MAX = 1000003;
int head[MAX], nxt[M];

const int dxy[4][2] = { 0, -1,
						-1, 0,						 
						0, 1, 
						1, 0 };

int try_to_insert(int rear)
{
	int value = 0;
	state& s = st[rear];
	for (int i = 0; i < 9; i++)
		value = value * 10 + s[i];
	/*if (vis.find(value) != vis.end())	return 0;
	vis.insert(value);
	return 1;*/
	int h = value % MAX;
	int u = head[h];
	while (u)
	{
		if (memcmp(st[u], s, sizeof(s)) == 0) return 0;
		u = nxt[u];
	}
	nxt[rear] = head[h];
	head[h] = rear;
	return 1;
}

int bfs()
{
	int front = 1, rear = 2;
	while (front < rear)
	{
		state& s = st[front];
		if (memcmp(s, goal, sizeof(s)) == 0)	return front;
		int z;
		for (z = 0; z < 9; z++) if (!s[z])	break;
		for (int d = 0; d < 4; d++)
		{
			int newx = dxy[d][0] + z / 3;
			int newy = dxy[d][1] + z % 3;
			int newz = newx * 3 + newy;
			if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
			{
				state& t = st[rear];
				memcpy(t, s, sizeof(s));
				t[newz] = s[z];
				t[z] = s[newz];
				if (memcmp(t, goal, sizeof(s)) == 0)	{ dist[rear] = dist[front] + 1; return rear; }
				if (try_to_insert(rear))
				{
					dist[rear] = dist[front] + 1;
					rear++;
				}
			}
		}
		front++;
	}
	return 0;
}

int main()
{
	//while (1)
	//{
		for (int i = 0; i < 9; i++)	cin >> st[1][i];
		for (int i = 0; i < 9; i++) cin >> goal[i];
		int ans = bfs();
		if (ans)	cout << dist[ans] << endl;
		else
		{
			cout << -1 << endl;
		}
		system("pause");
	//}
	return 0;
}