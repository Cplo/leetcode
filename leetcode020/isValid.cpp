#include<iostream>
using namespace std;
#include<string>
#include<stack>
class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		char arr[127];
		arr[']'] = '[';
		arr['}'] = '{';
		arr[')'] = '(';
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
				stk.push(s[i]);
				continue;
			}
			if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
				if (stk.empty()) return false;
				else if (stk.top() == arr[s[i]]){
					stk.pop();
				}
				else
					return false;
			}
		}
		if (stk.empty()) return true;
		return false;
	}
};

int main(){
	Solution so;
	cout << so.isValid("()") << endl;
	return 0;
}