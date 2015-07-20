#include<cstdio>
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
//Maximal Square:16ms
int wid[1000][1000];
int hei[1000][1000];
int area1[1000][1000];
class Solution {
public:
	int maxArea(int l, int r, int row) {
		int side = r - l + 1;
		for (int i = l; i <= r; i++) {
			if (hei[row][i] >= side) {
				continue;
			}
			else {
				side = r - i;
			}
		}
		return side*side;
	}
	int maximalSquare(vector<vector<char>>& matrix) {
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
						area = 1;
					}
					else if (!j) {
						wid[i][j] = 1;
						hei[i][j] = hei[i - 1][j] + 1;
						area = 1;
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
		"00000111110",
		"11101010111",
		"00000111111" };
	for (int i = 0; i < 3; i++) {
		vector<char> v(ch[i], ch[i] + 11);
		matrix.push_back(v);
	}
	printf("%d\n", so.maximalSquare(matrix));
	return 0;
}