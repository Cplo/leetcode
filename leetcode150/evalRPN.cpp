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
			else if(tokens[i] == "/") {
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
};

int main(void) {
	string s[] = { "4", "13", "5", "/", "+" };
	vector<string> v(s, s + 5);
	Solution so;
	cout << so.evalRPN(v) << endl;
	return 0;
}