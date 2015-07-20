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
#include<unordered_set>
using namespace std;

class Solution {
public:
/*	int isPalindrome(string s) {
		int size = s.size();
		for (int i = 0; i < size / 2; i++) {
			if (s[i] != s[size - 1 - i]) return 0;
		}
		return 1;
	}
	*/
	bool isAlphanumeric(char &k) {
		if (k <= 'Z'&& k >= 'A' || k <= 'z' && k >= 'a' || k <= '9' && k >= '0') return true;
		else return false;
	}
	bool isPalindrome(string s) {
		int n = s.size();
		if (!n) return true;
		/*string s1;
		for (auto k : s) if (k <= 'Z'&& k >= 'A' || k <= 'z' && k >= 'a' || k <= '9' && k >= '0') s1.push_back(k);
		int size = s1.size();
		for (int i = 0; i < size / 2; i++) {
			if (s1[i] <= 'Z'&& s1[i] >= 'A') s1[i] += ('a' - 'A');
			if (s1[size - 1 - i] <= 'Z'&& s1[size - 1 - i] >= 'A') s1[size - 1 - i] += ('a' - 'A');
			if (s1[i] != s1[size - 1 - i]) return false;
		}*/
		int l = 0, r = n - 1;
		while (l <= r) {
			while (l < n && (!isAlphanumeric(s[l]))) l++;
			while (r >= 0 && (!isAlphanumeric(s[r]))) r--;
			if (l >= n || r < 0 || l > r) break;
			if (s[l] <= 'Z'&& s[l] >= 'A') s[l] += ('a' - 'A');
			if (s[r] <= 'Z'&& s[r] >= 'A') s[r] += ('a' - 'A');
			if (s[l] != s[r]) return false;
			l++; r--;
		}
		return true;
	}
};

int main(void) {
	Solution so;
	printf("%d\n", so.isPalindrome("A man, a plan, a canal: Panama"));
	return 0;
}