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
	int atoi(string str) {
		int i = 0;
		while (i < str.length() && str[i] == ' ')	{ i++; }
		str = str.substr(i);
		if (str.length() <= 0) return 0;
		char arr[13];
		int flag = 0;
		for (i = 0; i < 12 && i < str.length(); i++)
		{
			if (i == 0 && (str[i] == '-' || str[i] == '+') || str[i] >= '0' && str[i] <= '9')	arr[i] = str[i];
			else break;
		}
		arr[i] = '\0';
		int len = strlen(arr);
		if (!len || len == 1 && (arr[0] == '+' || arr[0] == '-')) return 0;
		long long k;
		sscanf(arr, "%lld", &k);
		if (k > INT_MAX) k = INT_MAX;
		if (k < INT_MIN) k = INT_MIN;
		return k;
	}
	int evalRPN(vector<string>& tokens) {
		int n = tokens.size();
		stack<int> s;
		int left, right;
		for (int i = 0; i < n; i++) {
			if (tokens[i] == "+") {
				right = s.top(); s.pop();
				left = s.top(); s.pop();
				s.push(left + right);
			}
			else if (tokens[i] == "-") {
				right = s.top(); s.pop();
				left = s.top(); s.pop();
				s.push(left - right);
			}
			else if (tokens[i] == "*") {
				right = s.top(); s.pop();
				left = s.top(); s.pop();
				s.push(left * right);
			}
			else if (tokens[i] == "/") {
				right = s.top(); s.pop();
				left = s.top(); s.pop();
				s.push(left / right);
			}
			else {
				int num = atoi(tokens[i]);
				s.push(num);
			}
		}
		return s.top();
	}
	void convert(vector<string>& s_exp, string s) {
		int n = s.length();
		for (int i = 0; i < n;) {
			if (s[i] == '(') {
				int count = 1;
				i++;
				int start = i;
				while (i < n) {
					if (s[i] == '(') count++;
					else if (s[i] == ')') {
						count--;
						if (!count) {
							convert(s_exp, s.substr(start, i - start));
							i++;
							break;
						}
					}
					i++;
				}
			}
			else if(s[i]<='9'&&s[i]>='0') {
				int start = i;
				i++;
				while (i < n&&s[i] <= '9'&&s[i] >= '0') i++;
				s_exp.push_back(s.substr(start, i - start));
			}
			else if (s[i] == '+' || s[i] == '-') {
				i++;
				int start = i;
				if (s[i] == '(') {
					int count = 1;
					i++;
					int idx = i;
					while (i < n) {
						if (s[i] == '(') count++;
						else if (s[i] == ')') {
							count--;
							if (!count) {
								convert(s_exp, s.substr(idx, i - idx));
								i++;
								break;
							}
						}
						i++;
					}
				}
				else {
					int idx = i;
					i++;
					while (i < n&&s[i] <= '9'&&s[i] >= '0') i++;
					s_exp.push_back(s.substr(idx, i - idx));
				}
				string str; str.push_back(s[start - 1]);
				s_exp.push_back(str);
			}
		}
	}
	int calculate(string s) {
		vector<string> s_exp;
		int n = s.length();
		int i = 0, j = 0;
		int arr[500]; memset(arr, 0, 500 * sizeof(int));
		int level = 0;
		for (; i < n; i++) {
			if (s[i] == ' ') continue;
			s[j++] = s[i];
		}
		s = s.substr(0, j);
		n = s.size();
		i = 0; j = 0;
		for (; i < n; i++){
			if (s[i] == '(') { level++; }
			else if (s[i] == ')') { arr[level] = 0; level--; }
			else if (!level || !arr[level - 1]) {
				s[j++] = s[i];
				if (s[i] == '+') {
					arr[level] = 0;
				}
				else if (s[i] == '-') {
					arr[level] = 1;
				}
			}
			else if (arr[level - 1]) {
				if (s[i] == '+') {
					s[j++] = '-'; arr[level] = 1;
				}
				else if (s[i] == '-') {
					s[j++] = '+';
					arr[level] = 0;
				}
				else s[j++] = s[i];
			}
		}
		s = s.substr(0, j);
		convert(s_exp, s);
		return evalRPN(s_exp);
	}
	void convert1(vector<string>& s_exp, string s) {
		int n = s.length();
		for (int i = 0; i < n;) {
			if (s[i] <= '9'&&s[i] >= '0') {
				int start = i;
				i++;
				while (i < n&&s[i] <= '9'&&s[i] >= '0') i++;
				s_exp.push_back(s.substr(start, i - start));
			}
			else if (s[i] == '+' || s[i] == '-') {
				i++;
				int start = i;
				while (i < n&&s[i] != '+'&&s[i] != '-') i++;
				convert1(s_exp, s.substr(start, i - start));
				string str; str.push_back(s[start - 1]);
				s_exp.push_back(str);
			}
			else if (s[i] == '*' || s[i] == '/') {
				i++;
				int start = i;
				if (s[i] <= '9'&&s[i] >= '0') {
					int idx = i;
					i++;
					while (i < n&&s[i] <= '9'&&s[i] >= '0') i++;
					s_exp.push_back(s.substr(idx, i - idx));
				}
				string str; str.push_back(s[start - 1]);
				s_exp.push_back(str);
			}
		}
	}
	int calculate1(string s) {
		vector<string> s_exp;
		int n = s.length();
		int i = 0, j = 0;
		for (; i < n; i++) {
			if (s[i] != ' ') s[j++] = s[i];
		}
		s = s.substr(0, j);
		convert1(s_exp, s);
		return evalRPN(s_exp);
	}
	vector<int> productExceptSelf(vector<int>& nums) {
		int product = 1;
		int n = nums.size(); vector<int> ans(n,1);
		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1) ans[i] = nums[i];
			else ans[i] = nums[i] * ans[i + 1];
		}
		for (int i = 0; i<n; i++) {
			if (i != n - 1) ans[i] = product*ans[i + 1];
			else ans[i] = product;
			product *= nums[i];
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	//cout << so.calculate1("3+2*2"); 
	int arr[] = { 0, 0 };
	vector<int> v(arr,arr+2);
	so.productExceptSelf(v);
	return 0;
}