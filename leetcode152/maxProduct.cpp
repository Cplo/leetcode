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
	void maxProduct(int ans[], vector<int>& nums, int cur) {
		int product = 1;
		
	}
	int maxProduct(vector<int>& nums) {
		//int ans[10000];
		n = nums.size();
		if (n == 1) return nums[0];
		//memset(ans, -1, n*sizeof(int));
		//maxProduct(ans, nums, 0);
		int ans = INT_MIN;
		int cur_idx = 0;
		for (int i = 0; i < n;) {
			if (!nums[i]) ans = max(ans, 0);
			while (i < n && !nums[i]) {
				i++; cur_idx = i;
			}
			if (i >= n) break;
			if (i == n - 1 || !nums[i + 1])
				ans = max(ans, nums[i]);
			else if(nums[i + 1]) {
				int product = nums[i];
				int start = i;
				while (i + 1 < n && nums[i + 1]) {
					product *= nums[i + 1];
					i++;
				}
				if (product < 0 && i + 1 - start > 1) {
					int left = 1, right = 1;
					int k = start;
					while (nums[k] > 0) { left *= nums[k]; k++; }
					left *= nums[k];
					k = i;
					while (nums[k] > 0) { right *= nums[k]; k--; }
					right *= nums[k];
					product /= max(left, right);
				}
				ans = max(ans, product);
			}
			i++;
		}
		return ans;
	}
private:
	int n;
};

int main(void) {
	int a[] = { 3, 2, 1, -1, 1, 0, 0};
	vector<int> v(a, a + 7);
	Solution so;
	printf("%d\n", so.maxProduct(v));
	return 0;
}