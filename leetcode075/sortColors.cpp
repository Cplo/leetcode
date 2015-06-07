#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		//sort(nums.begin(), nums.end());
		int n = nums.size();
		if (!n) return;
		int red = 0, white = 0, blue = 0;
		for (auto i : nums) {
			if (i == 0) red++;
			else if (i == 1) white++;
			else blue++;
		}
		if (red) for (int i = 0; i < red; i++) nums[i] = 0;
		if (white) for (int i = red; i < red + white; i++) nums[i] = 1;
		if (blue) for (int i = red + white; i < n; i++) nums[i] = 2; 
	}
	string minWindow(string s, string t) {
		string ans = "";
		map<char, int> m;
		map<char, int> m1;
		for (auto i : t) m[i]++;
		int start = -1;
		int len = s.length();
		int n = m.size();
		int count = 0;
		int ans_len = len + 1;
		int ans_start;
		for (int i = 0; i < len; i++) {
			if (m.find(s[i]) == m.end()) continue;
			if (start == -1) start = i;
			m1[s[i]]++;
			if (m1[s[i]] == m[s[i]]) {
				count++;
				if (count == n){
					ans_len = min(ans_len, i - start + 1);
					ans_start = start;
				}
			}
			int k = start;
			if (count == n && m1[s[k]] > m[s[k]]) {
				while (m1[s[k]] > m[s[k]]) {
					m1[s[k]]--;
					k++;
					while (m1.find(s[k]) == m1.end()) k++;
				}
				start = k;
				if (i - k + 1 <= ans_len) {
					ans_start = k; ans_len = i - k + 1;
				}
			}
		}
		if (ans_len == len + 1) return "";
		return s.substr(ans_start, ans_len);
	}
};
int main(void) {
	Solution so;
	int a[] = {2,1,1,2,0,1,2};
	vector<int> v;
	for (int i = 0; i < 7; i++) {
		v.push_back(a[i]);
	}
	so.sortColors(v);
	cout << so.minWindow("cabwefgewcwaefgcf", "cae") << endl;
	return 0;
}