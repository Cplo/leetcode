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
using namespace std;

class Solution {
public:
	int numDistinct(string& s, int cur_s, string& t, int cur_t, int **arr) {
		int nums = 0;
		if (cur_t == t1) {
			return 1;
		}
		if (cur_s >= s1 || cur_t > t1) return 0;
		if (t[cur_t] == s[cur_s])  {
			if (arr[cur_s + 1][cur_t + 1] == -1) nums += numDistinct(s, cur_s + 1, t, cur_t + 1, arr);
			else nums += arr[cur_s + 1][cur_t + 1];
		}
		if (arr[cur_s + 1][cur_t] == -1) nums += numDistinct(s, cur_s + 1, t, cur_t, arr);
		arr[cur_s][cur_t] = nums;
		return nums;
	}
	int numDistinct(string s, string t) {
		s1 = s.length();
		t1 = t.length();
		if (s1 < t1 || !t1) return 0;
		int **arr = new int*[s1 + 1];
		for (int i = 0; i < s1 + 1; i++) { arr[i] = new int[t1+1]; memset(arr[i], -1, (1+t1) * sizeof(int)); }
		return numDistinct(s, 0, t, 0, arr);
	}
private:
	int s1;
	int t1;
};

int main(void) {
	Solution so;
	cout << so.numDistinct("rabbbit", "rabbit") << endl;
	return 0;
}