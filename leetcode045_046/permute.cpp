#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		do{
			ans.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return ans;
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {

	}
};

