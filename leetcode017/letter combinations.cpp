#include<iostream>
using namespace std;
#include<vector>
#include<string>

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		string arr[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (int i = 0; i < digits.length(); i++){
			string str = arr[digits[i] - '2'];
			if (!i){
				for (int j = 0; j < str.length(); j++){
					char a[2];
					sprintf(a, "%c", str[j]);
					ans.push_back(a);
				}
			}
			else{
				vector<string>::iterator begin = ans.begin();
				string temp = *begin;
				while (temp.length() == i){
					for (int j = 0; j < str.length(); j++){
						string s = temp;
						s += str[j];
						ans.push_back(s);
					}
					begin = ans.begin();
					ans.erase(begin);
					begin = ans.begin();
					temp = *begin;
				}
			}
		}
		return ans;
	}
};

int main(){
	Solution so;
	vector<string> ans = so.letterCombinations("23");
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
	return 0;
}