#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) return 1;
		for (int i = 0; i < nums.size();i++	){
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
			{
				swap(nums[nums[i] - 1], nums[i]);
			}
		}
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] != i + 1) return i + 1;
		}
		return nums.size() + 1;
		/*
		sort(nums.begin(), nums.end());
		int pre = 0;
		for (auto i : nums){
			if (i <= 0) continue;
			if (i - pre > 1) return pre + 1;
			pre = i;
		}
		return nums.back() + 1;*/
	}
};

int main(){
	int a[4] = { 3, 4, -1, 1 };
	vector<int> v(a,a+4);
	Solution so;
	cout<<so.firstMissingPositive(v);
	return 0;
}