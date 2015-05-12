#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		int sum = 0;
		int ans = INT_MAX;
		int start = 0;
		int j, len;
		for (int i = 0; i < n; i++){
			if (nums[i] >= s) return 1;
			int j = start;
			sum += nums[i];
			if (sum >= s){
				while (j <= i - 1 && sum - nums[j] >= s){
					sum -= nums[j];
					j++;
				}
				start = j;
				len = i - start + 1;
				if (ans > len)  ans = len;
			}
		}
		if (ans == INT_MAX) return 0;
		return ans;
	}
};

int main(void){
	int a[] = { 2, 3, 1, 2, 4, 3 ,7};
	vector<int> v(a, a + 7);
	Solution so;
	cout << so.minSubArrayLen(7, v) << endl;
	return 0;
}