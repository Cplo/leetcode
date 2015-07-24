#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
	void tag(int **a, int i, int j, int &n, int&m, vector<vector<char>>& grid) {
		if (i + 1 < n && !a[i + 1][j] && grid[i + 1][j] == '1') { a[i + 1][j] = 1; tag(a, i + 1, j, n, m, grid); }
		if (i - 1 >= 0 && !a[i - 1][j] && grid[i - 1][j] == '1') { a[i - 1][j] = 1; tag(a, i - 1, j, n, m, grid); }
		if (j - 1 >= 0 && !a[i][j - 1] && grid[i][j - 1] == '1') { a[i][j - 1] = 1; tag(a, i, j - 1, n, m, grid); }
		if (j + 1 < m && !a[i][j + 1] && grid[i][j + 1] == '1') { a[i][j + 1] = 1; tag(a, i, j + 1, n, m, grid); }
	}
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		if (!n) return 0;
		int m = grid[0].size();
		if (!m) return 0;
		int **a = new int*[n];
		for (int i = 0; i < n; i++){
			a[i] = new int[m];
			memset(a[i], 0, m*sizeof(int));
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (grid[i][j] == '1'&& !a[i][j]) {
					ans++;
					a[i][j] = 1;
					tag(a, i, j, n, m, grid);
				}
			}
		}
		return ans;
	}
};
int main(void){
	string s = "1011011";
	vector<char> v(s.c_str(), s.c_str() + 7);
	vector<vector<char>> v1;
	v1.push_back(v);
	Solution so;
	cout << so.numIslands(v1) << endl;
	return 0;
}