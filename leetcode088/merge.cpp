#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> ans;
		int i = 0, j = 0;
		while (i < m&&j < n) {
			if (nums1[i] < nums2[j]) {
				ans.push_back(nums1[i++]);
			}
			else{
				ans.push_back(nums2[j++]);
			}
		}
		if (i < m) {
			while (i < m) ans.push_back(nums1[i++]);
		}
		if (j < n) {
			while (j < n) ans.push_back(nums2[j++]);
		}
		nums1.clear();
		for (auto it : ans) nums1.push_back(it);
	}
};

int main(void)	{
	return 0;
}