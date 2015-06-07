#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	bool isInterleave(int cur, string s1, int index2, string &s3) {
//		int s1_len = s1.size();
//		if (index2 == n2) {
//			if (s3.substr(cur) == s1) return true;
//			else return false;
//		}
//		if (s2[index2] == s3[cur] && isInterleave(cur + 1, s1, index2 + 1, s3)) return true;
//		int i = 0;
//		while (i < s1_len && s1[i] == s2[index2]) i++;
//		if (i && s1.substr(0, i) != s3.substr(cur, i))  return false;
//		cur += i;
//		s1 = s1.substr(i);
//		s1_len = s1.length();
//		for (i=0; i <= s1_len; i++) {
//			if (i == s1_len && s1 + s2.substr(index2) == s3.substr(cur)) return true;
//			string s = s1.substr(0, i) + s2[index2];
//			if (s == s3.substr(cur, i + 1)) {
//				if (isInterleave(cur+i+1,s1.substr(i),index2+1,s3)) return true;
//			}
//		}
//		return false;
//	}
//	bool isInterleave(string s1, string s2, string s3) {
//		n1 = s1.size();
//		n2 = s2.size();
//		int n3 = s3.size();
//		if (n3 != n1 + n2) return false;
//		this->s2 = s2;
//		return isInterleave(0, s1, 0, s3);
//	}
//private:
//	int n1;
//	int n2;
//	string s2;
//};
class Solution {
public:
	bool isInterleave(string s1, string s2, int cur, string &s3) {
		int n1 = s1.size();
		int n2 = s2.size();
		if (cur == n3) return true;
		if (!n1 || !n2) {
			string s = s1 + s2;
			return s == s3.substr(cur);
		}
		int c = 1;
		int i = cur+1;
		while (i < n3 && s3[i] == s3[i-1]) { i++; c++; }
		int a = 0, b = 0;
		while (a < n1&&s1[a] == s3[cur]) a++;
		while (b < n2&&s2[b] == s3[cur]) b++;
		if (c > a + b || c < min(a, b)) return false;
		else if (c == a + b) return isInterleave(s1.substr(a), s2.substr(b), cur + c, s3);
		else if (c > max(a, b)) return (isInterleave(s1.substr(a), s2.substr(c - a), cur + c, s3) 
			|| isInterleave(s1.substr(c - b), s2.substr(b), cur + c, s3));
		else if (c < max(a, b))/*取较小部分+剩余部分*/ {
			if (a <= b) return isInterleave(s1.substr(a), s2.substr(c - a), cur + c, s3);
			return isInterleave(s1.substr(c - b), s2.substr(b), cur + c, s3);
		}
		else if (c == max(a, b))/*"取较小部分+剩余部分"或者"较大部分"*/ {
			if (a <= b) return (isInterleave(s1.substr(a), s2.substr(c - a), cur + c, s3) || isInterleave(s1, s2.substr(b), cur + c, s3));
			return (isInterleave(s1.substr(c - b), s2.substr(b), cur + c, s3) || isInterleave(s1.substr(a), s2, cur + c, s3));
		}
	}
	bool isInterleave(string s1, string s2, string s3) {
		int n1 = s1.size();
		int n2 = s2.size();
		n3 = s3.size();
		if (n3 != n1 + n2) return false;
		return isInterleave( s1, s2, 0, s3);
	}
private:
	int n3;
};
int main(void) {
	Solution so;
	cout << so.isInterleave(
		"ccabcaacaacccaabacbcacac",
		"ccbcbacbaaccabbabbca",
		"cccbccbabcacaacabacaaccccaaabbabbabccabcacac") << endl;
	cout << so.isInterleave("bbbb", "bac", "bbacbbb") << endl;
	return 0;
}