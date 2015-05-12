#include<cstdio>
#include<stdlib.h>
#include<string.h>
//using namespace std;
#define N 100005
#pragma warning(disable:4996)
int X[N];	//地雷
int A[N];	//记录地雷数目的数组
int S[N];	//标记格子是否确定一定是地雷或一定不是地雷
int ans;
int YES[N];
int NO[N];

int check(int n,int cur)
{
	if (cur == 2 && X[1] + X[2] == A[1])
	{
		if (n == 2 && X[1] + X[2] == A[2])
			return 1;
		if (n != 2)
			return 1;
	}
	if (cur == n && X[n] + X[n - 1] + X[n - 2] == A[n - 1] && X[n] + X[n - 1] == A[n])
		return 1;
	if (cur != n && X[cur] + X[cur - 1] + X[cur - 2] == A[cur - 1])
		return 1;
	return 0;
}

void mine(int n,int cur)
{
	if (n == 1)	
	{
		S[1] = A[1]; return;
	}
	if (cur > n)
	{
		if (!ans)
		{
			ans++;
			memcpy(S + 1, X + 1, n*sizeof(int));
		}
		else
		{
			ans++;
			for (int i = 1; i <= n; i++)
			{
				if (S[i] != X[i])
					S[i] = -1;		//这个位置不确定。。。
			}
		}
		return;
	}
	X[cur] = 0;
	if(cur == 1 || check(n, cur))
		mine(n, cur + 1);
	X[cur] = 1;
	if (cur == 1 || check(n, cur))
		mine(n, cur + 1);
}

void print_ans(int k)
{
	int y=0, n=0;
	for (int i = 1; i <= k; i++)
	{
		if (S[i] == 0)
		{
			n++; NO[n] = i;
		}
		if (S[i] == 1)
		{
			y++; YES[y] = i;
		}
	}
	printf("%d ", y);
	for (int i = 1; i <= y; i++) printf("%d ", YES[i]);
	printf("\n");
	printf("%d ", n);
	for (int i = 1; i <= n; i++) printf("%d ", NO[i]);
	printf("\n");
}

int main()
{
	int t,n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		ans = 0;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &A[j]);
		}
		mine(n,1);
		print_ans(n);
	}
	system("pause");
	return 0;
}