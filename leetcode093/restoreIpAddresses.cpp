#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
using namespace std;
class Solution {
public:
	void produce_ip(vector<string>& ans, string cur, string s, int num) {
		if (num == 4) {
			if (s.size() != 1 && s[0] == '0') return;
			if (s.size() <= 2 || s <= "255") {
				cur += ("."+s);
				ans.push_back(cur.substr(1));
			}
			return;
		}
		int n = s.length();
		for (int i = 1; i <= 3; i++){
			string s1 = s.substr(0, i);
			if (s1.size() != 1 && s1[0] == '0') return;
			if (n - i <= (4 - num) * 3 && n - i >= 4 - num && (s1.size()<=2||s1 <= "255")){
				produce_ip(ans, cur + "." + s1, s.substr(i), num + 1);
			}
		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		produce_ip(ans, "", s, 1);
		return ans;
	}
};
int main(void) {
	Solution so;
	so.restoreIpAddresses("25525511135");
	return 0;
}