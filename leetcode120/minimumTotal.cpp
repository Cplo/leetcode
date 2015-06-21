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
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int ans = INT_MAX;
		int n = triangle.size();
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++){
				if (j == 0) triangle[i][j] += triangle[i - 1][j];
				else if(j == i) triangle[i][j] += triangle[i - 1][j - 1];
				else {
					triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
				}
			}
		}
		for (int j = 0; j < n; j++) {
			ans = min(triangle[n - 1][j], ans);
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	int a[][4] = { { 2 }, { 3, 4 }, { 6, 5, 7 }, {4,1,8,3} };
	vector<vector<int>> v;
	for (int i = 1; i <= 4; i++){
		vector<int> v1(a[i - 1], a[i - 1] + i);
		v.push_back(v1);
	}
	cout << so.minimumTotal(v) << endl;
	return 0;
}