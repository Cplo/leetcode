#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<math.h>

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int cursum = nums[0];
		int maxsum = nums[0];
		int n = nums.size();
		for (int i = 1; i < n; i++){
			cursum = max(cursum + nums[i], nums[i]);
			maxsum = max(maxsum, cursum);
		}
		return maxsum;
	}
	int lengthOfLastWord(string s) {
		int i = s.length() - 1;
		int ans = 0;
		while (i >= 0 && s[i] == ' '){
			i--;
		}
		while (i >= 0 && s[i] != ' '){
			i--;
			ans++;
		}
		return ans;
	}
	string getPermutation(int n, int k) {
		string ans;
		vector<int> nums;
		string s;
		int mult = 1;
		for (int i = 1; i <= n - 1; i++){
			mult *= i;
			nums.push_back(mult);
			s.push_back(i+'0');
		}
		s.push_back(n+'0');
		for (int j = n - 2; j >= 0;j--){
			int idx = ceil((double)k / nums[j]);
			ans.push_back(s[idx - 1]);
			k = k - (idx - 1)*nums[j];
			s.erase(s.begin() + idx - 1);
		}
		ans.push_back(s[0]);
		return ans;
	}
};

int main(void)
{
	int a[] = {3,-3,3,-2,5,-5,4};
	vector<int> v(a, a + 7);
	Solution so;
	//cout << so.maxSubArray(v) << endl;
	for (int i = 1; i <= 6;i++)
	cout << so.getPermutation(3,i) << endl;
}