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

//ACGT
class Solution {
public:
	long long string_to_int(string s) {
		long long num = 0;
		for (auto x : s) {
			if (x == 'A') num = num * 10;
			else if (x == 'C')  num = num * 10 + 1;
			else if (x == 'G') num = num * 10 + 2;
			else if (x == 'T') num = num * 10 + 3;
		}
		return num;
	}
	string int_to_string(long long num) {
		char ch[12];
		sprintf(ch, "%lld", num);
		int len = strlen(ch);
		string s;
		for (int i = 0; i < 10 - len; i++) {
			s += 'A';
		}
		for (int i = 0; i < len; i++) {
			if (ch[i] == '0') s += 'A';
			else if (ch[i] == '1') s += 'C';
			else if (ch[i] == '2') s += 'G';
			else if (ch[i] == '3') s += 'T';
		}
		return s;
	}
	int char_to_int(char& x) {
		if (x == 'A') return 0;
		else if (x == 'C')  return 1;
		else if (x == 'G') return 2;
		else if (x == 'T') return 3;
	}
 	vector<string> findRepeatedDnaSequences(string s) {
		map<long long, int> m;
		int cur = 0;
		vector<string> ans;
		int n = s.length(); 
		if (n <= 10) return ans;
		string substr = s.substr(0,9);
		long long num = string_to_int(substr);
		for (int i = 9; i < n; i++) {
			substr.push_back(s[i]);
			num = num * 10 + char_to_int(s[i]);
			m[num]++;
			if (m[num] == 2) ans.push_back(substr);
			substr.erase(substr.begin());
			while (num > 1000000000) num -= 1000000000;
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	so.findRepeatedDnaSequences("CCGGCCGGCCGGCCGG");
	return 0;
}