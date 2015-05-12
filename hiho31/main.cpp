#include<cstdio>
#include<stdlib.h>
#include<math.h>
//using namespace std;
#define N 205
#pragma warning(disable:4996)

int A[N][N];
int S[N][N];
int y_num, n_num;

//1.���ĳһ����̽���ĸ��������������Ϊ0����ô�����ڵ�8���������δ̽�����ӱ�������һ�����ǵ��׵ĸ��ӡ�
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
	*2.���ĳһ����̽���ĸ��������������ΪK���������ڵ�8��������������K��û��̽���ĸ��ӵĻ�������K��û��
	*̽���ĸ��ӱ�������һ���ǵ��׵ĸ��ӡ�
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
//3.���ĳ����̽���˵ĸ���A��B�������б��������ֱַ�ΪP_A��P_B����������Χ8��������û��̽���ĸ�����ɵļ��Ϸֱ�ΪS_A��S_B�����S_A����S_B����|S_A|-|S_B|=P_A-P_B����ôS_A-S_B�е����и��ӣ���������һ���ǵ��׵ĸ��ӡ�
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
						int flag = 1;//�ж�(i,j)�Ƿ����(a,b)��δ֪���ӡ�
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
						if (flag && (A[i][j] - A[a][b] == count - count2))//(i,j)��δ֪���Ӱ���(a,b)��δ֪������
						{
							//(i,j)-(a,b)��δ֪����һ�����ף�
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
			//Ӧ�ù���һ
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
			//Ӧ�ù����
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
			//Ӧ�ù�����
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
						if (flag && (A[i][j] - A[a][b] == count - count2))//(i,j)��δ֪���Ӱ���(a,b)��δ֪������
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