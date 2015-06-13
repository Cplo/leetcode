#include<cstdio>
#include<vector>
#include<stdlib.h>
#include<string.h>
using namespace std;
#pragma warning(disable:4996)
const int N = 205;
int A[N][N];
int S[N][N];
vector<int> row;
vector<int> column;

//1.���ĳһ����̽���ĸ��������������Ϊ0����ô�����ڵ�8���������δ̽�����ӱ�������һ�����ǵ��׵ĸ��ӡ�
void rule1(int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (!A[i][j]) {
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++) {
						if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)	S[a][b] = 0;
					}
			}
		}
}
/*
* 2.���ĳһ����̽���ĸ��������������ΪK���������ڵ�8��������������K��û��̽���ĸ��ӵĻ�������K��û��
*   ̽���ĸ��ӱ�������һ���ǵ��׵ĸ��ӡ�
*/
void rule2(int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (A[i][j] <= 0) continue;
			int count = 0;
			for (int a = i - 1; a <= i + 1; a++)
				for (int b = j - 1; b <= j + 1; b++) {
					if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)	count++;
				}
			if (count == A[i][j]) {
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++) {
						if (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1 && A[a][b] == -1)	S[a][b] = 1;// printf("test%d %d\n",a,b);
					}
			}
		}
}
/*
* 3.���ĳ����̽���˵ĸ���A��B�������б��������ֱַ�ΪP_A��P_B����������Χ8��������û��̽���ĸ�����ɵļ��Ϸֱ�ΪS_A��S_B��
*   ���S_A����S_B����|S_A|-|S_B|=P_A-P_B����ôS_A-S_B�е����и��ӣ���������һ���ǵ��׵ĸ��ӡ�
*/
void rule3(int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (A[i][j] <= 0) continue;
			for (int a = i - 1; a <= i + 1; a++)
				for (int b = j - 1; b <= j + 1; b++) {
					if (a == i&&b == j) continue;
					if (a >= 0 && a < n && b >= 0 && b < m && A[a][b] >= 0) {
						if (a == i || b == j){
							if (a == i - 1) {
								int flag = 1;
								if (a-1 >= 0)
									for (int x = b - 1; x <= b + 1; x++) 
										if (x>=0&&x<m&&A[a - 1][x] == -1) {
											flag = 0; break;
										}
								if (!flag) continue;//������
								if (i + 1 >= n) continue;
								int count = 0;
								for (int x = b - 1; x <= b + 1; x++)
									if (x >= 0 && x<m && A[i + 1][x] == -1) count++;
								if (count == A[i][j]-A[a][b]) {
									for (int x = b - 1; x <= b + 1; x++)
										if (x >= 0 && x<m && A[i + 1][x] == -1) { row.push_back(i + 1); column.push_back(x); }
								}
							}
							else if (a == i + 1) {
								int flag = 1;
								if (a+1<n)
								for (int x = b - 1; x <= b + 1; x++)
									if (x>=0&&x<m&& A[a + 1][x] == -1) {
										flag = 0; break;
									}
								if (!flag||i-1<0) continue;//������
								int count = 0;
								for (int x = b - 1; x <= b + 1; x++)
									if (x >= 0 && x<m && A[i - 1][x] == -1) count++;
								if (count == A[i][j] - A[a][b]) {
									for (int x = b - 1; x <= b + 1; x++)
										if (x >= 0 && x<m && A[i - 1][x] == -1) { row.push_back(i - 1); column.push_back(x); }
								}
							}
							else if (b == j - 1) {
								int flag = 1;
								if (b-1>=0)
								for (int x = a - 1; x <= a + 1; x++)
									if (x>=0&&x<n&&A[x][b-1] == -1) {
										flag = 0; break;
									}
								if (!flag||j+1>=m) continue;//������
								int count = 0;
								for (int x = a - 1; x <= a + 1; x++)
									if (x>=0&&x<n&& A[x][j + 1] == -1) count++;
								if (count == A[i][j] - A[a][b]) {
									for (int x = a - 1; x <= a + 1; x++)
										if (x >= 0 && x<n&&  A[x][j + 1] == -1) { row.push_back(x); column.push_back(j + 1); }
								}
							}
							else{
								int flag = 1;
								if (b+1<m)
								for (int x = a - 1; x <= a + 1; x++)
									if (x>=0&&x<n&&A[x][b + 1] == -1) {
										flag = 0; break;
									}
								if (!flag||j-1<0) continue;//������
								int count = 0;
								for (int x = a - 1; x <= a + 1; x++)
									if (x >= 0 && x<n&& A[x][j - 1] == -1) count++;
								if (count == A[i][j] - A[a][b]) {
									for (int x = a - 1; x <= a + 1; x++)
										if (x >= 0 && x<n&& A[x][j - 1] == -1) { row.push_back(x); column.push_back(j - 1); }
								}
							}
						}
						else/*�ĸ���*/ {
							if (a - i == -1 && b - j == -1) {
								int flag = 1;
								if (a-1>=0)
									for (int x = b - 1; x <= j; x++) {
										if (x >= 0 && x < m&&A[a - 1][x] == -1) {
											flag = 0; break;
										}
									}
								if (b - 1 >= 0)
									for (int x = a - 1; x <= i; x++){
										if (x >= 0 && x < n&&A[x][b - 1] == -1){
											flag = 0; break;
										}
									}
								if (!flag) continue;
								int count = 0;
								if (i + 1 < n)
									for (int x = j - 1; x <= j + 1; x++) {
										if (x >= 0 && x < m&&A[i + 1][x] == -1) count++;
									}
								if (j + 1 < m)
									for (int x = i - 1; x <= i + 1; x++){
										if (x >= 0 && x < n&&A[x][j + 1] == -1) count++;
									}
								if (i + 1 < n&&j + 1 < m&&A[i + 1][j + 1] == -1) count--;
								if (count == A[i][j] - A[a][b]) {
									if (i + 1 < n)
										for (int x = j - 1; x <= j + 1; x++) {
											if (x >= 0 && x < m&&A[i + 1][x] == -1) { row.push_back(i + 1); column.push_back(x); }//A[i + 1][x] = 1;}
										}
									if (j + 1 < m)
										for (int x = i - 1; x <= i + 1; x++){
											if (x >= 0 && x < n&&A[x][j + 1] == -1) { row.push_back(x); column.push_back(j + 1); }//A[x][j + 1] = 1;
										}
								}
							}
							else if (a - i == -1 && b - j == 1) {
								int flag = 1;
								if (a - 1 >= 0)
									for (int x = b - 1; x <= b+1; x++) {
										if (x >= 0 && x < m&&A[a - 1][x] == -1) {
											flag = 0; break;
										}
									}
								if (b + 1 < m)
									for (int x = a - 1; x <= a+1; x++){
										if (x >= 0 && x < n&&A[x][b + 1] == -1){
											flag = 0; break;
										}
									}
								if (!flag) continue;
								int count = 0;
								if (i + 1 < n)
									for (int x = j - 1; x <= j + 1; x++) {
										if (x >= 0 && x < m&&A[i + 1][x] == -1) count++;
									}
								if (j - 1 >= 0)
									for (int x = i - 1; x <= i + 1; x++){
										if (x >= 0 && x < n&&A[x][j - 1] == -1) count++;
									}
								if (i + 1 < n && j - 1 >= 0 && A[i + 1][j - 1] == -1) count--;
								if (count == A[i][j] - A[a][b]) {
									if (i + 1 < n)
										for (int x = j - 1; x <= j + 1; x++) {
											if (x >= 0 && x < m&&A[i + 1][x] == -1) { row.push_back(i + 1); column.push_back(x); }
										}
									if (j - 1 >= 0)
										for (int x = i - 1; x <= i + 1; x++){
											if (x >= 0 && x < n&&A[x][j - 1] == -1)  { row.push_back(x); column.push_back(j - 1); }
										}
								}
							}
							else if (a - i == 1 && b - j == -1) {
								int flag = 1;
								if (a + 1 < n)
									for (int x = b - 1; x <= b + 1; x++) {
										if (x >= 0 && x < m&&A[a + 1][x] == -1) {
											flag = 0; break;
										}
									}
								if (b - 1 >= 0)
									for (int x = a - 1; x <= a + 1; x++){
										if (x >= 0 && x < n&&A[x][b - 1] == -1){
											flag = 0; break;
										}
									}
								if (!flag) continue;
								int count = 0;
								if (i - 1 >= 0)
									for (int x = j - 1; x <= j + 1; x++) {
										if (x >= 0 && x < m&&A[i - 1][x] == -1) count++;
									}
								if (j + 1 < m)
									for (int x = i - 1; x <= i + 1; x++){
										if (x >= 0 && x < n&&A[x][j + 1] == -1) count++;
									}
								if (i - 1 >= 0 && j + 1 < m&&A[i - 1][j + 1] == -1) count--;
								if (count == A[i][j] - A[a][b]) {
									if (i - 1 >= 0)
										for (int x = j - 1; x <= j + 1; x++) {
											if (x >= 0 && x < m&&A[i - 1][x] == -1) { row.push_back(i - 1); column.push_back(x); }
										}
									if (j + 1 < m)
										for (int x = i - 1; x <= i + 1; x++){
											if (x >= 0 && x < n&&A[x][j + 1] == -1) { row.push_back(x); column.push_back(j + 1); }
										}
								}
							}
							else if (a - i == 1 && b - j == 1) {
								int flag = 1;
								if (a + 1 < n)
									for (int x = b - 1; x <= b + 1; x++) {
										if (x >= 0 && x < m&&A[a + 1][x] == -1) {
											flag = 0; break;
										}
									}
								if (b+1 <m)
									for (int x = a - 1; x <= a + 1; x++){
										if (x >= 0 && x < n&&A[x][b + 1] == -1){
											flag = 0; break;
										}
									}
								if (!flag) continue;
								int count = 0;
								if (i - 1 >= 0)
									for (int x = j - 1; x <= j + 1; x++) {
										if (x >= 0 && x < m&&A[i - 1][x] == -1) count++;
									}
								if (j-1>=0)
									for (int x = i - 1; x <= i + 1; x++){
										if (x >= 0 && x < n&&A[x][j - 1] == -1) count++;
									}
								if (i - 1 >= 0 && j - 1 >= 0 && A[i - 1][j - 1] == -1) count--;
								if (count == A[i][j] - A[a][b]) {
									if (i - 1 >= 0)
										for (int x = j - 1; x <= j + 1; x++) {
											if (x >= 0 && x < m&&A[i - 1][x] == -1) { row.push_back(i - 1); column.push_back(x); }
										}
									if (j - 1 >= 0)
										for (int x = i - 1; x <= i + 1; x++){
											if (x >= 0 && x < n&&A[x][j - 1] == -1){ row.push_back(x); column.push_back(j - 1); }
										}
								}
							}
						}
					}
				}
		}
		for (int k = 0; k < row.size(); k++) {
			S[row[k]][column[k]] = 1;
		}
}
void mine(int n, int m) {
	rule1(n, m);
	rule2(n, m);
	rule3(n, m);
}

void print_ans(int n, int m)
{
	int y_num = 0, n_num = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (S[i][j] == 0) n_num++;
			if (S[i][j] == 1) y_num++;
		}
	printf("%d %d\n", y_num, n_num);
}

int main(void) {
	int t, n, m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &n, &m);
		for (int j = 0; j < n; j++) {
			memset(S[j], -1, m*sizeof(int));
			for (int k = 0; k < m; k++) scanf("%d", &A[j][k]); 
		}
		mine(n, m);
		print_ans(n, m);
	}
	system("pause");
	return 0;
}