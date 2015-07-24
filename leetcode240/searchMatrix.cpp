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
	bool search(int i, int j, vector<vector<int>>& matrix, int n, int m, int &target) {
		int starti = i, startj = j;
		while (i < n&&j < m) {
			if (matrix[i][j] < target) {
				if (i + 1 >= n&&j + 1 >= m) return false;
				if (i + 1 < n) i++;
				if (j + 1 < m) j++;
			}
			else if (matrix[i][j] == target) return true;
			else {
				if (search(starti, j, matrix, i, m, target) ||
					search(i, startj, matrix, n, j, target))
					return true;
				return false;
			}
		}
		return false;
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (!n) return false;
		int m = matrix[0].size();
		if (!m) return false;
		return search(0, 0, matrix, n, m, target);
	}
};

int main(void){
	Solution so;
	vector<vector<int>> matrix;
	int a[][5] = {
		{ 1, 4, 7, 11, 15 },
		{ 2, 5, 8, 12, 19 },
		{ 3, 6, 9, 16, 22 },
		{ 10, 13, 14, 17, 24 },
		{ 18, 21, 23, 26, 30 }
	};
	for (int i = 0; i < 5; i++){
		vector<int> v(a[i], a[i] + 5);
		matrix.push_back(v);
	}
	cout << so.searchMatrix(matrix,5) << endl;
}