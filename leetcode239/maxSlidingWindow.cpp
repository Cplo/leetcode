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

struct node
{
	int idx;
	int value;
	node(int i, int v) :idx(i), value(v) {}
};	
bool cmp(const node& left, const node&right) {
		return left.value < right.value;
}
class Solution {
public:

	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		int n = nums.size();
		if (!n) return ans;
		if (k >= n) {
			make_heap(nums.begin(), nums.end());
			pop_heap(nums.begin(), nums.end());
			ans.push_back(nums.back());
			return ans;
		}
		vector<node> v;
		for (int i = 0; i < k - 1; i++) {
			v.push_back(node(i, nums[i]));
		}
		make_heap(v.begin(), v.end(), cmp);
		for (int i = k - 1; i < n; i++) {
			v.push_back(node(i, nums[i]));
			push_heap(v.begin(), v.end(), cmp);
			do {
				pop_heap(v.begin(), v.end(), cmp);
				node a(v.back().idx, v.back().value);
				v.pop_back();
				if (a.idx > i - k) {
					ans.push_back(a.value);
					v.push_back(a);
					push_heap(v.begin(), v.end(), cmp);
					break;
				}
			} while (1);
		}
		return ans;
	}
};

int main(void) {
	int a[] = { 1, 3, 1, 2, 0, 5};
	vector<int> v(a, a + 6);
	Solution so; so.maxSlidingWindow(v,3);
	return 0;
}