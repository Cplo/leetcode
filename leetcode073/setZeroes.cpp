#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (!n) return;
		int m = matrix[0].size();
		int *p = new int[m];
		int *r = new int[n];
		memset(p, 0, m*sizeof(int));
		memset(r, 0, n*sizeof(int));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!matrix[i][j]) {
					r[i] = p[j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (r[i]) memset(&matrix[i][0], 0, m*sizeof(int));
		}
		for (int i = 0; i < m; i++) {
			if (p[i]) for (int k = 0; k < n; k++) matrix[k][i] = 0;
		}
	}
	bool searchMatrix(vector<int>& matrix, int target) {
		int l=0,r=matrix.size()-1,mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (matrix[mid] == target) return true;
			if (matrix[mid] < target) l++;
			else r--;
		}
		return false;
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (!n) return false;
		int m = matrix[0].size();
		if (!m) return false;
		int l = 0, r = n - 1;
		int mid;
		if (n == 1) return searchMatrix(matrix[0], target);
		while (l <= r) {
			mid = (l + r) / 2;
			if (mid == n - 1 && target >= matrix[mid].front()) break;
			else if (target >= matrix[mid].front() && target < matrix[mid + 1].front()) break;
			else if (target >= matrix[mid + 1].front()) l = l + 1;
			else r = r - 1;
		}
		if (matrix[mid].front() == target || matrix[mid].back() == target) return true;
		if (matrix[mid].front() > target || matrix[mid].back() < target) return false;
		return searchMatrix(matrix[mid],target);
	}
};
int main(void) {
	vector<vector<int>> matrix;
	int a[][4] = { 
		1, 3, 5, 7,
		10, 11, 16, 20,
		23, 30, 34, 50 };
	for (int i = 0; i < 1; i++) {
		vector<int> v(a[i], a[i] + 1);
		matrix.push_back(v);
	}
	Solution so;
	cout << so.searchMatrix(matrix, 1) << endl;
	return 0;
}