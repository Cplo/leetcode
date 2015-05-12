#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<math.h>

class Solution {
public:
	int array[101][101];
public:
	Solution(){
		for (int i = 1; i <= 100; i++){
			memset(array[i] + 1, -1, 100 * sizeof(int));
		}
	}
	int uniquePaths(int m, int n, vector<vector<int>>& v) {
		if (v[m - 1][n - 1]) { array[m][n] = 0; return 0; }
		if (m == 1){
			for (int i = 1; i <= n - 1; i++){
				if (v[m - 1][i - 1]) {
					array[m][n] = 0; return 0;
				}
			}
			array[m][n] = 1; return 1;
		}
		if (n == 1){
			for (int i = 1; i <= m - 1; i++){
				if (v[i - 1][n-1]) {
					array[m][n] = 0; return 0;
				}
			}
			array[m][n] = 1; return 1;
		}
		int a = array[m - 1][n];
		int b = array[m][n - 1];

		if (a==-1) {
			a = uniquePaths(m - 1, n, v); array[m - 1][n] = a;
		}
		if (b==-1) {
			b = uniquePaths(m, n - 1, v); array[m][n - 1] = b; 
		}
		return a + b;
	}
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		//return uniquePaths(obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid);
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int array[100][100];
		int i, j;
		int flag_m = 0;//标记第一行中是否出现1
		int flag_n = 0;//标记第一列中是否出现1
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
			{
				if (i == 0){
					if (flag_m){
						array[i][j] = 0; 
					}
					else if(obstacleGrid[i][j]) {
						array[i][j] = 0; flag_m = 1; 
					}
					else array[i][j] = 1;
				}
				if (j == 0){
					if (flag_n){
						array[i][j] = 0; 
					}
					else  if (obstacleGrid[i][j]) {
						array[i][j] = 0; flag_n = 1;
					}
					else array[i][j] = 1; 
				}
				if (!i || !j) continue;
				if (obstacleGrid[i][j]){
					array[i][j] = 0;
				}
				else
					array[i][j] = (array[i - 1][j] + array[i][j - 1]);
			}
		return array[m - 1][n - 1];
    }
};

int main(){
	Solution so;
	int a[3][3] = { 0, 1, 0,
					0, 0, 1,
					1, 0, 0 };
	vector<vector<int>> v;
	int b[2] = { 1, 0 };
	for (int i = 0; i < 3; i++){
		vector<int> v1(a[i],a[i]+3);
		v.push_back(v1);
	}
	cout << so.uniquePathsWithObstacles(v) << endl;
	return 0;
}