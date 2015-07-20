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

bool cmp(const int &left, const int &right) {
	if (left == right) return false;
	char ch_l[12],ch_r[12];
	sprintf(ch_l, "%d", left);
	sprintf(ch_r, "%d", right);
	string str_l(ch_l);
	string str_r(ch_r);
	str_l += str_r;
	str_r += str_l;
	int n = str_l.size();
	int i = 0;
	while (i < n) {
		if (str_l[i] > str_r[i]) return true;
		if (str_l[i] < str_r[i]) return false;
		i++;
	}
	return false;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		string ans;
		int n = nums.size(); 
		char ch[12];
		for(int i = 0; i < n; i++) { 
			sprintf(ch, "%d", nums[i]);
			string s(ch);
			ans += s;
		}
		int isZero = 1;
		for (auto x : ans) {
			if (x != '0') {
				isZero = 0; break;
			}
		}
		if (isZero){
			ans = "0";
		}
		return ans;
	}
};

int main(void){
	int a[] = { 824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247 };
	vector<int> v(a, a + 9);
	Solution so;
	cout << so.largestNumber(v) << endl;
	return 0;
}