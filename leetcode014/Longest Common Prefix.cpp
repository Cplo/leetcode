#include<iostream>
using namespace std;
#include<string>
#include<vector>

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() < 1) return "";
		int ans = strs[0].length();
		string ref = strs[0];
		int i, j;
		for (i = 1; i < strs.size(); i++){
			for (j = 0; j < ans; j++){
				if (ref[j] - strs[i][j]) break;
			}
			ans = j;
		}
		return ref.substr(0, ans);
	}
};
int main(){

	return 0;
}