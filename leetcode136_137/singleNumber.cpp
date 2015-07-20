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
	int singleNumber(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n;) {
			if (i + 1 < n) {
				if (nums[i + 1] != nums[i]) return nums[i];
			}
			else return nums.back();
			i += 2;
		}
	}
};

int main(void) {
	return 0;
}