#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
//Maximal Rectangle:20ms
int wid[1000][1000];
int hei[1000][1000];
int area1[1000][1000];
class Solution {
public:
	int maxArea(int l,int r, int row) {
		int ans = 0;
		int cur = r;
		for (int k = r; k >= l+1; k--)	{
			if (hei[row][k - 1] >= hei[row][cur]) continue;
			else {
				ans = max(ans, hei[row][cur]*(r - k + 1));
				cur = k - 1;
			}
		}
		ans = max(ans, hei[row][cur] * (r - l + 1));
		return ans;
	}
	int maximalRectangle(vector<vector<char>>& matrix) {
		int ans = 0;
		int m = matrix.size();
		if (!m) return ans;
		int n = matrix[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '0') {
					wid[i][j] = hei[i][j] = 0;
				}
				else {
					int area = 0;
					if (!i&&!j) {
						wid[i][j] = hei[i][j] = 1;
						area = 1;
					}
					else if (!i) {
						wid[i][j] = wid[i][j - 1] + 1;
						hei[i][j] = 1;
						area = wid[i][j];
					}
					else if(!j) {
						wid[i][j] = 1;
						hei[i][j] = hei[i - 1][j] + 1;
						area = hei[i][j];
					}
					else {
						wid[i][j] = 1 + wid[i][j - 1];
						hei[i][j] = 1 + hei[i - 1][j];
						area = max(area, maxArea(j - wid[i][j] + 1, j, i));
					}
					ans = max(area, ans);
					area1[i][j] = area;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	vector<vector<char>> matrix;
	char ch[][13] = { 
		"00000110110", 
		"11101011101",
		"00000111011" };
	for (int i = 0; i < 1; i++) {
		vector<char> v(ch[i], ch[i] + 1);
		matrix.push_back(v);
	}
	cout << so.maximalRectangle(matrix) << endl;
	return 0;
}