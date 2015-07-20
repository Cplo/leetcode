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
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> un_set;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (un_set.find(nums[i]) != un_set.end()) return true;
			else un_set.insert(nums[i]);
		}
		return false;
	}
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> m;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
			else m[nums[i]] = i;
		}
		return false;
	}
	bool is_ans(map<int, int>& m, int& b, int& t) {
		int n = m.size();
		if (!n) return false;
		map<int, int>::iterator it = m.begin();
		int l = 0, r = n - 1;
		int mid = (l + r) / 2;
		while (l <= r) {
			int mid = (l + r) / 2;
			std::advance(it, mid);
			if (abs((long long)it->first - (long long)b) <= t)  return true;
			if (it->first>b) r--;
			else l++;
		}
		return false;
	}
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int n = nums.size();
		/*for (int i = 0; i < n; i < n) {
			for (int j = i + 1; j < n; j++) {
				if (abs(nums[i] - nums[j]) <= t) return true;
				if (j - i > k) break;
			}
		}*/
		if (!t) return containsNearbyDuplicate(nums, k);
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			if (is_ans(m, nums[i], t)) return true;
			m[nums[i]]++;
			if (i < k) continue;
			m[nums[i - k]]--;
			if (m[nums[i - k]] == 0) m.erase(m.find(nums[i - k]));
		}
		return false;
	}
};

int main(void) {
	Solution so;
	int a[] = { -1, 2147483647};
	vector<int> v(a, a + 2);
	//bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	cout << so.containsNearbyAlmostDuplicate(v,  1, 2147483647) << endl;

	return 0;
}