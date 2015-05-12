#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<math.h>
#include<float.h>

class Solution {
public:
	void find_ans(int &ans, int cur, int i, int j, int m, int n, vector<vector<int>>& grid){
		cur += grid[i - 1][j - 1];
		if (i == m && j == n) {
			cur += grid[m - 1][n - 1]; ans = min(ans, cur); return;
		}		
		if (i + 1 <= m) find_ans(ans, cur, i + 1, j, m, n, grid);
		if (j + 1 <= n) find_ans(ans, cur, i, j + 1, m, n, grid);
	}
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int i, j;
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++){
				if (i == 0 && j == 0) continue;
				if (i == 0){ grid[i][j] += grid[i][j - 1]; continue; }
				if (j == 0){ grid[i][j] += grid[i - 1][j]; continue; }
				grid[i][j] = min(grid[i][j]+grid[i-1][j],grid[i][j]+grid[i][j-1]);
			}
		}
		return grid[m - 1][n - 1];
	}
};
int main(void){
	return 0;
}