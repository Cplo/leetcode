#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>
class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int size = matrix.size();
		for (int i = 0; i < size; i++){
			for (int j = 0; j < i; j++){
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size / 2; j++){
				swap(matrix[i][j], matrix[i][size - 1 - j]);
			}
		}
	}
	vector<string> anagrams(vector<string>& strs) {
		vector<string> ans;
		int n = strs.size();
		int p[100000];
		memset(p, 0, n*sizeof(int));
		map<string, vector<int>> m;
		for (int i = 0; i < n;i++){
			string t = strs[i];
			sort(t.begin(), t.end());
			if (m.find(t) == m.end()) {
				vector<int> v;
				v.push_back(i);
				m[t] = v;
			}
			else
			{
				m[t].push_back(i);
			}
		}
		map<string, vector<int>>::iterator it;
		for (it = m.begin(); it != m.end(); it++){
			if (it->second.size() > 1){
				for (auto idx : it->second){
					p[idx] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++){
			if (p[i]){
				ans.push_back(strs[i]);
			}
		}
		return ans;
	}
	double myPow(double x, int n) {
		if (!n) return 1;
		if (x == 1) return 1;
		if (x == -1) {
			if (n % 2) return -1;
			else return 1;
		}
		int flag = 0;
		if (n<0) { n = -n; flag = 1; }
		if (n == 1) return flag ? 1 / x : x;
		double ans = x*x;
		for (int i = 3; i <= n; i++){
			ans *= x;
			if (!ans) break;
		}
		return flag ? 1 / ans : ans;
	}
};

int main(){
	Solution so;
	string s[] = { "c", "c" };
	vector<string> v(s,s+2);
	so.anagrams(v);
	cout << so.myPow(0.00001, -214748364);
	return 0;
}