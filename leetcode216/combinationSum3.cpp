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
	vector<vector<int>> fun(int& n, int& k, int cur, int cur_v, int num){
		vector<vector<int>> ans;
		if (cur == k) {
			if (n - num <= 9 && n - num >= 1 && n-num > cur_v) {
				vector<int> v;
				v.push_back(n - num);
				ans.push_back(v);
			}
			return ans;
		}
		else {
			for (int i = cur_v + 1; i<=9; i++) {
				vector<vector<int>> v_temp = fun(n, k, cur + 1, i, num + i);
				for (auto x : v_temp) {
					vector<int> v;
					v.push_back(i);
					for (auto y : x){
						v.push_back(y);
					}
					ans.push_back(v);
				}
			}
		}
		return ans;
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans = fun(n, k, 1, 0, 0);
		return ans;
	}
		
};

int main(void){
	Solution so;
	so.combinationSum3(3, 9);
	return 0;
}