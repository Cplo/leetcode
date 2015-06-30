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

class Solution {
public:
/*	void rob(int cur, vector<int>& nums) {
		if (cur == n - 1) {
			ans[cur] = nums[n - 1]; 
			return; 
		}
		int temp = 0;
		if (ans[cur + 1] == -1) rob(cur + 1, nums);
		temp = max(temp, ans[cur + 1]);
		temp = max(temp, nums[cur]);
		if (cur + 2 < n) {
			if (ans[cur + 2] == -1) rob(cur + 2, nums);
			temp = max(temp, nums[cur] + ans[cur + 2]);
		}
		if (cur + 3 < n) {
			if (ans[cur + 3] == -1) rob(cur + 3, nums);
			temp = max(temp, nums[cur] + ans[cur + 3]);
		}
		ans[cur] = temp;
	}
	int rob(vector<int>& nums) {
		n = nums.size();
		if (!n) return 0;
		memset(ans, -1, n*sizeof(int));
		rob(0, nums);
		return ans[0];
	} */
	void rob(int cur, vector<int>& nums, int& n, int ans[]) {
		if (cur == n - 1) {
			ans[cur] = nums[n - 1]; return;
		}
		if (ans[cur + 1] == -1) rob(cur + 1, nums, n, ans);
		int temp = nums[cur];
		temp = max(temp, ans[cur + 1]);
		if (cur + 2 < n) {
			if (ans[cur + 2] == -1) rob(cur + 2, nums, n, ans);
			temp = max(temp, nums[cur] + ans[cur + 2]);
		}
		if (cur + 3 < n) {
			if (ans[cur + 3] == -1) rob(cur + 3, nums, n, ans);
			temp = max(temp, nums[cur] + ans[cur + 3]);
		}
		ans[cur] = temp;
	}
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (!n) return 0;
		if (n == 1) return nums[0];
		int ans[1000], ans1[1000];
		memset(ans, -1, n*sizeof(int));
		memset(ans1, -1, n*sizeof(int));
		rob(1, nums, n, ans1);
		n--;
		rob(0, nums, n, ans);
		return max(ans1[1], ans[0]);
	}
//private:
//	int n;
};

int main(void) {
	//8,8,9,5,4
	//8 9 5 10
	//8 8 9 5 10
	int a[] = { 
		8, 9, 9, 4, 10, 5, 6, 9, 7, 9};
	vector<int> v(a, a + 10);
	Solution so;
	printf("%d\n", so.rob(v));
	return 0;
}