#include<cstdio>
#include<stdlib.h>
#include<math.h>
//using namespace std;
#define N 205
#pragma warning(disable:4996)

int A[N][N];
int S[N][N];
int y_num, n_num;

//1.如果某一个被探明的格子里所标的数字为0，那么它相邻的8个格子里的未探明格子被认作是一定不是地雷的格子。
void rule1(int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (!A[i][j])
			{
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++)
					{
						if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)	S[a][b] = 0;
					}
			}
		}
}
/*
	*2.如果某一个被探明的格子里所标的数字为K，且它相邻的8个格子里正好有K个没有探明的格子的话，则这K个没有
	*探明的格子被认作是一定是地雷的格子。
*/
void rule2(int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] <= 0) continue;
			int count = 0;
			for (int a = i - 1; a <= i + 1; a++)
				for (int b = j - 1; b <= j + 1; b++)
				{
					if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)	count++;
				}
			if (count == A[i][j])
			{
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++)
					{
						if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)	S[a][b] = 1;// printf("test%d %d\n",a,b);
					}
			}
		}
}
//3.如果某两个探明了的格子A和B，他们中标明的数字分别为P_A和P_B，且他们周围8个格子中没有探明的格子组成的集合分别为S_A和S_B，如果S_A包含S_B，且|S_A|-|S_B|=P_A-P_B，那么S_A-S_B中的所有格子，被认作是一定是地雷的格子。
void rule3(int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] <= 0) continue;
			int count = 0;
			for (int a = i - 1; a <= i + 1; a++)
				for (int b = j - 1; b <= j + 1; b++)
				{
					if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)	count++;
				}
			for (int a = i - 1; a <= i + 1; a++)
				for (int b = j - 1; b <= j + 1; b++)
				{
					if (a == i && b == j)
						continue;
					int count2 = 0;
					if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] != -1)
					{
						int flag = 1;//判断(i,j)是否包含(a,b)的未知格子。
						for (int x = a - 1; x <= a + 1; x++)
						{
							for (int y = b - 1; y <= b + 1; y++)
							{
								if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1 && A[x][y] == -1)
								{
									count2++;
									if (abs(x - i) > 1 || abs(y - j) > 1)
									{
										flag = 0; break;
									}
								}
							}
							if (!flag) break;
						}
						if (flag && (A[i][j] - A[a][b] == count - count2))//(i,j)的未知格子包含(a,b)的未知格子数
						{
							//(i,j)-(a,b)的未知格子一定是雷！
							for (int a1 = i - 1; a1 <= i + 1; a1++)
								for (int b1 = j - 1; b1 <= j + 1; b1++)
								{
									if (a1 >= 0 && a1 <= n - 1 && b1 >= 0 && b1 <= m - 1 && A[a1][b1] == -1)
										if (abs(a1 - a) > 1 || abs(b1 - b) > 1)
										{
											S[a1][b1] = 1;
											//printf("test%d %d %d %d\n", i, j, a, b);
										}
								}
						}
					}
				}
		}
}

void mine(int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] == -1)
				continue;
			//应用规则一
			if (A[i][j] == 0)
			{
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++)
					{
						if (a == i && b == j)
							continue;
						if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)
							S[a][b] = 0;
					}
				continue;
			}
			int count = 0;
			for (int a = i - 1; a <= i + 1; a++)
				for (int b = j - 1; b <= j + 1; b++)
				{
					if (a == i && b == j)
						continue;
					if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1&&A[a][b] == -1)
					{
							count++;
					}
				}
			//应用规则二
			if (count == A[i][j])
			{
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++)
					{
						if (a == i && b == j)
							continue;
						if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)
						{
							S[a][b] = 1;// printf("test%d %d\n",a,b);
						}
					}
				continue;
			}
			//应用规则三
			for (int a = i - 1; a <= i + 1; a++)
				for (int b = j - 1; b <= j + 1; b++)
				{
					if (a == i && b == j)
						continue;
					int count2 = 0;
					if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] >= 0)
					{
						int flag = 1;

						for (int x = a - 1; x <= a + 1; x++)
						{ 
							for (int y = b - 1; y <= b + 1; y++)
							{
								if (x == a && y == b)
									continue;
								if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1&&A[x][y] == -1)
								{
									count2++;
									if (abs(x - i) > 1 || abs(y - j) > 1)
									{
										flag = 0; break;
									}
								}
							}
							if (!flag) break;
						}
						if (flag && (A[i][j] - A[a][b] == count - count2))//(i,j)的未知格子包含(a,b)的未知格子数
						{
							for (int a1 = i - 1; a1 <= i + 1; a1++)
								for (int b1 = j - 1; b1 <= j + 1; b1++)
								{
									if (a1 == i && b1 == j) continue;
									if (a1 >= 0 && a1 <= n - 1 && b1 >= 0 && b1 <= m - 1 && A[a1][b1] == -1)
										if (abs(a1 - a) > 1 || abs(b1 - b) > 1)
										{
											S[a1][b1] = 1;
											//printf("test%d %d %d %d\n", i, j, a, b);
										}
								}
						}
					}
				}
		}
}
//void mine(int n, int m)
//{
//	rule1(n, m);
//	rule2(n, m);
//	rule3(n, m);
//}
void print_ans(int n, int m)
{
	y_num = n_num = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (S[i][j] == 0) n_num++;
			if (S[i][j] == 1) y_num++;
		}
	printf("%d %d\n", y_num, n_num);
}

int main()
{
	//printf("heihei\n%cthaha\n",'c');
	int t,n,m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &n, &m);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				scanf("%d", &A[j][k]);
				S[j][k] = -1;
			}
		
		mine(n,m);
		print_ans(n, m);
	}
	system("pause");
	return 0;
}