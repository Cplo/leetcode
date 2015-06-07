#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
using namespace std;

class Solution {
public:
	/*int maxArea(int l, int r, int row) {
		int ans = 0;
		int cur = r;
		for (int k = r; k >= l + 1; k--)	{
			if (hei[row][k - 1] >= hei[row][cur]) continue;
			else {
				ans = max(ans, hei[row][cur] * (r - k + 1));
				cur = k - 1;
			}
		}
		ans = max(ans, hei[row][cur] * (r - l + 1));
		return ans;
	}*/
	int largestRectangleArea(vector<int> &height) {
		int n = height.size();
		if (n == 0) return 0;
		if (n == 1) return height[0];

		height.push_back(0);
		n++;

		int ans = 0;
		stack<int> s;

		int i = 0, j = 0, h = 0;
		while (i<n){
			if (s.empty() || height[i]>height[s.top()]) s.push(i++);
			else{
				h = height[s.top()];
				s.pop();
				j = s.empty() ? -1 : s.top();
				ans = max(ans, h*(i - j - 1));
			}
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	int a[] = {1,2,3,4,5,3};
	vector<int> v(a, a + 6); cout << so.largestRectangleArea(v) << endl;
	//cout <<  << endl;
	return 0;
}