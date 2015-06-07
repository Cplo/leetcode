#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
//For instance, ABCDE.There exists no scramble like CAEBD under the given operations.
/*class Solution {
public:
	bool isScramble(int index, string s, string &goal) {
		int n = s.size();
		if (goal.substr(index, n) == s) return true;
		for (int i = 0; i + 1 < n; i++) {
			string s_left = s.substr(0, i + 1);
			string s_right = s.substr(i + 1);
			if (isScramble(index, s_left, goal) && isScramble(index + i + 1, s_right, goal)) return true;
			if (isScramble(index, s_right, goal) && isScramble(index + n - (i + 1), s_left, goal)) return true;
		}
		return false;
	}
	bool isScramble(string s1, string s2) {
		return isScramble(0, s1, s2);
	}
};*/
class Solution {
public:
	bool isScramble(int index, string s, string &goal) {
		int n = s.size();
		if (goal.substr(index, n) == s) return true;
		for (int i = 0; i + 1 < n; i++) {
			string s_left = s.substr(0, i + 1);
			string s_right = s.substr(i + 1);
			if (s_left.size() < s_right.size()) {
				if (isScramble(index, s_left, goal) && isScramble(index + i + 1, s_right, goal)) return true;
				if (isScramble(index + n - (i + 1), s_left, goal) && isScramble(index, s_right, goal)) return true;
			}
			else {
				if (isScramble(index + i + 1, s_right, goal) && isScramble(index, s_left, goal) ) return true;
				if (isScramble(index, s_right, goal) && isScramble(index + n - (i + 1), s_left, goal)) return true;
			}
		}
		return false;
	}
	bool isScramble(string s1, string s2) {
		return isScramble(0, s1, s2);
	}
};
int main(void) {
	Solution so;
	//cout << so.isScramble("abcde", "caebd") << endl;
	//cout << so.isScramble("abbbcbaaccacaacc", "acaaaccabcabcbcb") << endl;
	cout << so.isScramble("abbbcbaaccacaacc", "acaaaccabcabcbcb") << endl;
	return 0;
}