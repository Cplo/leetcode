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
	void reverseWords(string &s) {
		int n = s.size();
		for (int i = 0; i < n / 2; i++) {
			swap(s[i], s[n - 1 - i]);
		}
		string str = "";
		for (int i = 0; i < n; i++) {
			while (i < n&&s[i] == ' ') i++;
			int start = i;
			while (i < n&&s[i] != ' ') i++;
			if (i - start <= 0)	 break;
			if (str == "") str = s.substr(start, i - start);
			else str += (" " + s.substr(start, i - start));
		}
		s = str;
		n = s.size();
		for (int i = 0; i < n;) {
			while (i < n&&s[i] == ' ') i++;
			int start = i;
			while (i < n&&s[i] != ' ') i++;
			for (int x = start; x < start + (i - start) / 2; x++) {
				swap(s[x], s[start + i - 1 - x]);
			}
		}
	}
};

int main() {
	Solution so;
	string s = "   a  b  c "; so.reverseWords(s);
	cout << s.size() << endl;
	return 0;
}