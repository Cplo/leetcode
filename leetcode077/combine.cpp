#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
/*
4 2
[
	[2, 4],
	[3, 4],
	[2, 3],
	[1, 2],
	[1, 3],
	[1, 4],
] 
*/
class Solution {
public:
	vector<vector<int>> combine(int l, int r, int k) {
		vector<vector<int>> ans;
		if (k == 1) {
			for (int i = l; i <= r; i++) {
				vector<int> v; 
				v.push_back(i);
				ans.push_back(v);
			}
			return ans;
		}
		for (int i = l; r - i + 1 >= k; i++) {
			vector<vector<int>> vi = combine(i + 1, r, k - 1);
			for (auto v_it : vi) {
				//v_it.push_back(i);
				v_it.insert(v_it.begin(), i);
				ans.push_back(v_it);
			}
		}
		return ans;
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		if (!k) return ans;
		return combine(1, n, k);
	}

	//Subsets
	vector<vector<int>> combine(int l, int r, int k, vector<int>& nums) {
		vector<vector<int>> ans;
		if (!k) { vector<int> v; ans.push_back(v); return ans; }
		if (k == 1) {
			for (int i = l; i <= r; i++) {
				vector<int> v;
				v.push_back(nums[i]);
				ans.push_back(v);
			}
			return ans;
		}
		for (int i = l; r - i + 1 >= k; i++) {
			vector<vector<int>> vi = combine(i + 1, r, k - 1, nums);
			for (auto v_it : vi) {
				//v_it.push_back(i);
				v_it.insert(v_it.begin(), nums[i]);
				ans.push_back(v_it);
			}
		}
		return ans;
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int i = 0; i <= n; i++) {
			vector<vector<int>> vi = combine(0, n - 1, i, nums);
			for (auto vi_it : vi) ans.push_back(vi_it);
		}
		return ans;
	}

	//[1, 2, 2]
	//1
	//2
	//1 2
	//2 2
	//1 2 2
	vector<vector<int>> combineWithDup(int l, int r, int k, vector<int>& nums) {
		vector<vector<int>> ans;
		if (!k) { vector<int> v; ans.push_back(v); return ans; }
		if (k == 1) {
			for (int i = l; i <= r; ) {
				vector<int> v;
				v.push_back(nums[i]);
				ans.push_back(v); 
				i++;
				while (i <= r&&nums[i] == nums[i - 1]) i++;
			}
			return ans;
		}
		for (int i = l; r - i + 1 >= k; ) {
			vector<vector<int>> vi = combineWithDup(i + 1, r, k - 1, nums);
			for (auto v_it : vi) {
				//v_it.push_back(i);
				v_it.insert(v_it.begin(), nums[i]);
				ans.push_back(v_it);
			}
			i++;
			while (r - i + 1 >= k && nums[i] == nums[i - 1]) i++;
		}
		return ans;
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int i = 0; i <= n; i++) {
			vector<vector<int>> vi = combineWithDup(0, n - 1, i, nums);
			for (auto vi_it : vi) ans.push_back(vi_it);
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	int a[] = {2,2,2};
	vector<int> v(a, a + 3);
	so.subsetsWithDup(v);
	return 0; 
}