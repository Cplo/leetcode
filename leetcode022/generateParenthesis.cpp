#include<iostream>
using namespace std;
#include<vector>
#include<string>

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		vector<int> left;
		vector<int> right;
		int i = 0; 
		while (1)
		{
			if (!i){
				string s= "(";
				ans.push_back(s);
				left.push_back(1);
				right.push_back(0);
				i++;
				continue;
			}
			int size = ans.size();
			for (int j = 0; j < size; j++){
				if (left[j] < n){
					if (left[j] > right[j]){
						string s = ans[j];
						s += ')';
						left.push_back(left[j]);
						right.push_back(right[j]+1);
						ans.push_back(s);
					}
					ans[j] += '(';
					left[j]++;
				}
				else if(left[j] == n){
					ans[j] += ')';
					right[j]++;
				}
			}
			i++;
			if (i == 2 * n) break;
		}
		return ans;
	}
};
int main(){
	Solution so;
	vector<string> ans = so.generateParenthesis(3);
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
	return 0;
}