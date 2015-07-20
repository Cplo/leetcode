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
	//solution
	int longestConsecutive(vector<int>& nums) {
		int n = nums.size();
		if (!n) return 0;
		sort(nums.begin(), nums.end());
		int ans = 1;
		for (int i = 0; i < n;) {
			int num = 1;
			while (i + 1 < n&&nums[i + 1] - nums[i] <= 1) {
				if (nums[i + 1] - nums[i]) num++;
				i++;
			}
			ans = max(ans, num);
			i++;
		}
		return ans;
	}
};

int main(void) {
	int a[] = { 100, 4, 200, 1, 3, 2 };
	vector<int>v(a,a+6);
	Solution so; cout<<so.longestConsecutive(v);
	return 0;
}