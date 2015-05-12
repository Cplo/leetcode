#include<iostream>
using namespace std;
#include<string>
#include<string.h>

class Solution {
public:
	int longestValidParentheses(string s) {
		int left = 0;
		int ans = 0;
		int count = 0;
		int p[100000];
		int stack[100000];
		int length = s.length();
		int i;
		memset(p, 0, sizeof(int)*length);
		memset(stack, -1, sizeof(int)*length);
		for (i = 0; i < length; i++){
			if (s[i] == '(') {
				stack[left] = i;
				left++;
			}
			else if (s[i] == ')') {
				if (left) {
					left--;
					p[stack[left]] = 1;
					p[i] = 1;
				}
			}
		}
		int com = 0;
		for (i = 0; i < length; i++){
			if (p[i]){
				com++;
			}
			else{
				if (com > ans) ans = com;
				com = 0;
			}
		}
		if (com > ans) ans = com;
		return ans;
	}
};

int main(){
	Solution so;
	cout << so.longestValidParentheses("())") << endl;
	return 0;
}